#ifndef GRAPH_H
#define GRAPH_H

struct Vertex {
    int uid;
    int value;
};

struct Edge {
    struct Vertex * src;
    struct Vertex * dest;
};

struct Graph {
    struct Vertex * * adj;
    int nv, ne;
};

struct Graph * make_graph();

void delete_graph (struct Graph * graph);

struct Vertex * make_vertex(int value);

void add_vertex(struct Graph * graph);

void add_edge(struct Graph * graph, struct Vertex * v1, struct Vertex * v2);

#endif
