cmake_minimum_required(VERSION 3.13)
project(InstrumentsToStringedInstruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(InstrumentsToStringedInstruments main.cpp Instrument.cpp Instrument.h StringedInstrument.cpp StringedInstrument.h ElectricGuitar.cpp ElectricGuitar.h BassGuitar.cpp BassGuitar.h Violin.cpp Violin.h)