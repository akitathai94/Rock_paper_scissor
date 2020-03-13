cmake_minimum_required(VERSION 3.13)
project(testProgram)

set(CMAKE_CXX_STANDARD 14)

add_executable(testProgram PlayerClassTester.cpp Player.cpp)
