#include <stdio.h>
#include <stdlib.h>

#include "queue_int.h" 

// Utility function to initialize a queue
queue_int_t* newQueue(int size)
{
    queue_int_t *pt = NULL;
    pt = (queue_int_t*)malloc(sizeof(queue_int_t));
 
    pt->items = (int*)malloc(size * sizeof(int));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;
 
    return pt;
}
 
// Utility function to return the size of the queue
int size(queue_int_t *pt) {
    return pt->size;
}
 
// Utility function to check if the queue is empty or not
int isEmpty(queue_int_t *pt) {
    return !size(pt);
}
 
// Utility function to return the front element of the queue
int front(queue_int_t *pt)
{
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    return pt->items[pt->front];
}
 
// Utility function to add an element `x` to the queue
void enqueue(queue_int_t *pt, int x)
{
    if (size(pt) == pt->maxsize)
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Inserting %d\t", x);
 
    pt->rear = (pt->rear + 1) % pt->maxsize;    // circular queue
    pt->items[pt->rear] = x;
    pt->size++;
 
    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}
 
// Utility function to dequeue the front element
void dequeue(queue_int_t *pt)
{
    if (isEmpty(pt))    // front == rear
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\t", front(pt));
 
    pt->front = (pt->front + 1) % pt->maxsize;  // circular queue
    pt->size--;
 
    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}