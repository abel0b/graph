add_executable(traversal traversal.c)
target_link_libraries(traversal graph)

add_executable(cycle cycle.c)
target_link_libraries(cycle graph)
