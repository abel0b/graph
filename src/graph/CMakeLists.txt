set(HEADER_FILES graph.h traversal.h stack.h queue.h cycle.h)
set(SOURCE_FILES graph.c traversal.c stack.c queue.c cycle.c)

add_library(graph SHARED ${HEADER_FILES} ${SOURCE_FILES})
