#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <iostream>
using namespace std;


template <typename T>
T* add_entry(T *array, T value, int& size, int& capacity);
// precondition(s): an array must exist
// postcondition(s): the value will be added into the array

template <typename T>
T* remove_entry(T *array, T value, int& size, int& capacity);
// precondition(s): an array must exist
//                  the type of the array must match the value type
// postcondition(s):

template <typename T>
T* reallocate(int capacity, T *initial_array, int size);
// precondition(s): an array must exist
// postcondition(s): a new array with a new capacity will be created

template <typename T>
void shift_left(T *array, T* move, int& size);
//precondition: there are values within the array
//postcondition: the array values will be shifted to the left starting
//               from the move pointer, thus removing a value

template <typename T>
void shift_right(T *array, int index, int& size);

/*----------------------------------------DEFINITIONS--------------------------------------*/


template <typename T>
T* add_entry(T *array, T value, int& size, int& capacity) {
    if (size == capacity) {             // checks if the array is full
        capacity *= 2;                  // updates the capacity
        array = reallocate(capacity, array, size);
        // if the array is full, a new array with 2*capacity is created
    }
    T *add_to = array + size;       // points add_to to the first empty slot in the array
    *add_to = value;                // assigns value to the empty slot in the array
    size++;
    return (array);
}

template <typename T>
T* reallocate(int capacity, T *initial_array, int size) {
//    const bool debug = true;
//    if (debug){
//        cout<<"---------- reallocate: "<<capacity<<" ---------------------------"<<endl;
//    }
    T *new_array = new T [capacity];            // creates new array with new capacity
    copy_list(initial_array, new_array, size);  // copies the initial array into the new array
    delete [] initial_array;                    // deallocates the initial array
    return (new_array);
}

template <typename T>
T* remove_entry(T *array, T value, int& size, int& capacity) {
    T *entry = search_entry(array, value, size);
    // checks if the value given is present in the array
    if (entry != nullptr)
        // if an address is returned, items in the array after the address are shifted left to remove the value
        shift_left(array, entry, size);
    if (size  < (capacity / 4)) {
        // if the size of the array falls below a quarter of its capacity,
        // a new array is allocated with half the original capacity
        capacity /= 2;      // updates the capacity
        array = reallocate(capacity, array, size);
    }
    return (array);
}

template <typename T>
void shift_left(T *array, T* move, int& size) {
    T *current, *shift = move +1;

    for(current = move; shift < (array + size); current++, shift++) {
        // current is set to the address of the current pointer from the remove_entry function
        // shift is set to the address right after
        *current = *shift;
    }
    size--;         // decrements the size of the array since a value was just removed
}

template <typename T>
void shift_right(T *array, int index, int& size) {
    T *current, *shift = array + size - 1;

    for(current = array + size; shift >= (array + index); current--, shift--) {
        // current is set to the address of the current pointer from the remove_entry function
        // shift is set to the address right after
        *current = *shift;
    }
    size++;         // decrements the size of the array since a value was just removed
}



#endif // ADD_ENTRY_H
