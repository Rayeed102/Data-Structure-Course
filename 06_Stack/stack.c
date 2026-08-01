#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *items;
    int top;
    int capacity;
} Stack;

Stack* createStack(int initialCapacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->capacity = initialCapacity;
    stack->top = -1;
    stack->items = (int *)malloc(stack->capacity * sizeof(int));

    if (!stack->items) {
        free(stack);
        return NULL;
    }

    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        int newCapacity = stack->capacity * 2;
        int *newItems = (int *)realloc(stack->items, newCapacity * sizeof(int));
        if (!newItems) return;

        stack->items = newItems;
        stack->capacity = newCapacity;
    }

    stack->items[++(stack->top)] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->items[(stack->top)--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->items[stack->top];
}

void destroyStack(Stack *stack) {
    if (stack) {
        free(stack->items);
        free(stack);
    }
}

int main() {
    Stack *myStack = createStack(2);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printf("Top: %d\n", peek(myStack));
    printf("Popped: %d\n", pop(myStack));
    printf("Popped: %d\n", pop(myStack));

    destroyStack(myStack);
    return 0;
}