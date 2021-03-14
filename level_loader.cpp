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
        // Supress warning
        return nullptr;
    }

    cb::bound_t Char2Block::bounds(const position_t &cord) {
        cb::bound_t b {
                static_cast<limit_t>(( (cord.x) * (BlockDim.width+2*BlockPad.x) )),
                static_cast<limit_t>(( (cord.y) * (BlockDim.height+2*BlockPad.y) + BottomMargin))
        };
        return b;
    }

    /* OBJECT GENERATORS */
    cb::physics::paddle_t generate_paddle(const cb::bound_t &bounds) {
        return {
                    {
                        ( static_cast<length_t>(bounds.lim_x/2) - static_cast<length_t>(PaddleDim.width/2) ),
                        (bounds.lim_y-cb::level::PaddleMargin)
                    },
                    cb::level::PaddleDim,
                    {0.0f,0.0f},
                    cb::graph::color_t::White
                };
    }
    void generate_balls (ball_ls& balls_list, const cb::bound_t& bounds){
        balls_list.push_back(
        new cb::physics::ball_t(
                        {
                            ( static_cast<cb::length_t>(bounds.lim_x/2) - static_cast<length_t>(BallDim.width/2) ),
                            (bounds.lim_y-cb::level::PaddleMargin)-50
                        },
                        cb::level::BallDim,
                        {0.0f,0.5f},
                        cb::graph::color_t::Green
                    )
        );
    }
}