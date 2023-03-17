#ifndef MY_VECTOR_H
#define MY_VECTOR_H


#include <iostream>
#include <assert.h>
#include "../../!includes/1d_arrays/oneD_arrays.h"
#include "../../!includes/add_entry/add_entry.h"
using namespace std;

template <typename T>
class Vector{
public:

    Vector(unsigned int capacity = 3);

    // big three:
    Vector(const Vector& other);
    ~Vector();
    Vector& operator =(const Vector& other);


    //member access functions:
    T operator [](unsigned int index) const;
    T& operator [](unsigned int index);
    T& at(int index);             //return reference to item at position index
    const T at(int index) const;  //return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_index);        //erase item at position
    int index_of(const T& item);        //search for item. retur index.

    //size and capacity:
    void set_size(int size);            //enlarge the vector to this size
    void set_capacity(int capacity);    //allocate this space
    int get_size() const;   //return _size
    int get_capacity() const;    //return _capacity

    bool empty() const;                 //return true if vector is empty


    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& v);
private:
    T *_v;
    int _size;
    int _capacity;
};

template <typename T>
Vector<T>::Vector(unsigned int capacity): _size(0) {
    _v = allocate<T>(capacity);
    set_capacity(capacity);
    initialize_oneD(_capacity, _v, T());
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    //cout << "TEST: construct using another vector" << endl;
    set_capacity(other.get_capacity());
   // cout << "size b4 " << other._size << endl;
    _size = other.get_size();
    //cout << "size" << _size << endl;
    _v = allocate<T>(other.get_capacity());
    copy_list(other._v, _v, other.get_capacity());
}
template <typename T>
Vector<T>::~Vector() {
    //cout << "TEST: destructor" << endl;
    delete[] _v;
}
template <typename T>
Vector<T>& Vector<T>::operator =(const Vector& other) {
    //cout << "TEST: assignment operator" << endl;
    set_size(other.get_size());
    set_capacity(other.get_capacity());
    delete[] _v;
    _v = allocate<T>(other.get_capacity());
    copy_list(other._v, _v, other.get_capacity());
    //cout << "size = " << _size << endl;
    return *this;
}

template <typename T>
T Vector<T>::operator [](unsigned int index) const {
    assert(index < _capacity);
    return (read(index, this));
}

template <typename T>
T& Vector<T>::operator [](unsigned int index) {
    assert(index < _capacity);
    T *temp = get(index, _v);
    return (*temp);
}

template <typename T>
T& Vector<T>::at(int index) {      //return reference to item at position index
    assert(index < _capacity);
    return (read(index, this));
}
template <typename T>
const T Vector<T>::at(int index) const {//return a const item at position index
    assert(index < _capacity);
    T *temp = get(index, this);
    return (*temp);
}

template <typename T>
T& Vector<T>::front() const {             //return item at position 0.
    return (*_v);
}

template <typename T>
T& Vector<T>::back() const {              //return item at the last position
    return *(_v + _size - 1);
}
template <typename T>
Vector<T>& Vector<T>::operator +=(const T& item) { //push_back
    T* temp = _v + _size;
    *temp = item;
    set_size(++_size);
    return *this;
}
template <typename T>
void Vector<T>::push_back(const T& item) {      //append to the end
    T* temp = _v + _size;
    *temp = item;
    set_size(++_size);
}
template <typename T>
T Vector<T>::pop_back() {
    T * temporary = _v + _size - 1;
    T temp = *temporary;
    *temporary = 0;
    set_size(--_size);
    return temp;
}

template <typename T>
void Vector<T>::insert(int insert_here, const T& insert_this) { //insert at pos
    assert(insert_here < _capacity);
    int temp_size = get_size();
    shift_right(_v, insert_here, temp_size);
    //this[insert_here] = insert_this;
    write(insert_here, _v, insert_this);
    set_size(temp_size);
}
template <typename T>
void Vector<T>::erase(int erase_index) {       //erase item at position
    int temp_size = get_size();
    shift_right(_v, erase_index, temp_size);
    set_size(temp_size);
}
template <typename T>
int Vector<T>::index_of(const T& item) {       //search for item. return index
    return(search_entry(_v, item, get_size()));
}
template <typename T>
void Vector<T>::set_size(int size) {          //enlarge the vector to this size
    if (_size >= (_capacity / 2)) {
        _v = reallocate(_capacity * 2, _v, _size);
        set_capacity(_capacity * 2);
    }
    else if (_size <= (_capacity / 4)) {
        _v = reallocate(_capacity / 2, _v, _size);
        set_capacity(_capacity / 2);
    }
    _size = size;
}
template <typename T>
void Vector<T>::set_capacity(int capacity) {   //allocate this space
    _capacity = capacity;
}
template <typename T>
int Vector<T>::get_size() const {
    return _size;
}

template <typename T>
int Vector<T>::get_capacity() const {
    return _capacity;
}

template <typename T>
bool Vector<T>::empty() const {                 //return true if vector is empty
    if (get_size() == 0)
        return true;
    return false;
}

template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& v) {
    outs<< endl << "SIZE: " << v._size << endl
         << "CAPACITY: " << v._capacity << endl;
    outs << "Items: ";
    print(v._v, v._size);
    return outs;
}

#endif // MY_VECTOR_H
