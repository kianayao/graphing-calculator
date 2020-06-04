#include "system.h"

#include <iostream>
#include <constants.h>

System::System(graph_info* g): _g(g), _info(g) {
    // INTENTIONALLY LEFT BLANK
}

void System::Step(int command){
    _g.commands(command);
    _g.update();

}

void System::entering_function(sf::RenderWindow& window,
                       bool entering, string func) {
    _g.entering_func(window, entering, func);
}

void System::Draw(sf::RenderWindow& window){
    _g.draw(window);
}

