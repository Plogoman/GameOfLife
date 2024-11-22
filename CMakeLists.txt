cmake_minimum_required(VERSION 3.29)
project(GameOfLife)

find_package(raylib CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameOfLife main.cpp
        Game.cpp
        Game.h
        GameOfLife.cpp
        GameOfLife.h
)

target_link_libraries(GameOfLife PRIVATE raylib)