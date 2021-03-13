//
// Created by RodrigoSalad on 11/03/2021.
//

#ifndef CUSTOMBREAKER_PLATFORM_TYPES_H
#define CUSTOMBREAKER_PLATFORM_TYPES_H

#include <SFML/Graphics.hpp>
#include "common_types.h"

namespace cb::graph{
    using color_t = sf::Color;
    using platform_render_t = sf::RenderWindow;
    auto get_render_size = [](const bound_t& bound) {
        return sf::VideoMode(bound.lim_x, bound.lim_y);
    };
}

#endif //CUSTOMBREAKER_PLATFORM_TYPES_H
