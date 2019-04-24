cmake_minimum_required(VERSION 3.13)
project(AnimalsInTheZoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimalsInTheZoo main.cpp animal.cpp animal.h breedByEgg.cpp breedByEgg.h breedByLive.cpp breedByLive.h mammals.cpp mammals.h reptile.cpp reptile.h bird.cpp bird.h)