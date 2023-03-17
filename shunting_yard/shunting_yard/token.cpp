#include "token.h"

Token::Token()
{

}

int Token::type_of() {
    return TOKEN_TYPE;
}

void Token::print() {
    cout << "this is a token" << endl;
}

ostream& operator <<(ostream& outs, Token t) {
    t.print();
    return outs;
}

ostream& operator <<(ostream& outs, Token *t) {
    t->print();
    return outs;
}
