#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "../../!includes/stack_and_queue/stack_and_queue/queue.h"
#include "../../!includes/stack_and_queue/stack_and_queue/stack.h"

using namespace std;

const int TOKEN_TYPE = 1, OP_TYPE = 2, NUM_TYPE = 3, LPAREN_TYPE = 4,
          RPAREN_TYPE = 5;
const int LOWER_PREC = 1, HIGHER_PREC = 2, HIGHEST_PREC = 3, FUNCTIONS = 4;

class Token {
public:
    Token();                    // default ctor
    virtual int type_of();      // returns TOKEN_TYPE
    virtual void print();       // this is a token
    friend ostream& operator <<(ostream& outs, Token t);    // calls print
    friend ostream& operator <<(ostream& outs, Token* t);
    // calls print for the children classes of Token
};

#endif // TOKEN_H
