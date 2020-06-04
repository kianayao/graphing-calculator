#ifndef RPN_H
#define RPN_H

#include "../../CS3A/shunting_yard/shunting_yard/shunt_yard.h"
class rpn {
public:
    rpn();
    rpn(Queue<Token*> postfix, double x);
    double get_y(Queue<Token*> postfix, double x);
private:
    Stack<Token*> _evaluate;
};

#endif // RPN_H
