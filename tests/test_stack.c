#include <stdio.h>
#include "../lib/stack_int.h"

int main()
{
    // create a stack of capacity 5
    stack_int_t *pt = newStack(5);
 
    push(pt, 1);
    push(pt, 2);
    push(pt, 3);
 
    printf("The top element is %d\n", peek(pt));
    printf("The stack size is %d\n", size(pt));
 
    pop(pt);
    pop(pt);
    pop(pt);
 
    if (isEmpty(pt)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}

