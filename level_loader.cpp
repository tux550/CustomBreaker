//
// Created by RodrigoSalad on 13/03/2021.
//

#include "level_loader.h"

namespace cb::level{
    block_p Char2Block::operator()(const char_t &c, const position_t &cord) {
        cb::position_t pos{};
        switch (c) {
            // Caso bloque
            case 'B':
                pos = {
                        (cord.x * (BlockDim.width+2*BlockPad.x) + BlockPad.x),
                        (cord.y * (BlockDim.height+2*BlockPad.y) + BlockPad.y)
                };
                return new cb::physics::block_t (pos, BlockDim, BlockVel, BlockColor);
                // Caso vacio
            case 'E':
                return nullptr;
                // Caso error
            default:
                cb::error_exit<1>("CARACTER NO VALIDO: ",c," EN (",cord.x,",",cord.y,")");

        };
    }

    cb::bound_t Char2Block::bounds(const position_t &cord) {
        cb::bound_t b {
                static_cast<limit_t>(( (cord.x) * (BlockDim.width+2*BlockPad.x) )),
                static_cast<limit_t>(( (cord.y) * (BlockDim.height+2*BlockPad.y) + BottomMargin))
        };
        return b;
    }
}