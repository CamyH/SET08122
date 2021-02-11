#include <stdio.h>

#define MAX 5

void enqueue(int *arr, int item, int *pfront, int *prear)
{
    // Check if queue is full
    if (*prear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        printf("Enqueuing: %d\n", item);
        // Increment rear of queue
        (*prear)++;
        // Add item to rear of queue
        arr[*prear] = item;
        // Change front indicator to 0 to show it is no longer empty
        if (*pfront == -1)
            *pfront = 0;
    }
}

int isEmpty(int *pfront)
{
    // Check if front is -1
    // If it is queue is empty
    if (*pfront == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else
        return 0;
}

int dequeue(int *arr, int *pfront, int *prear)
{
    int data = arr[*pfront];
    printf("Dequeuing: %d\n", data);

    arr[*pfront] = 0;
    // Check if both front + rear pointers are 0
    // If so then set them both to -1 because the queue is now empty
    // Else increment front pointer by 1 so it points to the next item in the queue
    if (*pfront == *prear)
        *pfront = *prear = -1;
    else
        (*pfront)++;

    return data;
}

int main()
{
    int arr[MAX];
    int front = -1, rear = -1;

    enqueue(arr, 23, &front, &rear);
    enqueue(arr, 9, &front, &rear);
    enqueue(arr, 11, &front, &rear);
    enqueue(arr, -10, &front, &rear);
    enqueue(arr, 25, &front, &rear);
    enqueue(arr, 16, &front, &rear);
    enqueue(arr, 17, &front, &rear);
    enqueue(arr, 22, &front, &rear);
    enqueue(arr, 19, &front, &rear);
    enqueue(arr, 30, &front, &rear);
    enqueue(arr, 32, &front, &rear);

    int i;
    for (int idx = 0; idx < MAX; idx++)
    {
        i = dequeue(arr, &front, &rear);
        printf("Received Dequeued item: %d\n", i);
    }

    return 0;
}