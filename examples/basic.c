#include <stdlib.h>
#include <stdio.h>

#include "graph/graph.h"

int main() {
    printf("basic example\n");
    struct Graph * graph = make_graph();


    delete_graph(graph);

    return EXIT_SUCCESS;
}
