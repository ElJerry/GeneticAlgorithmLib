project(examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(examples
        examples.cpp
        OneMaxProblem.cpp
        Knapsack.cpp
    )

include_directories(${CMAKE_SOURCE_DIR}/include/public)
add_dependencies(examples GeneticAlgorithmLib)
target_link_libraries(examples GeneticAlgorithmLib)