#include "graph/cycle.h"
#include "graph/stack.h"

bool is_cyclic (struct Graph * graph, struct Vertex * vertex) {
    struct Stack * stack = stack_make();
    stack_push(stack, vertex);

    struct Vertex * v;
    int visited[graph->nv];
    for (int i = 0; i < graph->nv; i++)
        visited[i] = 0;
    while (!stack_is_empty(stack)) {
        v = stack_pop(stack);
        visited[v->uid] = 1;
        struct VertexList * adj = graph->adj[v->uid];
        while (adj->size > 0) {
            if (!visited[adj->head->uid])
                stack_push(stack, adj->head);
            else {
                stack_delete(stack);
                return true;
            }
            adj = adj->next;
        }
    }

    stack_delete(stack);
    return false;
}
