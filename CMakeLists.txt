﻿cmake_minimum_required(VERSION 3.13)
project(CustomBreaker)

# Archivos del Projecto
set(PROJECT_SOURCE
        main.cpp
        args_interpreter.cpp args_interpreter.h common_types.h platform_types.h render_t.cpp render_t.h debug_config.h object_t.cpp object_t.h block_t.cpp block_t.h ball_t.cpp ball_t.h physics.h paddle_t.cpp paddle_t.h utility.cpp utility.h level_loader.cpp level_loader.h direction_input.cpp direction_input.h)

# C++ Standard se sugiere 11 o 14
set(CMAKE_CXX_STANDARD 17)

set(SFML_ROOT "~/DevLibraries/SFML/32bit/SFML-2.5.1")

set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

if (APPLE)
    set(SFML_DIR "${SFML_ROOT}/Frameworks/SFML.framework/Resources/CMake")
else()
    set(SFML_DIR "${SFML_ROOT}/lib/CMake/SFML")
endif()

link_directories(${SFML_LIBRARY_DIR})
include_directories(${SFML_INCLUDE_DIR})

# Instrucciones para generar el ejecutable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})

find_package(SFML 2.5.1
        COMPONENTS
            system
            window
            graphics
        REQUIRED)

target_link_libraries (${PROJECT_NAME}
        sfml-system
        sfml-window
        sfml-graphics
        )
