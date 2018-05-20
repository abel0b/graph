#ifndef STACK_H
#define STACK_H

struct Stack {
    int size;
    void * value;
    struct Stack * next;
};

struct Stack * stack_make();

void stack_push(struct Stack * stack, void * value);

void * stack_pop(struct Stack * stack);

void stack_delete(struct Stack * stack);

int stack_is_empty(struct Stack * stack);

#endif
