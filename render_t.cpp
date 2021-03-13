//
// Created by RodrigoSalad on 11/03/2021.
//

#include "render_t.h"

namespace cb::graph{
    // Constructor Privado
    render_t::render_t(const cb::bound_t &bound, const cb::string_t &title):
            platform_render {cb::graph::get_render_size(bound), title}
            {}

    // Instance Getter
    render_t *render_t::get_instance(const cb::bound_t &bound, const cb::string_t &title) {
        if (!instance) instance = new render_t(bound, title);
        return instance;
    }

    // Getters
    cb::bound_t render_t::get_limit() {
        auto& canvas = get_instance()->platform_render;
        return {canvas.getSize().x, canvas.getSize().y};
    }

    platform_render_t &render_t::get_platform_render() {
        return platform_render;
    }

    // Custom Draw Methods
    void render_t::draw_rectangle(cb::position_t p, cb::dimension_t d, color_t c) {
        sf::RectangleShape shape;
        shape.setSize({d.width,d.height});
        shape.setFillColor(c);
        shape.setPosition(p.x,p.y);
        auto& canvas = get_instance()->platform_render;
        canvas.draw(shape);
    }

    void render_t::draw_ellipse(cb::position_t p, cb::dimension_t d, color_t c) {
        sf::CircleShape shape;
        shape.setRadius(1);
        shape.setFillColor(c);
        shape.setScale({d.width/2, d.height/2});
        shape.setPosition(p.x,p.y);
        auto& canvas = get_instance()->platform_render;
        canvas.draw(shape);
    }
}



