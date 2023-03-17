#include "numbers.h"

Numbers::Numbers(): _num(NULL), _is_x(false) {
    // INTENTIONALLY LEFT BLANK
}

Numbers::Numbers(string num) {
    if (num == "x"  || num == "X") {
        _is_x = true;
        _num = 0;
    }
    else {
        _is_x = false;
        _num = stod(num);   // string to double
    }
}

double Numbers::get_num() {
    return _num;
}

int Numbers::type_of() {
    return NUM_TYPE;
}

bool Numbers::is_x() {
    return _is_x;
}

void Numbers::print() {
    if (_is_x)
        cout << "x";
    else
        cout << _num;
}
