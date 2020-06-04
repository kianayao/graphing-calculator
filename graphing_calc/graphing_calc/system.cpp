#include "system.h"

#include <iostream>
#include <constants.h>

System::System(graph_info* g): _g(g) {


}

void System::Step(int command){
    _g.commands(command);
    _g.update();
}


void System::Draw(sf::RenderWindow& window){
    _g.draw(window);

}

