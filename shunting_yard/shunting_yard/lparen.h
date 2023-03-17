#ifndef LPAREN_H
#define LPAREN_H

#include "token.h"

class Lparen : public Token {
public:
    Lparen();       // ctor
    int type_of();  // returns LPAREN_TYPE
    void print();   // prints (
private:
    string _left_parent;    // "("
    int _prec;              // precedent
};

#endif // LPAREN_H
