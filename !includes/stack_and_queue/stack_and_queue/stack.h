#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "../../../!includes/my_list/my_list.h"

using namespace std;

template <typename T>
class Stack {

public:
    Stack();
    node<T>* push_head(T i);
    T pop_head();
    bool empty();
    node<T>* top();

    template <typename U>
    friend ostream& operator <<(ostream& outs, const Stack<U> l);

private:
    node<T>* _stack;
};

template <typename T>
Stack<T>::Stack():_stack(nullptr) {
    // INTENTIONALLY LEFT BLANK
}

template <typename T>
node<T>* Stack<T>::push_head(T i) {
    return insert_head(_stack, i);
}

template <typename T>
T Stack<T>::pop_head() {
    assert(! empty());
    return delete_head(_stack);
}

template <typename T>
bool Stack<T>::empty() {
    return empty_list(_stack);
}

template <typename T>
node<T>* Stack<T>::top() {
    return _stack;
}

template <typename U>
ostream& operator <<(ostream& outs, const Stack<U> l) {
    return print_plain_list(l._stack, outs);
}

#endif // STACK_H
