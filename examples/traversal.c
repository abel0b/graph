#include <stdlib.h>
#include <stdio.h>

#include "graph/graph.h"
#include "graph/traversal.h"

int main() {
    printf("graph traversal example\n");
    struct Graph * graph = make_graph();

    struct Vertex * A = make_vertex("A");
    struct Vertex * B = make_vertex("B");
    struct Vertex * C = make_vertex("C");
    struct Vertex * D = make_vertex("D");

    add_vertex(graph, A);
    add_vertex(graph, B);
    add_vertex(graph, C);
    add_vertex(graph, D);

    add_edge(graph, A, B);
    add_edge(graph, B, C);
    add_edge(graph, C, A);
    add_edge(graph, A, D);

    printf("depth-first search:\n");
    depth_first_search(graph, A, display_vertex_value);

    printf("breadth-first search:\n");
    breadth_first_search(graph, A, display_vertex_value);

    delete_graph(graph);

    return EXIT_SUCCESS;
}
