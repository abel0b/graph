#include "graph/traversal.h"
#include "graph/stack.h"
#include "graph/queue.h"

void depth_first_search (struct Graph * graph, struct Vertex * vertex, void (*action)(struct Vertex *)) {
    struct Stack * stack = stack_make();
    stack_push(stack, vertex);

    struct Vertex * v;
    int visited[graph->nv];
    for (int i = 0; i < graph->nv; i++) {
        visited[i] = 0;
    }
    while (!stack_is_empty(stack)) {
        v = stack_pop(stack);
        visited[v->uid] = 1;
        action(v);
        struct VertexList * adj = graph->adj[v->uid];
        while (adj->size > 0) {
            if (!visited[adj->head->uid])
                stack_push(stack, adj->head);
            adj = adj->next;
        }
    }

    stack_delete(stack);
}

void breadth_first_search (struct Graph * graph, struct Vertex * vertex, void (*action)(struct Vertex *)) {
    struct Queue * queue = queue_make();
    queue_push(queue, vertex);

    struct Vertex * v;
    int visited[graph->nv];
    for (int i = 0; i < graph->nv; i++) {
        visited[i] = 0;
    }
    while (!queue_is_empty(queue)) {
        v = queue_pop(queue);
        visited[v->uid] = 1;
        action(v);
        struct VertexList * adj = graph->adj[v->uid];
        while (adj->size > 0) {
            if (!visited[adj->head->uid])
                queue_push(queue, adj->head);
            adj = adj->next;
        }
    }

    queue_delete(queue);
}
