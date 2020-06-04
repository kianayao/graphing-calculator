#ifndef GRAPH_H
#define GRAPH_H

#include "plot.h"

class Graph
{
public:
    Graph(graph_info* g);
    void update();
    void draw(sf::RenderWindow &window);
    void draw_axis(sf::RenderWindow &window);
    void commands(int command);
    void entering_func(bool entering, string func);
private:
    graph_info* _info;
    plot _plotter;
    Vector<sf::Vector2f> _points;
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
};

#endif // GRAPH_H
