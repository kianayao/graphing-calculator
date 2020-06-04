#ifndef COORDINATE_TRANSLATOR_H
#define COORDINATE_TRANSLATOR_H

#include "graph_info.h"

class coordinate_translator {
public:
    coordinate_translator(graph_info* g);
    sf::Vector2f translate(sf::Vector2f point);
private:
    graph_info* _info;
};

#endif // COORDINATE_TRANSLATOR_H
