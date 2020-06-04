#include "coordinate_translator.h"

coordinate_translator::coordinate_translator(graph_info* g): _info(g) {

}

sf::Vector2f coordinate_translator::translate(sf::Vector2f point) {
    sf::Vector2f new_point;
    double scaling = _info->_window_dimensions.x /
            (_info->_domain.y - _info->_domain.x);

    new_point.x = (point.x - _info->_domain.x) * scaling;

    new_point.y = _info->_origin.y - point.y * scaling;

    //300 is 1/2 of the screen length and width
    return  new_point;
}
