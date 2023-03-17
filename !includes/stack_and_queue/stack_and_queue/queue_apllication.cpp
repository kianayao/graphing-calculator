#include "queue_apllication.h"
#include <time.h>

void menu(char command, Queue<int>& l,
          typename Simple_List<int>::Iterator &head) {
    int key;
    switch(command) {
    case 'R':
        l.push_end(rand() % 100);
     break;

    case 'U':
        cout << "key: ";
        cin >> key;
        cout << endl;
        l.push_end(key);
     break;

    case 'O':
        l.pop_head();
        head = l.top();
     break;

    default:
        break;

    }
}

void test_queue() {
    srand(time(0));
    char command;
    Queue<int> test;
    Simple_List<int>::Iterator head;

    head = test.push_end(rand() % 100);
    for (int i = 1; i < 5; i++) {
        test.push_end(rand() % 100);
    }

    //cout << test << endl;
    cout << "head: " << *head << endl;

    do{
        cout << "[R]andom P[U]sh  P[O]p  e[x]it" << ":" << endl;
            cin >> command;

            menu(toupper(command), test, head);

            cout << endl << test << endl;
            cout << "cursor: " << *head << endl;
    }while (toupper(command) != 'X');
}

void test2_queue() {
    srand(time(0));
    char command;
    Queue<string> test;
    Simple_List<string>::Iterator head;

    head = test.push_end("hi");
    cout << test << endl;
    cout << "head: " << *head << endl;

    head = test.push_end("no");
    cout << test << endl;
    cout << "head: " << *head << endl;

    head = test.push_end("tired");
    cout << test << endl;
    cout << "head: " << *head << endl;


//    do{
//        cout << "[R]andom P[U]sh  P[O]p  e[x]it" << ":" << endl;
//            cin >> command;

//            //menu(toupper(command), test, head);

//            cout << endl << test << endl;
//            cout << "cursor: " << *head << endl;
//    }while (toupper(command) != 'X');
}
