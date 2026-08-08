cmake_minimum_required(VERSION 3.20)

project(CarRunner C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(CarRunner
    src/core/main.c
    src/core/Engine.c
    src/core/Application.c
    src/core/Time.c
)

target_include_directories(CarRunner
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
