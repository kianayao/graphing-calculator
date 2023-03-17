#ifndef NUMBERS_H
#define NUMBERS_H

#include "token.h"

class Numbers : public Token {
public:
    Numbers();              // default ctor
    Numbers(string num);    // ctor
    int type_of();          // returns NUM_TYPE
    void print();           // prints _num or x
    double get_num();       // returns _num
    bool is_x();            // true if object is x
private:
    double _num;
    bool _is_x;

};

#endif // NUMBERS_H
