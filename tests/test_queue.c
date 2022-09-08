#include <stdio.h>
#include "../lib/queue_int.h"

int main()
{
    queue_int_t *pt = newQueue(5);
 
    enqueue(pt, 1);
    enqueue(pt, 2);
    enqueue(pt, 3);
    enqueue(pt, 4);
 
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
 
    enqueue(pt, 5);
    enqueue(pt, 6);
 
    printf("size = %d\n", size(pt));
 
    if (isEmpty(pt)) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }
 
    return 0;
}