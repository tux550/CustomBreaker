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
                        (cord.x * (cb::level::BlockConfig::BlockDim.width+2*cb::level::BlockConfig::BlockPad.x) + cb::level::BlockConfig::BlockPad.x),
                        (cord.y * (cb::level::BlockConfig::BlockDim.height+2*cb::level::BlockConfig::BlockPad.y) + cb::level::BlockConfig::BlockPad.y)
                };
                return new cb::physics::block_t (pos, cb::level::BlockConfig::BlockDim, cb::level::BlockConfig::BlockVel, cb::level::BlockConfig::BlockColor);
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
                static_cast<limit_t>(( (cord.x) * (cb::level::BlockConfig::BlockDim.width+2*cb::level::BlockConfig::BlockPad.x) )),
                static_cast<limit_t>(( (cord.y) * (cb::level::BlockConfig::BlockDim.height+2*cb::level::BlockConfig::BlockPad.y) + cb::level::BlockConfig::BottomMargin))
        };
        return b;
    }

    /* OBJECT GENERATORS */
    cb::physics::paddle_t generate_paddle(const cb::bound_t &bounds) {
        return {
                    {
                        ( static_cast<length_t>(bounds.lim_x/2) - static_cast<length_t>(cb::level::PaddleConfig::PaddleDim.width/2) ),
                        (bounds.lim_y-cb::level::PaddleConfig::PaddleMargin)
                    },
                    cb::level::PaddleConfig::PaddleDim,
                    {0.0f,0.0f},
                    cb::level::PaddleConfig::PaddleColor,
                    cb::level::PaddleConfig::PaddleMaxSpeed
                };
    }
    void generate_balls (ball_ls& balls_list, const cb::bound_t& bounds){
        balls_list.push_back(
        new cb::physics::ball_t(
                        {
                            ( static_cast<cb::length_t>(bounds.lim_x/2) - static_cast<length_t>(cb::level::BallConfig::BallDim.width/2) ),
                            (bounds.lim_y-cb::level::PaddleConfig::PaddleMargin)-50
                        },
                        cb::level::BallConfig::BallDim,
                        {0.0f,cb::level::BallConfig::BallMaxSpeed},
                        cb::level::BallConfig::BallColor
                    )
        );
    }
}