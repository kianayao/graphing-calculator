#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "../../../!includes/iterated_list/iterated_list/iterated_list.h"

using namespace std;

template <typename T>
class Queue {

public:
    Queue();
    typename Simple_List<T>::Iterator push_end(T i);
    T pop_head();
    bool empty();
    typename Simple_List<T>::Iterator top();

    void print();

    template <typename U>
    friend ostream& operator <<(ostream& outs, const Queue<U> l);

private:
    Simple_List<T> _queue;

};

template <typename T>
Queue<T>::Queue() {
    // INTENTIONALLY LEFT BLANK
}

template <typename T>
typename Simple_List<T>::Iterator Queue<T>::push_end(T i) {
    return _queue.InsertEnd(i);
}

template <typename T>
T Queue<T>::pop_head() {
    assert(! empty());
    return _queue.RemoveHead();
}

template <typename T>
bool Queue<T>::empty() {
    return _queue.Empty();
}

template <typename T>
typename Simple_List<T>::Iterator Queue<T>::top() {
    return _queue.Begin();
}

template <typename T>
void Queue<T>::print() {
    cout << _queue;
}

template <typename U>
ostream& operator <<(ostream& outs, const Queue<U> l) {
    outs << l._queue;
    return outs;
}

#endif // QUEUE_H
