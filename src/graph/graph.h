#ifndef GRAPH_H
#define GRAPH_H

#define MAXVERTEXSTR 16

struct Vertex {
    int uid;
    char value[MAXVERTEXSTR];
};

struct Edge {
    struct Vertex * src;
    struct Vertex * dest;
};

struct VertexList {
    struct Vertex * head;
    struct VertexList * next;
    int size;
};

struct Graph {
    struct Vertex * * vertices;
    struct VertexList * * adj;
    int nv, ne;
};

struct Graph * make_graph();

void delete_graph (struct Graph * graph);

struct Vertex * make_vertex (char * value);

struct VertexList * make_vertex_list();

void delete_vertex_list(struct VertexList * vertex_list);

void insert_head_vertex_list(struct VertexList * vertex_list, struct Vertex * vertex);

void add_vertex(struct Graph * graph, struct Vertex * vertex);

void add_edge(struct Graph * graph, struct Vertex * v1, struct Vertex * v2);

void display_vertex_value(struct Vertex * vertex);

#endif
