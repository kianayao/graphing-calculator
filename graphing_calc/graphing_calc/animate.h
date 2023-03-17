#ifndef ANIMATE_H
#define ANIMATE_H


#include "system.h"
#include "sidebar.h"
#include "constants.h"

class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void entering_func();
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    System system;                      //container for all the animated objects
    Sidebar sidebar;                    //rectangular message sidebar
    graph_info* _info;
    int _command;                        //command to send to system
    bool mouseIn;                       //mouse is in the screen
    int _sidebar_index;
    string _function;
    bool _entering_func;

};

string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
