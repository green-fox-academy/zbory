cmake_minimum_required(VERSION 3.13)
project(Farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Farm main.cpp Animal.cpp Animal.h Farm.cpp Farm.h)