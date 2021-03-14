#include <iostream>
#include <SFML/Graphics.hpp>

#include "debug_config.h"
#include "common_types.h"
#include "args_interpreter.h"
#include "render_t.h"
#include "physics.h"
#include "level_loader.h"
#include "utility.h"

#include <thread>
#include <chrono>
using namespace std::chrono_literals;

int main(const int argc, char** argv)
{
    /* LOAD PAREMENTERS */
    // Create default parameters
    cb::args_intr::args_dict game_dict = {
            {"-lvl","simple_level.lvl"},
            {"-difficulty", "1"}
    };
    // Load parameters from Command line
    cb::args_intr::LinkedAC{game_dict}(argc, argv);
    /* TEST - DEBUGGING [1] : Print de argumentos */
    #ifdef ENABLE_DEBUG_ARGS_DICT
    std::cout << "GAME PARAMETERS:" << std::endl;
    for (const auto &i : game_dict) { std::cout << i.first << "=" << i.second << std::endl; }
    #endif
    /* ----------------------------------------- */



    /* CREATE OBJECTS */
    // Load blocks from file
    cb::level::block_ls ls_blocks;
    cb::bound_t game_bound = cb::level::generate_blocks(ls_blocks, game_dict["-lvl"]);
    /* TEST - DEBUGGING [2] : Print resulting list */
    #ifdef ENABLE_DEBUG_FILE_LOAD_BLOCK
        std::cout << "BLOCKS CREATED:" << std::endl;
        for (const auto &i : ls_blocks) { std::cout << *i << std::endl; }
    #endif
    /* ----------------------------------------- */
    // Init paddle
    cb::level::paddle_t paddle = cb::level::generate_paddle(game_bound);
    /* TEST - DEBUGGING [3] : Print resulting paddle */
    #ifdef ENABLE_DEBUG_FILE_LOAD_PADDLE
        std::cout << "PADDLE CREATED:" << std::endl;
        std::cout << paddle << std::endl;
    #endif
    /* ----------------------------------------- */
    // Init balls
    cb::level::ball_ls ls_balls;
    cb::level::generate_balls(ls_balls, game_bound);
    /* TEST - DEBUGGING [4] : Print resulting paddle */
    #ifdef ENABLE_DEBUG_FILE_LOAD_BALL
        std::cout << "BALL CREATED:" << std::endl;
        for (const auto &i : ls_balls) { std::cout << *i << std::endl; }
    #endif



    /* CREATE WINDOWS */
    auto render = cb::graph::render_t::get_instance(
            game_bound,
            //{1200,800},
            "CustomBreaker"
            );
    auto& p_render = render->get_platform_render();



    while (p_render.isOpen()){
        sf::Event event{};
        while (p_render.pollEvent(event))
        {
            if  (event.type == sf::Event::Closed) p_render.close();
        }
        // Evaluar Collisiones
        // Actualizar pos y Dibujar
        p_render.clear(cb::graph::color_t::Blue);
        cb::utility::bulk_move_draw(ls_balls, ls_blocks, paddle);

        // Display y sleep
        p_render.display();
        std::this_thread::sleep_for(10ms);
    }






















    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
     */

    return 0;
}