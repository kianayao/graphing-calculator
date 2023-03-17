#include <iostream>
#include <cstdlib>
#include "my_simple_list.h"
#include "my_simple_list_functions.h"
#include "test_simple_list.h"

using namespace std;

void test() {
    srand(rand());
    char command;
    list<int> test1(rand() % 100);
    node<int> *cursor;

    for (int i = 1; i < 5; i++) {
        cursor = test1.InsertHead(rand() % 100);
    }

    cout << test1 << endl;

    do{
        cout << "[R]andom [A]fter  [B]efore [D]elete [S]earch " <<
                "[P] Previous  [N] Next  [H]ome  [E]nd  e[x]it" << ":" << endl;
            cin >> command;

            menu(toupper(command), test1, cursor);

            cout << endl << test1 << endl;
            cout << "cursor: " << cursor ->_item << endl;
    }while (toupper(command) != 'X');
}
