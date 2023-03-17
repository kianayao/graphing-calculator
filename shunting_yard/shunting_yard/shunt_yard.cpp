#include "shunt_yard.h"

Shunt_Yard::Shunt_Yard(): _postfix() {
    //INTENTIONALLY LEFT BLANK
}

Shunt_Yard::Shunt_Yard(Queue<Token*> infix): _postfix(postfix(infix)) {
   // INTENTIONALLY LEFT BLANK
}

Queue<Token*> Shunt_Yard::get_postfix() {
    return _postfix;
}

Queue<Token*> Shunt_Yard::postfix(const Queue<Token*> &infix) {
    Queue<Token*> final;
    Stack<Token*> ops;
    int prec1 = 300, prec2;
    typename Simple_List<Token*>::Iterator walker = infix.top();

    while (walker != nullptr) {

        //DEBUG: cout << "temp type: " << temp->type_of() << endl;

        if ((*walker)->type_of() == OP_TYPE ||      // checks op or lparen type
            (*walker)->type_of() == LPAREN_TYPE) {

            if (! ops.empty())    // if ops stack has items
                prec1 = static_cast<Operator*>(ops.top()->_item)->get_prec();
                // ^ top of stack
                prec2 = static_cast<Operator*>(*walker)->get_prec();
                // ^ want to push into stack

                if (prec2 > prec1 || (*walker)->type_of() == LPAREN_TYPE ||
                    ops.empty())
                    // walker prec > prec1 || walker == ( || ops stack empty
                    ops.push_head(*walker);

                else if (prec2 <= prec1 &&
                         ops.top()->_item->type_of() == LPAREN_TYPE)
                    // walker prec <= prec1 && ops top == (
                    ops.push_head(*walker);

                else if (prec2 <= prec1 &&
                         ops.top()->_item->type_of() != LPAREN_TYPE) {
                    // walker prec <= prec1 && ops top != (
                    final.push_end(ops.pop_head());
                    ops.push_head(*walker);
                }
        }

        else if ((*walker)->type_of() == NUM_TYPE)  // push num to final queue
            final.push_end(*walker);

        else if ((*walker)->type_of() == RPAREN_TYPE) {     // )

            while ((*walker)->type_of() != LPAREN_TYPE) {   // walker != (
                (*walker) = ops.pop_head();                 // pop stack
                if ((*walker)->type_of() != LPAREN_TYPE)    // == ) don't push
                    final.push_end(*walker);
            }
        }

        walker = walker.next();     // increment iterator
    }
    while (! ops.empty())
        final.push_end(ops.pop_head());
    // empty ops stack to end of final queue

    return final;
}

ostream& operator <<(ostream& outs, Shunt_Yard sy) {
    outs << sy._postfix;
    return outs;
}
