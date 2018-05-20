add_test(NAME memcheck_basic_example
    COMMAND valgrind --leak-check=full --error-exitcode=1 ./examples/basic
    DEPENDS basic
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
