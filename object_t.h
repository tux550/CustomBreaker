//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_OBJECT_T_H
#define CUSTOMBREAKER_OBJECT_T_H

#include "common_types.h"
#include "render_t.h"

namespace cb::physics{
    // Pre-Declaration
    class object_t;
    // Friend functions
    bool have_collided(object_t* a, object_t* b);

    // Implementation
    class object_t {
    protected:
        // Protected atributes
        position_t position{};
        dimension_t dimension{};
        velocity_t velocity{};
        cb::graph::color_t color{};
    public:
        // Constructor paremtrizado
        object_t(position_t p,
                 dimension_t d,
                 velocity_t v,
                 cb::graph::color_t c):
                 position{p},
                 dimension{d},
                 velocity{v},
                 color{c}
                 {}
        // Destructor (Default)
        virtual ~object_t() = default;
        // Metodos virtuales
        virtual void move();
        virtual void draw() = 0; // Puro: Depende del objeto especifico
        // Funciones Friend
        friend bool have_collided(object_t* a, object_t* b);
    };
}



#endif //CUSTOMBREAKER_OBJECT_T_H
