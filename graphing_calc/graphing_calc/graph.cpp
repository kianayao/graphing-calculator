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

void Graph::entering_func(bool entering, string func) {
    if (entering) {
        sf::RectangleShape input_box(sf::Vector2f(300, 150));
        input_box.move(sf::Vector2f(_info->_window_dimensions.x / 8, 100));
        input_box.setFillColor(sf::Color::Black);
        input_box.setOutlineColor(sf::Color::Yellow);
    }
}

void Graph::draw_axis(sf::RenderWindow &window) {
    // X AXIS
    sf::RectangleShape x_axis(sf::Vector2f(_info->_window_dimensions.x,2));
    x_axis.move(sf::Vector2f(0,_info->_origin.y));
    window.draw(x_axis);

    // Y AXIS
    sf::RectangleShape y_axis(sf::Vector2f(2,_info->_window_dimensions.y));
    y_axis.move(sf::Vector2f(_info->_origin.x,0));
    window.draw(y_axis);
}

void Graph::draw(sf::RenderWindow &window) {
    sf::CircleShape shape(2);
    shape.setFillColor(sf::Color(250,0,0));

    draw_axis(window);

    for (int i = 0;i < _points.get_size() - 1; i++) {
        shape.setPosition(_points[i].x, _points[i].y);
        window.draw(shape);
    }
}
