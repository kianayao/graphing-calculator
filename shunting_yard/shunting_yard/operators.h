#ifndef OPERATORS_H
#define OPERATORS_H

#include "token.h"

class Operator : public Token {
public:
    Operator();             // default ctor
    Operator(string op);    // ctor
    int type_of();          // returns OP_TYPE
    void print();           // prints _op
    int precedence(string op);
    // assigns numerical values to set the
    //      precedence for operators and functions
    int get_prec();         // returns _prec
    string get_op();        // returns _op
private:
    string _op;
    int _prec;
};

#endif // OPERATORS_H
