#include "my_simple_list_functions.h"

void menu(char command, list<int>& l, node<int> *&cursor) {
    char key;
    switch(command) {
    case 'R':
        cursor = l.InsertAfter(rand() % 100, cursor);
     break;

    case 'A':
        cout << "key: ";
        cin >> key;
        cout << endl;
        cursor = l.InsertAfter(key, cursor);
     break;

    case 'B':
        cout << "key: ";
        cin >> key;
        cout << endl;
        cursor = l.InsertBefore(key, cursor);
     break;

    case 'D':
        l.Delete(cursor);
        cursor = l.Begin();
     break;

    case 'S':
        cout << "key: ";
        cin >> key;
        cout << endl;
        cursor = l.Search(key);
     break;

    case 'P':
        cursor = l.Prev(cursor);
     break;

    case 'N':
        if (cursor == nullptr) {

        }
        else
            cursor = l.Next(cursor);
     break;

    case 'H':
        cursor = l.Begin();
     break;

    case 'E':
        cursor = l.End();
     break;

    }
}
