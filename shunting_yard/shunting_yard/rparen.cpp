#include "rparen.h"

Rparen::Rparen(): _right_parent(")"), _prec(2) {

}

int Rparen::type_of() {
    return RPAREN_TYPE;
}

void Rparen::print() {
    cout << _right_parent;
}
