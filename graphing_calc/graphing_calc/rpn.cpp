#include "rpn.h"
#include <cmath>

rpn::rpn() {
    // INTENTIONALLY LEFT BLANK
}

rpn::rpn(Queue<Token*> postfix, double x) {
    get_y(postfix, x);
}

double rpn::get_y(Queue<Token*> postfix, double x) {
    Token* temp;
    double pop_first, pop_second, result;

    while (! postfix.empty()) {
        temp = postfix.pop_head();

        if (temp->type_of() == NUM_TYPE) {
            if (static_cast<Numbers*>(temp)->is_x())
                _evaluate.push_head(new Numbers(to_string(x)));
            else
                _evaluate.push_head(temp);
        }


        else if (temp->type_of() == OP_TYPE) {

            // BASIC OPERATIONS

            if (static_cast<Function*>(temp)->get_args() == 2) {
                pop_first =
                        static_cast<Numbers*>(_evaluate.pop_head())->get_num();
                pop_second =
                        static_cast<Numbers*>(_evaluate.pop_head())->get_num();

                if (static_cast<Function*>(temp)->get_op() == "+")
                    result = pop_second + pop_first;

                else if (static_cast<Function*>(temp)->get_op() == "-")
                    result = pop_second - pop_first;

                else if (static_cast<Function*>(temp)->get_op() == "*")
                    result = pop_second * pop_first;

                else if (static_cast<Function*>(temp)->get_op() == "/")
                    result = pop_second / pop_first;

                else if (static_cast<Function*>(temp)->get_op() == "^")
                    result = pow(pop_second, pop_first);
            }

            // TRICONOMETRIC FUNCTIONS

            else if (static_cast<Function*>(temp)->get_args() == 1) {
                pop_first =
                        static_cast<Numbers*>(_evaluate.pop_head())->get_num();

                if (static_cast<Function*>(temp)->get_op() == "sin")
                   result = sin(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "arcsin")
                   result = asin(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "cos")
                   result = cos(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "arccos")
                   result = acos(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "tan")
                   result = tan(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "arctan")
                   result = atan(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "log")
                   result = log10(pop_first);

                else if (static_cast<Function*>(temp)->get_op() == "ln")
                   result = log(pop_first);
            }

            _evaluate.push_head(new Numbers(to_string(result)));

        }
    }

    return static_cast<Numbers*>(_evaluate.pop_head())->get_num();

}
