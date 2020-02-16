cmake_minimum_required(VERSION 3.14)
project(GeneticAlgorithmLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(GeneticAlgorithmLib
        src/GeneticAlgorithmLib.cpp
        src/MemoryManager.cpp)


add_subdirectory(tests)