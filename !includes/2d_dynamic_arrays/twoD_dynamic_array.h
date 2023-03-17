#ifndef TWOD_DYNAMIC_ARRAY_H
#define TWOD_DYNAMIC_ARRAY_H

#include <iostream>
#include <assert.h>
#include "../1d_arrays/oneD_arrays.h"

using namespace std;


template <typename T>
void initialize_twoD(T** twoD_array, int *sizes_array, T initial_value);
// precondition(s): a two-D array exists consisting of dynamic arrays
//                  an array with the number of colmns in each row exists
// postcondition(s): each element in the two-D array will be initialized
//                   to the value given

template <typename T>
void init_debug(T** twoD_array, int *sizes_array, T initial_value);
// precondition(s): a two-D array exists consisting of dynamic arrays
//                  an array with the number of colmns in each row exists
// postcondition(s): each element in the two-D array will be initialized
//                   to a unique value

int find_rows(int *sizes_array);
// precondition(s): determines the number of rows based on the number of
//                  elements in the array passed
// postcondition(s): returns the number of rows

template <typename T>
T** allocate_twoD(int *sizes_array);
// precondition(s): an int array exists
// postcondition(s): a two dimensional array will have been created

template <typename T>
void allocate_oneD(int size, T **twoD_array, int *sizes_array);
// precondition(s): an array of pointers exists
// postcondition(s):a one dimensional array will have been created

template <typename T>
bool is_valid(int *sizes_array, int row, int column);
// precondition(s): checks to see if a row and column entry is valid
// postcondition(s): returns true if the input is valid, otherwise false

template <typename T>
T read(T** twoD_array, int row, int column, int *sizes_array);
// precondition(s): a valid row and column must be used
//                  a two dimensional array must exist
// postcondition(s): prints the value of the space specified to the console

template <typename T>
void write(T** twoD_array, int row, int column, T value, int *sizes_array);
// precondition(s): the row and column must be valid
//                  a two dimensional array must exist
// postcondition(s): a value will be assigned to the space specified

template <typename T>
void deallocate(T** twoD_array);
// precondition(s): a dynamic two-D array must exist
// postcondition(s): releases the dynamic arrays and returns the freestore
//                   memory

template <typename T>
void print(T** twoD_array, int* sizes_array);
// precondition(s): an array must exist
// postcondition(s): all the elements of the array will be printed

template <typename T>
T* get(T** twoD_array, int row, int column, int *sizes_array);

template <typename T>
T* twoD_search(T** twoD_array, int* sizes_array, T value);
//precondition: there are values within the array the
//              current pointer is within the bounds of the array
//postcondition: returns address of element if value is found,
//               otherwise returns nullptr

//****************************FUNCTION DEFINNITIONS**************************//

template <typename T>
void initialize_twoD(T** twoD_array, int* sizes_array, T initial_value) {
    for (T** init = twoD_array; *init != nullptr; init++) {
     // increments vertically
        initialize_oneD(*sizes_array, *init, initial_value);
        sizes_array++;  // determines how many columns in the row
    }
}

template <typename T>
void init_debug(T** twoD_array, int* sizes_array, T initial_value) {
    for (T** init = twoD_array; *init != nullptr; init++) {
    // increments vertically
        for (T* s_pointer = *init; s_pointer < (*init + *sizes_array);
             s_pointer++) {   // increments horizontally
            *s_pointer = initial_value;  // sets each element to intital_value
            initial_value += 5;   // increments initial_value by 5 horizontally
        }
        initial_value += 10;       // increments initial_value by 10 vertically
        sizes_array++;             // determines how many columns in the row
    }
}

int find_rows(int *sizes_array) {
    int size_of_size = 0;
    for (int *rows = sizes_array; *rows != -1; rows++)
    // increments till -1 to count the number of rows that will be in the array
        size_of_size++;
    return size_of_size;
}

template <typename T>
T** allocate_twoD(int *sizes_array) {
    int size_of_size = find_rows(sizes_array);
    // determines the size of the dynamic array
    T **double_pointer = new T*[size_of_size + 1];
    // creates a dynamic array of pointers
    allocate_oneD(size_of_size, double_pointer, sizes_array);
    // creates the second dimension of the array
    return double_pointer;
}

template <typename T>
void allocate_oneD(int size, T **twoD_array, int *sizes_array) {
    T **create;
    int *rows = sizes_array;
    for (create = twoD_array; create < twoD_array + size; create++) {
        // creates an array for each pointer in twoD_array
        *create = new T[*rows];
        rows++;
    }
    *create = nullptr;  // sets the last element of the array to a null pointer
}

template <typename T>
bool is_valid(int* size_array, int row, int column) {
    int number_of_rows = find_rows(size_array);
    if (row <= number_of_rows - 1) {        // checks if the row given is valid
        T *row_walker = size_array + row;
        if (column <= *row_walker - 1)
        // checks if the size column given is valid
            return true;
    }
    return false;        // returns false if the row or column is out of bounds
}

template <typename T>
T read(T** twoD_array, int row, int column, int *sizes_array) {
    T *column_walker = get(twoD_array, row, column, sizes_array);
    if (column_walker != nullptr)
        return (*column_walker);
}

template <typename T>
void write(T** twoD_array, int row, int column, T value, int *sizes_array) {
    T *column_walker = get(twoD_array, row, column, sizes_array);
    if (column_walker != nullptr)
        *column_walker = value;
        // assigns the value given to the desired position

}

template <typename T>
void deallocate(T** twoD_array) {
    for (T **deallocate_ptr = twoD_array; *deallocate_ptr != nullptr;
         deallocate_ptr++) {
        delete[] *deallocate_ptr;            // deallocates each single pointer
    }
    delete[] twoD_array;                     // deallocates the double pointer
}

template <typename T>
void print(T** twoD_array, int* sizes_array) {
    for (T** row = twoD_array; *row != nullptr; row++) {
    // increments vertically
        for (T* column = *row; column < (*row + *sizes_array); column++)
        // increments horizontally
            cout << *column << " ";
        sizes_array++;           // determines the number of columns in the row
        cout << endl;
    }
}

template <typename T>
T* twoD_search(T** twoD_array, int* sizes_array, T value) {
    T* address;
    for (T** walk = twoD_array; *walk != nullptr; walk++) {
    // increments vertically
        address = search_entry(*walk, value, *sizes_array);

        if (address != nullptr)
            return address;
        sizes_array++;             // determines how many columns in the row
    }
    return nullptr;
}

template <typename T>
T* get(T** twoD_array, int row, int column, int *sizes_array) {
    if (is_valid<int>(sizes_array, row, column)) {
    // checks if the row or column given is valid
    T **row_walker = twoD_array + row;            // points to the row given
    T *column_walker = *row_walker + column;      // points to the column given
    return (column_walker);
    }
    return (nullptr);
}

#endif // TWOD_DYNAMIC_ARRAY_H
