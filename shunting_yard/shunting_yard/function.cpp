#include "function.h"

Function::Function(): Operator(), _arguments(0) {
    // INTENTIONALLY LEFT BLANK
}

Function::Function(string func, int arg): Operator(func), _arguments(arg) {
    // INTENTIONALLY LEFT BLANK
}

int Function::get_args() {
    return _arguments;
}
