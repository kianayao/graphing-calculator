#include <iostream>
#include <string.h>
#include <sstream>
#include "shunt_yard.h"

using namespace std;

Queue<Token*> test_tokenizer(string s);

int main()
{

    string temp;

    cout << "infix string" << endl;
    getline(cin, temp);


    Shunt_Yard test3(test_tokenizer(temp));

    //cout << "infix: " << test2 << endl;
    cout << "postfix: " << test3 << endl;



    return 0;
}

Queue<Token*> test_tokenizer(string s) {
    Queue<Token*> infix;
    stringstream temp;
    string token;
    temp << s;

    while (temp >> token) {
        cout << "tokens " << token << endl;
        if (isdigit(token[0]) || token == "x" || token == "X")
            infix.push_end(new Numbers(token));
        else if (token == "+" || token == "-" || token == "/" ||
                 token == "*")
            infix.push_end(new Function(token, 2));
        else if (token == "(")
            infix.push_end(new Lparen());
        else if (token == ")")
            infix.push_end(new Rparen());
        else // trig functions
            infix.push_end(new Function(token, 1));
    }

    Queue<Token*> temp_infix = infix;

    return infix;
}
