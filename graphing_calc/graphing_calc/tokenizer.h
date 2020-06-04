#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include "../../CS3A/shunting_yard/shunting_yard/shunt_yard.h"

using namespace std;

class Tokenizer
{
public:
    Tokenizer();
    Tokenizer(char* s);
    Tokenizer(string s);
    Queue<Token*> tokenize(string s);
    Queue<Token*> tokenize(char* c);
    Queue<Token*> get_infix();

private:
    Queue<Token*> _infix;
};

#endif // TOKENIZER_H
