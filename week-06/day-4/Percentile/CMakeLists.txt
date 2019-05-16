cmake_minimum_required(VERSION 3.13)
project(Percentile C)

set(CMAKE_C_STANDARD 11)

add_executable(Percentile main.c matrix.c matrix.h)