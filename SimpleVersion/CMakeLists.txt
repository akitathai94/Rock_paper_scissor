cmake_minimum_required(VERSION 3.13)
project(testProgram)

set(CMAKE_CXX_STANDARD 11)

add_executable(testProgram RockPaperScissor.cpp Player.cpp Game.cpp Round.cpp MLChooser.cpp)
