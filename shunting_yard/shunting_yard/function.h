#ifndef FUNCTION_H
#define FUNCTION_H

#include "operators.h"

class Function : public Operator {
public:
    Function();                         // default ctor
    Function(string func, int arg);     // ctor
    int get_args();                     // returns the number of arguments
private:
    int _arguments;
    // how many Numbers are needed to perform the operation
};

#endif // FUNCTION_H
