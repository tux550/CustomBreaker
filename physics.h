//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_PHYSICS_H
#define CUSTOMBREAKER_PHYSICS_H

#include "ball_t.h"
#include "block_t.h"
#include "paddle_t.h"

namespace cb::physics{
    // CONSTANTS

    // Objects
    const cb::dimension_t DefBallDim = {10.0f, 10.0f};
    const cb::dimension_t DefBlockDim = {50.0f, 10.0f};
    const cb::dimension_t DefPaddleDim = {100.0f, 10.0f};
}

#endif //CUSTOMBREAKER_PHYSICS_H
