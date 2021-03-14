#include <iostream>
#include <SFML/Graphics.hpp>

#include "debug_config.h"
#include "common_types.h"
#include "args_interpreter.h"
#include "render_t.h"
#include "physics.h"
#include "level_loader.h"
#include "direction_input.h"
#include "utility.h"

#include <thread>
#include <chrono>
using namespace std::chrono_literals;

int main(const int argc, char** argv)
{
    /* [1] LOAD PAREMENTERS */
    // Create default parameters
    cb::args_intr::args_dict game_dict = {
            {"-lvl","level.lvl"},
            {"-difficulty", "1"},
    };
    // Load parameters from Command line
    cb::args_intr::LinkedAC{game_dict}(argc, argv);
    // Tests/Debug
    #ifdef ENABLE_DEBUG_ARGS_DICT
    /* TEST - DEBUGGING [1] : Print de argumentos */
    std::cout << "GAME PARAMETERS:" << std::endl;
    for (const auto &i : game_dict) { std::cout << i.first << "=" << i.second << std::endl; }
    /* ----------------------------------------- */
    #endif

    /* [2] CREATE GAME OBJECTS */
    // Load blocks from file
    cb::level::block_ls ls_blocks;
    cb::bound_t game_bound = cb::level::generate_blocks(ls_blocks, game_dict["-lvl"]);
    // Init paddle
    cb::level::paddle_t paddle = cb::level::generate_paddle(game_bound);
    // Init balls
    cb::level::ball_ls ls_balls;
    cb::level::generate_balls(ls_balls, game_bound);
    // Tests/Debug
    #ifdef ENABLE_DEBUG_FILE_LOAD_BLOCK
    /* TEST - DEBUGGING [2] : Print resulting list */
        std::cout << "BLOCKS CREATED:" << std::endl;
        for (const auto &i : ls_blocks) { std::cout << *i << std::endl; }
    /* ----------------------------------------- */
    #endif
    #ifdef ENABLE_DEBUG_FILE_LOAD_PADDLE
    /* TEST - DEBUGGING [3] : Print resulting paddle */
        std::cout << "PADDLE CREATED:" << std::endl;
        std::cout << paddle << std::endl;
    /* ----------------------------------------- */
    #endif
    #ifdef ENABLE_DEBUG_FILE_LOAD_BALL
    /* TEST - DEBUGGING [4] : Print resulting paddle */
        std::cout << "BALL CREATED:" << std::endl;
        for (const auto &i : ls_balls) { std::cout << *i << std::endl; }
    /* ----------------------------------------- */
    #endif

    /* [3] CREATE WINDOWS & GAME EVENT HANDELER */
    auto render = cb::graph::render_t::get_instance(
            game_bound,
            "CustomBreaker"
            );
    auto& p_render = render->get_platform_render();
    cb::input::direction_input DirectionGetter;
    #ifdef ENABLE_DEBUG_WINDOW
    /* TEST - DEBUGGING [5] : Print resulting windows data */
            {
                auto size  = cb::graph::render_t::get_limit();
                std::cout << "WINDOW DATA: " << std::endl;
                std::cout << "Bounds: {"<< size.lim_x << "," << size.lim_y << "} " << std::endl;
            }
        /* ----------------------------------------- */
    #endif

    /* [4] MAIN LOOP */
    while (p_render.isOpen()){
        // [4.1] Verificar cerrado de ventana
        sf::Event event{};
        while (p_render.pollEvent(event))
        {if  (event.type == sf::Event::Closed) p_render.close();}
        // [4.2] Leer keyboard input
        paddle.setHorDirection(DirectionGetter());
        // [4.3] Evaluar Collisiones
        // Colision de paddle con borde
        // Collision de ball con bloques
        // [4.4] Mover y Dibujar
        p_render.clear(cb::graph::color_t::Blue);
        cb::utility::bulk_move_draw(ls_balls, ls_blocks, paddle);
        // [4.5] Display y sleep
        p_render.display();
        std::this_thread::sleep_for(10ms);
    }
    return 0;
}