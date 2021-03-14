//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_PADDLE_T_H
#define CUSTOMBREAKER_PADDLE_T_H

#include <iostream>
#include "object_t.h"

namespace cb::physics {
    // Pre-definition
    class paddle_t;

    // Operator overload
    std::ostream& operator<<(std::ostream& os, const paddle_t& p);

    // Implementation
    class paddle_t: public object_t {
        using object_t::object_t; // Heredar constructor
        // EQUIVALENTE A (En public):
        // paddle_t(position_t p,
        //              dimension_t d,
        //              velocity_t v,
        //              cb::graph::color_t c):
        //              object_t{p,d,v,c}
        //              {}
    public:
        void draw() override;
        friend std::ostream& operator<<(std::ostream& os, const paddle_t& p);
    };
}


#endif //CUSTOMBREAKER_PADDLE_T_H
