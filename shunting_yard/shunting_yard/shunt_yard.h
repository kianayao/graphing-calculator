#ifndef SHUNT_YARD_H
#define SHUNT_YARD_H

#include "token.h"
#include "function.h"
#include "numbers.h"
#include "lparen.h"
#include "rparen.h"

class Shunt_Yard
{
public:
    Shunt_Yard();                       // default ctor
    Shunt_Yard(Queue<Token*> infix);    // ctor
    Queue<Token*> postfix(const Queue<Token*> &infix);
    // returns the postfix expression given an infix
    Queue<Token*> get_postfix();
    // returns _postfix
    friend ostream& operator <<(ostream& outs, Shunt_Yard sy);
private:
    Queue<Token*> _postfix;
};

#endif // SHUNT_YARD_H
