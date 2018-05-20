#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "graph.h"

void depth_first_search(struct Graph * graph, struct Vertex * vertex, void (*action)(struct Vertex *));

#endif
