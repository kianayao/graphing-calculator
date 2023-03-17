#ifndef RPAREN_H
#define RPAREN_H

#include "token.h"

class Rparen : public Token {
public:
    Rparen();           // default ctor
    int type_of();      // returns RPAREN_TYPE
    void print();       // prints ")"
private:
    string _right_parent;
    int _prec;
};

#endif // RPAREN_H
