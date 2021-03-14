//
// Created by RodrigoSalad on 14/03/2021.
//

#include "direction_input.h"

namespace cb::input{
    direction_t direction_input::operator()() {
        // Retorna direccion unitaria horizontal
        direction_t dir = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            dir -= 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            dir += 1.0f;
        }
        return dir;
    }
}
