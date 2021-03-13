#include <iostream>
#include <SFML/Graphics.hpp>

#include "debug_config.h"
#include "common_types.h"
#include "args_interpreter.h"
#include "render_t.h"
#include "physics.h"
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
            {"-difficulty", "1"},
            {"-test","Nan"}
    };
    // Load parameters from Command line
    cb::args_intr::LinkedAC{game_dict}(argc, argv);


    /* TEST - DEBUGGIN [1] : Print de argumentos */
    #ifdef ENABLE_DEBUG_ARGS_DICT
    std::cout << "GAME PARAMETERS:" << std::endl;
    for (const auto &i : game_dict) { std::cout << i.first << "=" << i.second << std::endl; }
    #endif
    /* ----------------------------------------- */


    /* CREATE OBJECTS */
    // Init lists & paddle
    cb::list<cb::physics::block_t*> ls_blocks;
    cb::list<cb::physics::ball_t*> ls_balls;
    cb::physics::paddle_t paddle({500.0f, 500.0f}, cb::physics::DefPaddleDim, {0.0f,0.0f}, cb::graph::color_t::Black);

    ls_blocks.push_back(new cb::physics::block_t(
                                    {100.0f,100.0f}, cb::physics::DefBlockDim, {0.0f,0.0f}, cb::graph::color_t::Red
                                 )
                       );
    ls_blocks.push_back(new cb::physics::block_t(
            {200.0f,200.0f}, cb::physics::DefBlockDim, {0.0f,0.0f}, cb::graph::color_t::Red
                        )
    );

    ls_balls.push_back(new cb::physics::ball_t(
            {500.0f,600.0f}, cb::physics::DefBallDim, {0.0f,-5.0f}, cb::graph::color_t::Green
                        )
    );

    /* CREATE WINDOWS */
    auto render = cb::graph::render_t::get_instance(
            {1200,800},
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
        /*
        for (const auto& i : ls_blocks) {
            i->move();
            i->draw();
        }
        for (const auto& i : ls_balls) {
            i->move();
            i->draw();
        }
        paddle.move();
        paddle.draw();
        */
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