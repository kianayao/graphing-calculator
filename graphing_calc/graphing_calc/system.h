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
private:
    Graph _g;
};

#endif // SYSTEM_H
