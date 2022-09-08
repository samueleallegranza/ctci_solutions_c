#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"

// Utility function to initialize the stack
stack_int_t * newStack(int capacity) {
    stack_int_t * stack = (stack_int_t *)malloc(sizeof(stack_int_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int *)malloc(sizeof(int) * capacity);
}

// Utility function to return the size of the stack
int size(stack_int_t * stack) {
    return stack->top + 1;
}

// Utility function to check if the stack is empty or not
int isEmpty(stack_int_t * stack) {
    return stack->top == -1;                                // or return size(pt) == 0;
}

// Utility function to check if the stack is full or not
int isFull(stack_int_t * stack) {
    return stack->top == stack->capacity -1;                // or return size(pt) == pt->maxsize;
}

// Utility function to add an element `x` to the stack
void push(stack_int_t * stack, int x) {
    // check if the stack is already full. Then inserting an element would lead to stack overflow
    if(isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }

    stack->items[++stack->top] = x;
}

// Utility function to return the top element of the stack
int peek(stack_int_t * stack) {
    if(isEmpty(stack)) {
        printf("Stack empty\n");
        exit(EXIT_FAILURE);
    } else
        return stack->items[stack->top];
}

// Utility function to pop a top element from the stack
int pop(stack_int_t * stack) {
    if(isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return stack->items[stack->top--];
    }
}