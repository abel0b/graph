#include <stdlib.h>
#include <stdio.h>

#include "graph/graph.h"
#include "graph/traversal.h"

int main() {
    printf("basic example\n");
    struct Graph * graph = make_graph();

    struct Vertex * A = make_vertex("A");
    struct Vertex * B = make_vertex("B");
    struct Vertex * C = make_vertex("C");


    add_vertex(graph, A);
    add_vertex(graph, B);
    add_vertex(graph, C);

    add_edge(graph, A, B);
    add_edge(graph, B, C);
    add_edge(graph, C, A);

    depth_first_search(graph, A, display_vertex_value);

    delete_graph(graph);

    return EXIT_SUCCESS;
}
