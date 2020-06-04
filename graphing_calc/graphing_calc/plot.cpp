#include "plot.h"

plot::plot(graph_info* g): _info(g) {
    // INTENTIONALLY LEFT BLANK
}


Vector<sf::Vector2f> plot::operator ()() {
    Vector<sf::Vector2f> points;
    coordinate_translator trans(_info);
    Queue<Token*> test;


      // y = 2x
//    test.push_end(new Numbers("x"));
//    test.push_end(new Function("*"));
//    test.push_end(new Numbers("2"));

    // y = x
//    test.push_end(new Numbers("x"));

    // y = x^2
    test.push_end(new Function("tan", 1));
    test.push_end(new Lparen());
    test.push_end(new Numbers("1"));
    test.push_end(new Function("/", 2));
    test.push_end(new Numbers("x"));
//    test.push_end(new Function("/"));
//    test.push_end(new Numbers("12"));
//    test.push_end(new Function("*"));
//    test.push_end(new Numbers("x"));
//    test.push_end(new Function("-"));
//    test.push_end(new Numbers("x"));
    test.push_end(new Rparen());
    Shunt_Yard _postfix(test);

    double i = _info->_domain.x;
    while (i <= _info->_domain.y) {
        sf::Vector2f point(i,_rpn.get_y(_postfix.postfix(test), i));
        point = trans.translate(point);
        points += point;
        i += (_info->_domain.y - _info->_domain.x) / _info->_points;
    }

    return points;
}

