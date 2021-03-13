//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_PADDLE_T_H
#define CUSTOMBREAKER_PADDLE_T_H

#include "object_t.h"

namespace cb::physics {
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
    };
}


#endif //CUSTOMBREAKER_PADDLE_T_H