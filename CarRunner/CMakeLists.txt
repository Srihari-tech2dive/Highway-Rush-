cmake_minimum_required(VERSION 3.20)

project(CarRunner C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

add_executable(CarRunner
    src/core/main.c
    src/core/Engine.c
    src/core/Application.c
    src/core/Time.c
    src/core/Window.c
    src/core/Input.c
    src/core/Renderer.c

    src/game/Player.c
)

target_include_directories(CarRunner
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(CarRunner
    PRIVATE
        PkgConfig::SDL3
)
