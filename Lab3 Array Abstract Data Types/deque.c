#include <stdio.h>

#define MAX 5

void addToFront(int *arr, int item, int *pfront, int *prear)
{
    int i, j, c;
    // Currently not working as intended - throw small error but doesn't seem to impact final output //

    // Check if deque is full
    if (*prear == MAX - 1)
    {
        printf("Deque is full\n");
        return;
    }
    // Check position at front of deque
    // Move pfront to rear if it is at the start of the deque
    // Else decrease front by 1
    if (*pfront == -1)
    {
        *pfront = *prear = 0;
        arr[*pfront] = item;
        return;
    }

    if (*prear != MAX - 1)
    {
        c = count(arr);
        j = *prear + 1;
        for (i = 1; i <= c; i++)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = item;
        *pfront = j;
        (*prear)++;
    }
    else
    {
        (*pfront)--;
        arr[*pfront] = item;
    }
}

void addToRear(int *arr, int item, int *pfront, int *prear)
{
    // Check if deque is full
    if (*prear == MAX - 1)
    {
        printf("Deque is full\n");
        return;
    }
    else
    {
        // Increment rear of queue
        (*prear)++;
        // Add item to rear of queue
        printf("Adding %d to the tail\n", item);
        arr[*prear] = item;
        // Change front indicator to 0 to show it is no longer empty
        if (*pfront == -1)
            *pfront = 0;
    }
}

int deleteFromFront(int *arr, int *pfront, int *prear)
{
    int item;
    // If the front of the array is -1 then Deque is empty
    if (*pfront == -1)
    {
        printf("Deque is empty\n");
        return 0;
    }

    // Set item to first item in Deque to be deleted
    item = arr[*pfront];
    printf("Deleting %d from the head\n", item);
    arr[*pfront] = 0;

    if (*pfront == *prear)
        *pfront = *prear = -1;
    else
        (*pfront)++;

    return item;
}

int deleteFromRear(int *arr, int *pfront, int *prear)
{
    int item;
    // If the front of the array is -1 then Deque is empty
    if (*pfront == -1)
    {
        printf("Deque is empty\n");
        return 0;
    }

    // Set item to last item in Deque to be deleted
    item = arr[*prear];
    printf("Deleting %d from the tail\n", item);
    // Set last item in Deque to 0
    arr[*prear] = 0;

    (*prear)--;

    if (*prear == -1)
        *pfront = -1;

    return item;
}

void display(int *arr)
{
    // Display contents of Deque from front to back
    int i;
    printf("\nFront:  ");
    for (i = 0; i < MAX; i++)
        printf("  %d", arr[i]);
    printf("  :Back\n");
}

int count(int *arr)
{
    // Count number of items present in the Deque
    int c = 0, i;

    for (i = 0; i < MAX; i++)
    {
        if (arr[i] != 0)
            c++;
    }
    return c;
}

int main()
{
    int arr[MAX];
    int front = -1, rear = -1;

    addToFront(arr, 29, &front, &rear);
    addToRear(arr, 7, &front, &rear);
    addToRear(arr, 2, &front, &rear);
    addToFront(arr, 54, &front, &rear);
    addToFront(arr, -10, &front, &rear);
    //addToRear(arr, 22, &front, &rear);
    display(arr);
    int i;
    for (int idx = 0; idx < MAX; idx++)
    {
        i = deleteFromFront(arr, &front, &rear);
        printf("Received Deleted item: %d\n", i);
    }

    addToFront(arr, 2, &front, &rear);
    addToRear(arr, 9, &front, &rear);
    addToRear(arr, 2, &front, &rear);
    addToFront(arr, 4, &front, &rear);
    addToFront(arr, -50, &front, &rear);

    display(arr);

    return 0;
}
