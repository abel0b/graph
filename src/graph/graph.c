#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

struct Graph * make_graph () {
    struct Graph * new_graph = malloc (sizeof (struct Graph));
    if (new_graph == NULL) {
        printf("EMEMORY\n");
        exit(1);
    }
    return new_graph;
}

void delete_graph (struct Graph * graph) {
    free (graph);
}

struct Vertex * make_vertex (int value) {
    struct Vertex * new_vertex = malloc (sizeof (struct Graph));
    new_vertex->value = value;
    if (new_vertex == NULL) {
        printf ("EMEMORY\n");
        exit (1);
    }
    return new_vertex;
}

// void add_vertex(struct Graph * graph);
//
// void add_edge(struct Graph * graph, struct Vertex * v1; struct Vertex * v2);
