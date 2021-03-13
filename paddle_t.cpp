//
// Created by RodrigoSalad on 13/03/2021.
//

#include "render_t.h"
#include "paddle_t.h"

namespace cb::physics{
    void paddle_t::draw() {
        cb::graph::render_t::draw_rectangle(position, dimension, color);
    }
}

