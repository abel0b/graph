#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Graph * make_graph () {
    struct Graph * new_graph = malloc (sizeof (struct Graph));
    if (new_graph == NULL) {
        printf("EMEMORY\n");
        exit(1);
    }
    new_graph->adj = new_graph->vertices = NULL;
    new_graph->nv = new_graph->ne = 0;
    return new_graph;
}

void delete_graph (struct Graph * graph) {
    for (int i = 0; i < graph->nv; i++) {
        delete_vertex_list (graph->adj[i]);
        free (graph->vertices[i]);
    }
    if (graph->nv > 0) {
        free (graph->adj);
        free (graph->vertices);
    }
    free (graph);
}

struct Vertex * make_vertex (char * value) {
    struct Vertex * new_vertex = malloc (sizeof (struct Graph));
    strcpy(new_vertex->value, value);
    if (new_vertex == NULL) {
        printf ("EMEMORY\n");
        exit (1);
    }
    new_vertex->uid = 0;
    return new_vertex;
}

struct VertexList * make_vertex_list() {
    struct VertexList * new_vertex_list = malloc (sizeof (struct VertexList));
    new_vertex_list->next = NULL;
    new_vertex_list->size = 0;
    return new_vertex_list;
}

void delete_vertex_list(struct VertexList * vertex_list) {
    struct VertexList * node = vertex_list;
    while (node->size != 0) {
        struct VertexList * tmp = node;
        node = node->next;
        free (tmp);
    }
    free (node);
}

void insert_head_vertex_list(struct VertexList * vertex_list, struct Vertex * vertex) {
    struct VertexList * new_vertex_list = malloc (sizeof (struct VertexList));
    new_vertex_list->head = vertex_list->head;
    new_vertex_list->next = vertex_list->next;
    new_vertex_list->size = vertex_list->size;
    vertex_list->head = vertex;
    vertex_list->next = new_vertex_list;
    vertex_list->size ++;
}

void add_vertex(struct Graph * graph, struct Vertex * vertex) {
    vertex->uid = graph->nv;
    graph->nv ++;
    graph->vertices = realloc (graph->vertices, graph->nv * sizeof (struct Vertex *));
    graph->adj = realloc (graph->adj, graph->nv * sizeof (struct VertexList *));
    graph->adj[graph->nv - 1] = make_vertex_list ();
    graph->vertices[graph->nv - 1] = vertex;
}

void add_edge(struct Graph * graph, struct Vertex * v1, struct Vertex * v2) {
    insert_head_vertex_list(graph->adj[v1->uid], v2);
}

void display_vertex_value(struct Vertex * vertex) {
    printf("%s\n", vertex->value);
}
