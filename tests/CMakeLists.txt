add_test(NAME memcheck_basic_example
    COMMAND valgrind --leak-check=full --error-exitcode=1 ./examples/traversal
    DEPENDS traversal
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
