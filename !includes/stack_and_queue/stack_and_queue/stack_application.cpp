#include "stack_application.h"
#include <time.h>

void menu(char command, Stack<int>& l,
          node<int>* &head) {
    int key;
    switch(command) {
    case 'R':
        head = l.push_head(rand() % 100);
     break;

    case 'U':
        cout << "key: ";
        cin >> key;
        cout << endl;
        head = l.push_head(key);
     break;

    case 'O':
        l.pop_head();
        head = l.top();
     break;

    default:
        break;

    }
}

void test_stack() {
    srand(time(0));
    char command;
    Stack<int> test;
    node<int>* head;

    for (int i = 1; i < 5; i++) {
        head = test.push_head(rand() % 100);
    }

    cout << test << endl;
    cout << "head: " << *head << endl;

    do{
        cout << "[R]andom P[U]sh  P[O]p  e[x]it" << ":" << endl;
            cin >> command;

            menu(toupper(command), test, head);

            cout << endl << test << endl;
            cout << "cursor: " << *head << endl;
    }while (toupper(command) != 'X');
}

