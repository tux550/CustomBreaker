//
// Created by RodrigoSalad on 13/03/2021.
//

#include "object_t.h"

namespace cb::physics{

    bool have_collided(object_t *a, object_t *b) {
        // Aproximacion de rectangulo:
        // Alineacion Y: Si uno esta arriba del otro
        if  (
                (a->position.x+a->dimension.width < b->position.x) ||  // A esta a la izquierda de B
                (b->position.x+b->dimension.width < a->position.x)     // B esta a la i<quierda de A
                ) {return false;}
        // Alineacion X: Si uno esta al lado del otro
        if  (
                (a->position.y+a->dimension.height < b->position.y) ||  // A esta a la abajo de B
                (b->position.y+b->dimension.height < a->position.y)     // B esta a la abajo de A
                ) {return false;}
        // Caso contrario si collisionan
        return true;
    }

    void object_t::move() {
        position.x += velocity.vx;
        position.y += velocity.vy;
    }
}