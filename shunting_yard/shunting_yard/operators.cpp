#include "operators.h"

Operator::Operator(): _op(""), _prec(-1) {
    // INTENTIONALLY LEFT BLANK
}

Operator::Operator(string op): _op(op), _prec(precedence(op)) {
    // INTENTIONALLY LEFT BLANK
}

int Operator::type_of() {
    return OP_TYPE;
}

int Operator::precedence(string op) {
    if (op == "+" || op == "-")
        return LOWER_PREC;
    else if (op == "*" || op == "/")
        return HIGHER_PREC;
    else if (op == "^")
        return HIGHEST_PREC;
    else if (op == "cos" || op == "sin" || op == "tan" || op == "csc" ||
             op == "sec" || op == "cot" || op == "log" || op == "ln")
        return FUNCTIONS;
    return -1;
}

int Operator::get_prec() {
    return _prec;
}

string Operator::get_op() {
    return _op;
}
void Operator::print() {
    cout << _op;
}

