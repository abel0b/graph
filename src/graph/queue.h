#ifndef QUEUE_H
#define QUEUE_H

struct QueueItem {
    void * value;
    struct QueueItem * next;
    struct QueueItem * prev;
};

struct Queue {
    int size;
    struct QueueItem * head;
    struct QueueItem * tail;
};

struct Queue * queue_make();

void queue_push(struct Queue * queue, void * value);

void * queue_pop(struct Queue * queue);

void queue_delete(struct Queue * queue);

int queue_is_empty(struct Queue * queue);

#endif
