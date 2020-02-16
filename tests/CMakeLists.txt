project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test testMain.cpp)

include_directories(../include/public)

target_link_libraries(test GeneticAlgorithmLib)