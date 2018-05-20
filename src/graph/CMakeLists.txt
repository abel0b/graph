set(HEADER_FILES graph.h traversal.h stack.h queue.h)
set(SOURCE_FILES graph.c traversal.c stack.c queue.c)

add_library(graph SHARED ${HEADER_FILES} ${SOURCE_FILES})
