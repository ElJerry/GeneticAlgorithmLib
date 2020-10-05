cmake_minimum_required(VERSION 3.14)
project(GeneticAlgorithmLib)

set(CMAKE_CXX_STANDARD 14)
include(ctest)

include_directories(include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library(GeneticAlgorithmLib
        src/GeneticAlgorithmLib.cpp
        src/GeneticAlgorithm.cpp
        src/Individual.cpp)

add_subdirectory(tests)
add_subdirectory(examples)