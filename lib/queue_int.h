#ifndef QUEUE_INT_H
#define QUEUE_INT_H

typedef struct queue_int_s {
    int *items;     // array to store queue elements
    int maxsize;    // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int size;       // current capacity of the queue
} queue_int_t;

queue_int_t* newQueue(int);
int size(queue_int_t *);
int isEmpty(queue_int_t *);
int front(queue_int_t *);
void enqueue(queue_int_t *, int);
void dequeue(queue_int_t *);

#endif