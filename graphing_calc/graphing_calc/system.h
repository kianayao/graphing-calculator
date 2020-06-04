#ifndef SYSTEM_H
#define SYSTEM_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "graph.h"

using namespace std;

class System
{
public:
    System(graph_info* g);
    void Step(int command);
    void Draw(sf::RenderWindow& window);
    void entering_function(sf::RenderWindow& window,
                           bool entering, string func);
private:
    Graph _g;
    graph_info* _info;
};

#endif // SYSTEM_H
