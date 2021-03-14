//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_BALL_T_H
#define CUSTOMBREAKER_BALL_T_H

#include "object_t.h"

namespace cb::physics {
    // Pre-definition
    class ball_t;

    // Operator overload
    std::ostream& operator<<(std::ostream& os, const ball_t& b);

    // Implementation
    class ball_t: public object_t {
        using object_t::object_t; // Heredar constructor
        // EQUIVALENTE A (En public):
        // ball_t(position_t p,
        //              dimension_t d,
        //              velocity_t v,
        //              cb::graph::color_t c):
        //              object_t{p,d,v,c}
        //              {}
    public:
        void draw() override;
        friend std::ostream& operator<<(std::ostream& os, const ball_t& b);
    };
}


#endif //CUSTOMBREAKER_BALL_T_H
