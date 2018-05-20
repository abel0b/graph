#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

struct Queue * queue_make() {
    struct Queue * new_queue = malloc (sizeof (struct Queue));
    new_queue->size = 0;
    return new_queue;
}

void queue_delete(struct Queue * queue) {
    if (queue->size > 0) {
        struct QueueItem * node = queue->head;

        while (node->next != NULL) {
            struct QueueItem * tmp = node;
            node = node->next;
            free (tmp);
        }
        free (node);
    }
    free (queue);
}

void queue_push(struct Queue * queue, void * value) {
    struct QueueItem * new_item = malloc (sizeof (struct QueueItem));

    new_item->next = NULL;
    new_item->value = value;
    if (queue->size > 0) {
        new_item->prev = queue->tail;
        queue->tail->next = new_item;
        queue->tail = new_item;
    }
    else {
        queue->head = queue->tail = new_item;
        new_item->prev = new_item->next = NULL;
    }
    queue->size ++;
}

void * queue_pop(struct Queue * queue) {
    if (queue->size <= 0) {
        printf("EEMPTYQUEUE\n");
        exit(1);
    }
    struct QueueItem * head = queue->head;
    void * value = head->value;

    if (queue->size > 1) {
        queue->head = queue->head->next;
        queue->head->prev = NULL;
    }
    free(head);

    queue->size --;
    return value;
}

int queue_is_empty(struct Queue * queue) {
    return queue->size == 0;
}
