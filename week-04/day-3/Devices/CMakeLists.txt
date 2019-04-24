cmake_minimum_required(VERSION 3.13)
project(Devices)

set(CMAKE_CXX_STANDARD 14)

add_executable(Devices main.cpp printer.cpp printer.h printer3d.cpp printer3d.h printer2d.cpp printer2d.h scanner.cpp scanner.h copier.cpp copier.h)