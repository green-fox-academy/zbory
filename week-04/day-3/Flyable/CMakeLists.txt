cmake_minimum_required(VERSION 3.13)
project(Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyable main.cpp Flyable.h vehicle.cpp vehicle.h Helicopter.cpp Helicopter.h bird.cpp bird.h)