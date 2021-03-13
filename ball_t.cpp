//
// Created by RodrigoSalad on 13/03/2021.
//

#include "render_t.h"
#include "ball_t.h"

namespace cb::physics{
    void ball_t::draw() {
        cb::graph::render_t::draw_ellipse(position, dimension, color);
    }
}

