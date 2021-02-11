#include <stdio.h>

#define MAX 5

struct stack
{
    int array[MAX];
    int top;
};

void init_stack(struct stack *s)
{
    // Accessing variable that points to top of stack and setting to -1 indicating stack is empty
    s->top = -1;
}

void push(struct stack *s, int item)
{
    // Check if stack is full
    if (s->top == MAX - 1)
    {
        printf("Stack is full. Couldn't push '%d' onto stack\n", item);
        return;
    }
    // Alter where variable pointing to top points to if stack is not full
    s->top++;
    // Place item onto stack
    s->array[s->top] = item;
}

void *pop(struct stack *s)
{
    // Temp storage
    int *data;
    // Check if stack is empty, return null if it is so user can check for null to see whether stack is empty or not
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    data = &s->array[s->top];
    s->top--;
    return data;
}

int main()
{
    struct stack s;

    init_stack(&s);

    push(&s, 11);
    push(&s, 23);
    push(&s, -8);
    push(&s, 16);
    push(&s, 27);
    push(&s, 14);
    push(&s, 20);
    push(&s, 39);
    push(&s, 2);
    push(&s, 15);

    push(&s, 7);

    int *i = NULL;

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    i = pop(&s);
    if (i)
    {
        printf("Item popped %d\n", *i);
    }

    return 0;
}