#ifndef MY_SIMPLE_LIST_H
#define MY_SIMPLE_LIST_H

#include <iostream>
#include "../../../!includes/my_list/my_list.h"
#include "../../../!includes/node/node.h"

using namespace std;

template <typename T>
class list {
public:
    list();
    list(T item);
    ~list();
    list(const list<T> &copyThis);
    list& operator =(const list& RHS);

    node<T>* InsertHead(T i);           //inset i at the head of list

    node<T>* InsertAfter(T i, node<T>* iMarker);       //insert i after iMarker


    node<T>* InsertBefore(T i, node<T>* iMarker); //insert i before iMarker

    node<T>* InsertSorted(T i);         //insert i. Assume sorted list

    T Delete(node<T>* iMarker);         //delete node pointed to by iMarker


    void Print() const;                 //print the list

    node<T>* Search(const T &key);      //return pointer to node containing
                                        //  key. NULL if not there

    node<T>* Prev(node<T>* iMarker);    //get the previous node to iMarker

    node<T>* Next(node<T>* iMarker);    //get the next node to iMarker

    T& operator[](int index);               //return the item at index

    node<T>* Begin() const;                 //return the head of the list

    node<T>* End() const;                   //return the tail of the list
                                            //  if you ever have to use this
                                            //  function, you need to redesign
                                            //  your program.
    template <typename U>
    friend ostream& operator <<(ostream& outs,    //insertion operator for list
                                const list<U>& l);
private:
    node<T>* _head;

};

template <typename T>
list<T>::list() {
    _head = nullptr;
}

template <typename T>
list<T>::list(T item) {
    _head = new node<T>(item);
}

template <typename T>
list<T>::~list() {
    clear_list(_head);
}

template <typename T>
list<T>::list(const list<T> &copyThis) {
    _head = copy_list(copyThis._head);
}

template <typename T>
list<T>& list<T>::operator =(const list<T>& RHS) {
    if (this == &RHS)
        return *this;

    clear_list(_head);
    _head = copy_list(RHS._head);
    return _head;
}

template <typename T>
node<T>* list<T>::InsertHead(T i) {           //inset i at the head of list
    return insert_head(_head, i);
}

template <typename T>
node<T>* list<T>::InsertAfter(T i, node<T>* iMarker) {      //insert i after iMarker
    return insert_after(_head, iMarker, i);
}

template <typename T>
node<T>* list<T>::InsertBefore(T i, node<T>* iMarker) { //insert i before iMarker
    return insert_before(_head, iMarker, i);
}

template <typename T>
node<T>* list<T>::InsertSorted(T i) {         //insert i. Assume sorted list
    return insert_sorted(_head, i);
}
template <typename T>
T list<T>::Delete(node<T>* iMarker) {         //delete node pointed to by iMarker
    return delete_node(_head, iMarker);
}

template <typename T>
void list<T>::Print() const {                 //print the list
    print_list(_head);
}

template <typename T>
node<T>* list<T>::Search(const T &key) {
    //return pointer to node containing
    return search_list(_head, key);             //  key. nullptr if not there
}

template <typename T>
node<T>* list<T>::Prev(node<T>* iMarker) {
    //get the previous node to iMarker
    return previous_node(_head, iMarker);
}

template <typename T>
node<T>* list<T>::Next(node<T>* iMarker) {
        //get the next node to iMarker
    return next_node(_head, iMarker);
}

template <typename T>
T& list<T>::operator[](int index) {            //return the item at index
    return at(_head, index);
}
template <typename T>
node<T>* list<T>::Begin() const {              //return the head of the list
    return _head;
}

template <typename T>
node<T>* list<T>::End() const {               //return the tail of the list
    return last_node(_head);
}

template <typename U>
ostream& operator <<(ostream& outs,
                     const list<U>& l) {
    return print_list(l._head);
}

#endif // MY_SIMPLE_LIST_H
