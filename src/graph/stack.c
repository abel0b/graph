#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

struct Stack * stack_make() {
    struct Stack * new_stack = malloc (sizeof (struct Stack));
    new_stack->size = 0;
    return new_stack;
}

void stack_delete(struct Stack * stack) {
    struct Stack * node = stack;
    while (node->size != 0) {
        struct Stack * tmp = node;
        node = node->next;
        free (tmp);
    }
    free (node);
}

void stack_push(struct Stack * stack, void * value) {
    struct Stack * new_next = stack_make();
    new_next->next = stack->next;
    new_next->size = stack->size;
    new_next->value = stack->value;
    stack->next = new_next;
    stack->size ++;
    stack->value = value;
}

void * stack_pop(struct Stack * stack) {
    if (stack->size <= 0) {
        printf("EEMPTYSTACK\n");
        exit(1);
    }
    void * head = stack->value;
    stack->size --;
    if (stack->size >= 0) {
        struct Stack * tmp = stack->next;
        stack->value = tmp->value;
        stack->next = tmp->next;
        free(tmp);
    }

    return head;
}

int stack_is_empty(struct Stack * stack) {
    return stack->size == 0;
}
