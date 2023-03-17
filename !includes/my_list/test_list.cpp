#include <iostream>
#include "test_list.h"
#include "../!includes/node/node.h"
#include "../!includes/my_list/my_list.h"

using namespace std;

node<int> * test_inserthead(node<int> *&head_ptr, const int &item) {
    return insert_head(head_ptr, item);
    print_list(head_ptr, cout);

//    cout<<"--------- TEST_INSERT_HEAD ------------"<<endl;
//        List<int> l;
//        for (int i=0; i<10; i++){
//            l._insert_head(i*10);
//        }
//        cout<<"/n/ninserted 0..10 into list head: 90-80..20-10-0"<<endl;
//        cout<<l<<endl;
//        cout<<"--------- END_TEST_INSERT_HEAD ------------"<<endl;
//
}

node<int>* test_insert_before(node<int>*& head, node<int>* beforeThis,
                        int insertThis) {
    return insert_before(head, beforeThis, insertThis);
}

node<int>* test_insert_after(node<int>*& head, node<int>* afterThis,
                       int insertThis) {
    return insert_after(head, afterThis, insertThis);
}

node<int>* test_search_list(node<int>* head, int key) {
    return search_list(head, key);
}

node<int>* test_previous_node(node<int>* head, node<int>* cursor) {
    return previous_node(head, cursor);
}

node<int>* test_next_node(node<int>* head, node<int>* cursor) {
    return next_node(head, cursor);
}
