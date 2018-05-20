cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

enable_testing()

add_subdirectory(src/graph)
add_subdirectory(examples)
add_subdirectory(tests)
