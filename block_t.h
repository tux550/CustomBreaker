//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_BLOCK_T_H
#define CUSTOMBREAKER_BLOCK_T_H

#include <iostream>
#include "object_t.h"

namespace cb::physics {
    // Pre-definition
    class block_t;

    // Operator overload
    std::ostream& operator<<(std::ostream& os, const block_t& b);

    // Implementation
    class block_t: public object_t {
        using object_t::object_t; // Heredar constructor
        // EQUIVALENTE A (En public):
        // block_t(position_t p,
        //              dimension_t d,
        //              velocity_t v,
        //              cb::graph::color_t c):
        //              object_t{p,d,v,c}
        //              {}
    public:
        void draw() override;
        friend std::ostream& operator<<(std::ostream& os, const block_t& b);
    };
}


#endif //CUSTOMBREAKER_BLOCK_T_H
