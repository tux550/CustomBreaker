//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_LEVEL_LOADER_H
#define CUSTOMBREAKER_LEVEL_LOADER_H

#include <iostream>
#include <fstream>
#include "common_types.h"
#include "physics.h"

namespace cb::level{
    using block_p = cb::physics::block_t*;
    using block_ls = cb::list<block_p>;

    /* CHAR INTERPRETER DEFAULT FUNCTOR */
    struct Char2Block{
    private:
        inline static const cb::dimension_t BlockDim{50.0f, 20.0f};
        inline static const cb::velocity_t  BlockVel{0.0f,0.0f};
        inline static const cb::padding_t   BlockPad{5.0f,5.0f};
        inline static const cb::graph::color_t BlockColor = cb::graph::color_t::Red;
    public:
        inline static const cb::length_t BottomMargin = 200.0f;
        block_p operator()(const cb::char_t& c, const cb::position_t& cord);
        static cb::bound_t bounds(const cb::position_t& cord);
    };

    /* FILE READING FUNCTION */
    template <typename Interpreter = cb::level::Char2Block>
    cb::bound_t generate_blocks(block_ls& blocks_list, const cb::string_t &file){
        // Complejidad: O(mxn)
        // m = cantidad de lineas
        // n = longitud de lineas

        // Lista resultante es una ordenada de tal forma que los mayores "Y" estan alfrente
        // y los menores al final

        // Generar objeto de archivo
        std::ifstream level(file);
        // Error if cant open
        if (!level.is_open()) {cb::error_exit<1>("NO SE PUDO ABRIR EL ARCHIVO: ", file);}
        // Inicializar variables
        cb::string_t line;
        Interpreter interpreter{};
        // Leer archivo
        cb::length_t y = 0;
        cb::length_t x = 0;
        while ( std::getline(level, line) ){
            x = 0;
            for (; x < line.size(); ++x) {
                auto tmp = interpreter(line[x], {x, y}); // Funcion que crea nuevo objeto o retorne nullptr
                if  (tmp != nullptr) {blocks_list.push_front(tmp);}
            }
            ++y;
        }
        // Process {x,y} cords to bounds
        return interpreter.bounds({x,y});
    }
}

#endif //CUSTOMBREAKER_LEVEL_LOADER_H