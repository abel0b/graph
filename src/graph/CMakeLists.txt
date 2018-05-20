set(HEADER_FILES graph.h traversal.h stack.h)
set(SOURCE_FILES graph.c traversal.c stack.c)

add_library(graph SHARED ${HEADER_FILES} ${SOURCE_FILES})
