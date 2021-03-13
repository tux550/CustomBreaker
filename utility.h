//
// Created by RodrigoSalad on 13/03/2021.
//

#ifndef CUSTOMBREAKER_UTILITY_H
#define CUSTOMBREAKER_UTILITY_H

namespace cb::utility{
    // Base case
    void bulk_move_draw();

    // Recursive Container of pointers case
    template <
            template <typename ...> class Cont,
            typename T,
            typename ... Params,
            typename ... Others
            >
    void bulk_move_draw(Cont<T, Params...>& cont, Others& ... args){
        for (auto& i : cont) {
            i->move();
            i->draw();
            bulk_move_draw(args...);
        }
    }

    // Recursive Element reference case
    template <typename First, typename  ... Others>
    void bulk_move_draw(First& first, Others& ... args){
        first.move();
        first.draw();
        bulk_move_draw(args...);
    }

}

#endif //CUSTOMBREAKER_UTILITY_H
