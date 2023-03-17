#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H

#include <SFML/Graphics.hpp>
#include "constants.h"
using namespace std;

struct graph_info {
    graph_info();
    graph_info(graph_info* _info);
    //string _equation;
    sf::Vector2f _window_dimensions,
                 _origin,   // in screen coordinates
                 _domain;

    int _points;    // number of points drawn
};

#endif // GRAPH_INFO_H
