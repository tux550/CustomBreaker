//
// Created by RodrigoSalad on 14/03/2021.
//

#ifndef CUSTOMBREAKER_DIRECTION_INPUT_H
#define CUSTOMBREAKER_DIRECTION_INPUT_H

#include <SFML/Graphics.hpp>
#include "common_types.h"
#include "platform_types.h"

namespace cb::input{
    // Types
    using direction_t = cb::speed_t;

    /* FUNCTOR */
    class direction_input {
    public:
        // Functor for direction of movement based on input
        // Constructor
        direction_input() = default;
        // Operator overload
        direction_t operator() ();
    };

}



#endif //CUSTOMBREAKER_DIRECTION_INPUT_H
