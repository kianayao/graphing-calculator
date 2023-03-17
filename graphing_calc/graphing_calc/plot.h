#ifndef PLOT_H
#define PLOT_H

#include "graph_info.h"
#include "../../!includes/my_vector/my_vector.h"
#include "coordinate_translator.h"
#include "rpn.h"

class plot {
public:
    plot(graph_info* g);
    void set_info();
    Vector<sf::Vector2f> operator ()();
private:
    graph_info* _info;
    rpn _rpn;
    //Shunt_Yard _postfix;

};

#endif // PLOT_H
