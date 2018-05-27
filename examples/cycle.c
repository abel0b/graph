#include <stdlib.h>
#include <stdio.h>

#include "graph/graph.h"
#include "graph/cycle.h"

int main() {
    printf("cycle detection examples\n");

    // GRAPH 1
    struct Graph * graph1 = make_graph();
    struct Vertex * A = make_vertex("A");
    struct Vertex * B = make_vertex("B");
    struct Vertex * C = make_vertex("C");
    struct Vertex * D = make_vertex("D");
    add_vertex(graph1, A);
    add_vertex(graph1, B);
    add_vertex(graph1, C);
    add_vertex(graph1, D);
    add_edge(graph1, A, B);
    add_edge(graph1, B, C);
    add_edge(graph1, C, A);
    add_edge(graph1, A, D);

    // GRAPH 2
    struct Graph * graph2 = make_graph();
    struct Vertex * E = make_vertex("E");
    struct Vertex * F = make_vertex("F");
    struct Vertex * G = make_vertex("G");
    struct Vertex * H = make_vertex("H");
    add_vertex(graph2, E);
    add_vertex(graph2, F);
    add_vertex(graph2, G);
    add_vertex(graph2, H);
    add_edge(graph2, E, F);
    add_edge(graph2, F, G);
    add_edge(graph2, E, H);

    printf("graph1 is cyclic ? ");
    if (is_cyclic(graph1, A))
        printf("true\n");
    else
        printf("false\n");

    printf("graph2 is cyclic ? ");
    if (is_cyclic(graph2, E))
        printf("true\n");
    else
        printf("false\n");

    delete_graph(graph1);
    delete_graph(graph2);

    return EXIT_SUCCESS;
}
