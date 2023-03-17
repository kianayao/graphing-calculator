#include "lparen.h"

Lparen::Lparen(): _left_parent("("), _prec(HIGHER_PREC) {

}

int Lparen::type_of() {
    return LPAREN_TYPE;
}

void Lparen::print() {
    cout << _left_parent;
}
