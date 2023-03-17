#ifndef ONED_ARRAYS_H
#define ONED_ARRAYS_H

#include <iostream>
using namespace std;

template <typename T>
void initialize_oneD(const int capacity);

template <typename T>
T* allocate(int capacity);
// precondition(s): a capacity must be given
// postcondition(s): a new array with the given capcity will be created

template <typename T>
void copy_list(T *initial_array, T *final_array, int size);
// precondition(s): two arrays exist
//                  the final array has a capacity greater than or equal to size
// postcondition(s): the final array will be a copy of the initial array

template <typename T>
T* search_entry(T *array, T value, int size);
//precondition: there are values within the array the
//              current pointer is within the bounds of the array
//postcondition: returns address of element if value is found,
//               otherwise returns nullptr

template <typename T>
T read(unsigned int index, T *array);

template <typename T>
void write(unsigned int index, T *array, T value);

template <typename T>
T* get(unsigned int index, T *array);

template <typename T>
void print(T *array, int size);
// precondition(s): an array exists
// postcondition(s): the contents of the array will be printed to the console


/*-------------------------------DEFINITIONS---------------------------------*/

template <typename T>
void initialize_oneD(int size, T *array, T value) {
    for(T *i = array; i < (array + size); i++) {
        *i = value;
    }
}

template <typename T>
T* allocate(int capacity) {
    T *array = new T [capacity];
    return (array);
}

template <typename T>
void copy_list(T *initial_array, T *final_array, int size) {
    for (int i = 0; i < size; i++, final_array++, initial_array++)
        // copies elements from initial_array to final_array
        *final_array = *initial_array;
}

template <typename T>
T* search_entry(T *array, T value, int size) {
    for(T *search = array; search < (array + size); search++) {
        // searches for value given
        if (*search == value)
            return(search);  // returns the address where the element was found
    }
    return(nullptr);         // returns a null pointer if value is not found
}

template <typename T>
T read(unsigned int index, T *array) {
    T *temp = get(index, array);
    return (*temp);
}

template <typename T>
void write(unsigned int index, T *array, T value) {
    T *temp = get(index, array);
    *temp = value;
}
template <typename T>
T* get(unsigned int index, T *array) {
    return (array + index);
}

template <typename T>
void print(T *array, int size) {
    T *p1;
    for(p1=array; p1 < (array + size); p1++)
        cout << *p1 << " ";
    cout << endl;
}

#endif // ONED_ARRAYS_H
