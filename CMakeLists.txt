cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -std=gnu99")

enable_testing()

add_subdirectory(src/graph)
add_subdirectory(examples)
add_subdirectory(tests)
