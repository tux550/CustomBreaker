//
// Created by RodrigoSalad on 11/03/2021.
//

#ifndef CUSTOMBREAKER_COMMON_TYPES_H
#define CUSTOMBREAKER_COMMON_TYPES_H

#include <iostream>
#include <unordered_map>
#include <string>

/* MAIN NAMESPACE TYPES */
namespace cb{
    // Basic
    using string_t = std::string;
    using char_t = char;
    using size_t = std::size_t;
    using length_t = float;
    using speed_t = float;
    using limit_t = std::size_t;

    // Structs
    struct position_t{
        length_t x;
        length_t y;
    };
    struct dimension_t{
        length_t width;
        length_t height;
    };
    struct velocity_t{
        speed_t vx;
        speed_t vy;
    };
    struct bound_t{
        limit_t lim_x;
        limit_t lim_y;
    };
    struct padding_t{
        length_t x;
        length_t y;
    };

    // Containers
    template <typename T, typename U>
    using dict = std::unordered_map<T,U>;
    template <typename T>
    using list = std::list<T>;
    template <typename T>
    using vector = std::vector<T>;

    // Error template
    // Recursive case
    template <size_t exit_code, typename First, typename ... Others>
    void rec_error_exit(First msg, Others ... params){
        std::cout << msg;
        rec_error_exit<exit_code>(params...);
    }
    //Base case
    template <size_t exit_code>
    void rec_error_exit(){
        std::cout << std::endl;
        std::exit(exit_code);
    }
    // Call function
    template <size_t exit_code, typename Str, typename ... Others>
    void error_exit(Str msg, Others ... params){
        std::cout << "ERROR: " << msg;
        rec_error_exit<exit_code>(params...);
    }

}

#endif //CUSTOMBREAKER_COMMON_TYPES_H
