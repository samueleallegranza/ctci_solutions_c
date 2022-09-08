#ifndef STACK_INT_H
#define STACK_INT_H

typedef struct stack_int_s{
    int capacity;
    int top;
    int * items;
} stack_int_t;

stack_int_t * newStack(int);
int size(stack_int_t *);
int isEmpty(stack_int_t *);
int isFull(stack_int_t *);
void push(stack_int_t *, int);
int peek(stack_int_t *);
int pop(stack_int_t *);

#endif
