#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <iostream>
#include "test_list.cpp"
#include "my_list.h"
#include "../!includes/node/node.h"

using namespace std;

node<int>* test_inserthead(node<int> *&head_ptr, const int &item);

node<int>* test_insert_before(node<int>*& head, node<int>* beforeThis,
                        int insertThis);

node<int>* test_insert_after(node<int>*& head, node<int>* afterThis,
                       int insertThis);

node<int>* test_search_list(node<int>* head, int key);

node<int>* test_previous_node(node<int>* head, node<int>* cursor);

node<int>* test_next_node(node<int>* head, node<int>* cursor);

#endif // TEST_LIST_H
