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
    private:
        // Atributos Privados
        cb::speed_t max_speed;
    public:
        // Constructor
        paddle_t(position_t p,
                 dimension_t d,
                 velocity_t v,
                 cb::graph::color_t c,
                 cb::speed_t m):
                 object_t{p,d,v,c},
                 max_speed{m}
                 {}
        // Espacializacion
        void draw() override;
        friend std::ostream& operator<<(std::ostream& os, const paddle_t& p);
        // Update Direcction
        void setHorDirection(speed_t dirx) {
            if  (dirx > 1.0f || dirx < -1.0f) {cb::error_exit<1>("DIRECCION DE MOVIMIENTO NO VALIDA: ", dirx);}
            velocity.vx= dirx * max_speed;
        };
    };
}


#endif //CUSTOMBREAKER_PADDLE_T_H
