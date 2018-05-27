add_test(NAME memcheck_traversal_examples
    COMMAND valgrind --leak-check=full --error-exitcode=1 ./examples/traversal
    DEPENDS traversal
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_test(NAME memcheck_cycle_examples
    COMMAND valgrind --leak-check=full --error-exitcode=1 ./examples/cycle
    DEPENDS cycle
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
