#include <iostream>
#include <ctime>
#include "my_simple_list.h"
#include "my_simple_list_functions.h"
#include "test_simple_list.h"

using namespace std;

int main()
{
    srand(time(NULL));
    list<int> l;

    for (int i = 0; i < 10; i ++)
        //l.InsertBefore(rand() % 100 + 1, l.Begin()); Doesn't work!
        l.InsertBefore(rand() % 100 + 1, new node<int>);




    cout << l[6];

    l.Print();
    return 0;
}
