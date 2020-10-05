project(test)

set(CMAKE_CXX_STANDARD 14)

include_directories(
    ../include/public
    ../Dependencies/Testing
)

set(UNIT_TEST_LIST
  Individual)
 
foreach(NAME IN LISTS UNIT_TEST_LIST)
  list(APPEND UNIT_TEST_SOURCE_LIST
    ${NAME}.test.cpp)
endforeach()
 
set(TARGET_NAME tests)
 
add_executable(${TARGET_NAME}
  testMain.cpp
  ${UNIT_TEST_SOURCE_LIST})
  
add_dependencies(${TARGET_NAME} GeneticAlgorithmLib)

target_link_libraries(${TARGET_NAME} GeneticAlgorithmLib)

add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})