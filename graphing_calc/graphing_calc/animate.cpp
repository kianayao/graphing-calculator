#include "animate.h"
#include "system.h"

#include <iostream>
using namespace std;


animate::animate(): sidebar(WORK_PANEL, SIDE_BAR), system(_info),
                    _info(new graph_info), _sidebar_index(SB_KEY_PRESSED + 1),
                    _function(""), _entering_func(false)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    system = System(_info);
    window.setFramerateLimit(60);

    mouseIn = true;


    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
//    if (!font.loadFromFile("../arial.ttf")){
//        cout<<"animate() CTOR: Font failed to load"<<endl;
//        cin.get();
//        exit(-1);
//    }

//    myTextLabel = sf::Text("Initial String for myTextLabel", font);
//    myTextLabel.setCharacterSize(20);
//    myTextLabel.setStyle(sf::Text::Bold);
//    myTextLabel.setColor(sf::Color::Green);
//    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));







    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(_command);
    _command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }
}
void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event)) { //or waitEvent
       // check the type of the event...
           switch (event.type) {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:

               switch(event.key.code){

                case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                   _command = 4;
                   break;

               case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                   _command = 6;
                   break;

               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;

               case sf::Keyboard::Enter:
                   if (_entering_func == false) {
                     sidebar[SB_KEY_PRESSED] = "ENTER";
                     _command = 8;
                   }
                   else {   // _entering_func == true
                       _entering_func = false;
                       sidebar[_sidebar_index++] = _function;
                       _function = "";
                   }
                   break;

               case sf::Keyboard::LShift:
                   sidebar[SB_KEY_PRESSED] = "SHIFT + ENTER";
                   // if (sf::Keyboard::Space)
                       _command = 10;
                   break;

               case sf::Keyboard::RShift:
                   sidebar[SB_KEY_PRESSED] = "SHIFT + ENTER";
                   // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                       _command = 10;
                   break;

               case sf::Keyboard::A:
                   if (_entering_func)
                       _function += "a";
                   break;

               case sf::Keyboard::B:
                   if (_entering_func)
                       _function += "b";
                   break;

               case sf::Keyboard::C:
                   if (_entering_func)
                       _function += "c";
                   break;

               case sf::Keyboard::D:
                   if (_entering_func)
                       _function += "d";
                   break;

               case sf::Keyboard::E:
                   if (_entering_func)
                       _function += "e";
                   break;

               case sf::Keyboard::F:
                   if(! _entering_func) {
                        _entering_func = true;
                        entering_func();
                   }
                   else if (_entering_func)
                       _function += "f";
                   break;

               case sf::Keyboard::G:
                   if (_entering_func)
                       _function += "g";
                   break;

               case sf::Keyboard::H:
                   if (_entering_func)
                       _function += "h";
                   break;

               case sf::Keyboard::I:
                   if (_entering_func)
                       _function += "i";
                   break;

               case sf::Keyboard::J:
                   if (_entering_func)
                       _function += "j";
                   break;

               case sf::Keyboard::K:
                   if (_entering_func)
                       _function += "k";
                   break;

               case sf::Keyboard::L:
                   if (_entering_func)
                       _function += "l";
                   break;

               case sf::Keyboard::M:
                   if (_entering_func)
                       _function += "m";
                   break;

               case sf::Keyboard::N:
                   if (_entering_func)
                       _function += "n";
                   break;

               case sf::Keyboard::O:
                   if (_entering_func)
                       _function += "o";
                   break;

               case sf::Keyboard::P:
                   if (_entering_func)
                       _function += "p";
                   break;

               case sf::Keyboard::Q:
                   if (_entering_func)
                       _function += "q";
                   break;

               case sf::Keyboard::R:
                   if (_entering_func)
                       _function += "r";
                   break;

               case sf::Keyboard::S:
                   if (_entering_func)
                       _function += "s";
                   break;

               case sf::Keyboard::T:
                   if (_entering_func)
                       _function += "t";
                   break;

               case sf::Keyboard::U:
                   if (_entering_func)
                       _function += "u";
                   break;

               case sf::Keyboard::V:
                   if (_entering_func)
                       _function += "v";
                   break;

               case sf::Keyboard::W:
                   if (_entering_func)
                       _function += "w";
                   break;

               case sf::Keyboard::X:
                   if (_entering_func)
                       _function += "x";
                   break;

               case sf::Keyboard::Y:
                   if (_entering_func)
                       _function += "y";
                   break;

               case sf::Keyboard::Z:
                   if (_entering_func)
                       _function += "z";
                   break;
               }

               break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;

           case sf::Event::MouseButtonReleased:

                   if (event.mouseButton.button == sf::Mouse::Right) {
                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);
                   }

                   else {
                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               mouse_pos_string(window);
                   }

                   break;

               default:     break;
           }    // switch

           //entering_func();

       }    // while
}

void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}

void animate::entering_func() {
    if (_entering_func) {
        cout << "draw rect" << endl;
        sf::RectangleShape input_box(sf::Vector2f(300, 150));
        input_box.setPosition(sf::Vector2f(_info->_window_dimensions.x / 8, 100));
//        input_box.setFillColor(sf::Color::Black);
//        input_box.setOutlineColor(sf::Color::Yellow);

        window.draw(input_box);

        sf::Text func_text;
        func_text.setFont(font);
        func_text.setCharacterSize(15);
        func_text.setStyle(sf::Text::Bold);
        func_text.setColor(sf::Color::Yellow);
        func_text.setString(_function);
        window.draw(func_text);

    }
}

