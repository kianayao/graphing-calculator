#include "graph.h"


Graph::Graph(graph_info* g): _info(g), _plotter(g) {
    // INTENTIONALLY LEFT BLANK
}

void Graph::commands(int command) {
    const int LEFT_PAN = 4, RIGHT_PAN = 6, ZOOM_IN = 8, ZOOM_OUT = 10;
    float scale = (_info->_domain.y - _info->_domain.x) * .30;
    // # of points to move when panning or to zoom

    float x_scale = (_info->_window_dimensions.x /
                      (_info->_domain.y - _info->_domain.x));

    switch (command) {
    case LEFT_PAN:
        _info->_domain.x -= scale;
        _info->_domain.y -= scale;
//        _info->_origin.x += (scale * (_info->_window_dimensions.x /
//                            (_info->_domain.y - _info->_domain.x)));
        break;

    case RIGHT_PAN:
        _info->_domain.x += scale;
        _info->_domain.y += scale;
//        _info->_origin.x -= (scale * (_info->_window_dimensions.x /
//                            (_info->_domain.y - _info->_domain.x)));
        break;

    case ZOOM_IN:
        _info->_domain.x += scale;
        _info->_domain.y -= scale;
        //_info->_origin.x = (0 - _info->_domain.x) * x_scale;
        break;

    case ZOOM_OUT:
        _info->_domain.x -= scale;
        _info->_domain.y += scale;
       // _info->_origin.x = (0 - _info->_domain.x) * x_scale;
        break;

    default:    break;
    }

    _info->_origin.x = (0 - _info->_domain.x) * x_scale;
}

void Graph::update() {
    _points = _plotter();
}



void Graph::draw_axis(sf::RenderWindow &window) {
    // X AXIS
    sf::RectangleShape x_axis(sf::Vector2f(_info->_window_dimensions.x,1));
    x_axis.move(sf::Vector2f(0,_info->_origin.y));
    window.draw(x_axis);

    // Y AXIS
    sf::RectangleShape y_axis(sf::Vector2f(1,_info->_window_dimensions.y));
    y_axis.move(sf::Vector2f(_info->_origin.x,0));
    window.draw(y_axis);
}

void Graph::entering_func(sf::RenderWindow &window,
                   bool entering, string func) {
    const int WIDTH = 500, HEIGHT = 75, MARGIN = 50;

    double pos_x = (_info->_window_dimensions.x - WIDTH) /2,
           pos_y = _info->_window_dimensions.y * .05;

    if (entering) {
        sf::RectangleShape input_box(sf::Vector2f(WIDTH, HEIGHT));
        input_box.move(sf::Vector2f(pos_x, pos_y));
        input_box.setFillColor(sf::Color::Black);
        input_box.setOutlineThickness(1);
        input_box.setOutlineColor(sf::Color::Yellow);

        window.draw(input_box);

        sf::Text func_text;
        sf::Font font;
        font.loadFromFile("Roboto-Thin.ttf");
        func_text.setFont(font);
        func_text.setCharacterSize(15);
        func_text.setStyle(sf::Text::Bold);
        func_text.setColor(sf::Color::Yellow);
        func_text.setString(func);
        func_text.setPosition(sf::Vector2f(pos_x + MARGIN,
                                           pos_y + (HEIGHT / 3)));

        window.draw(func_text);
    }
}

void Graph::draw(sf::RenderWindow &window) {
    sf::CircleShape shape(1);
    shape.setFillColor(sf::Color(250,0,0));

    draw_axis(window);

    for (int i = 0;i < _points.get_size() - 1; i++) {
        shape.setPosition(_points[i].x, _points[i].y);
        window.draw(shape);
    }
}
