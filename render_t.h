//
// Created by RodrigoSalad on 11/03/2021.
//

#ifndef CUSTOMBREAKER_RENDER_T_H
#define CUSTOMBREAKER_RENDER_T_H

#include "platform_types.h"

namespace cb::graph{
    /* Patron SINGLETON */
    //Declaracion
    class render_t;

    // Implementacion
    class render_t {
    private:
        // Atributos Privados
        platform_render_t platform_render;
        inline static render_t* instance = nullptr;
        // Metodos privados
        render_t(const cb::bound_t &bound, const cb::string_t &title); // Construcor privado
    public:
        /* Destructor */
        ~render_t () = default;
        /* Metodos */
        // Generador/Getter de instancia                          valores por defecto
        static render_t* get_instance(const cb::bound_t  &bound = {1200,800},
                                      const cb::string_t &title = "Title");
        // Metodos custom de dibujo
        static void draw_rectangle(cb::position_t p, cb::dimension_t d, color_t c);
        static void draw_ellipse(cb::position_t p, cb::dimension_t d, color_t c);
        // Getters
        static cb::bound_t get_limit();
        platform_render_t& get_platform_render();
    };

}




#endif //CUSTOMBREAKER_RENDER_T_H
