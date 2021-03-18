#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* Quick sort goes something like this:
1. Pick element from data set. This is the pivot.
2. Perform a partitioning operation: Reorder the dataset so that elements greater than the pivot are to one side, and items less than the pivot are to the other side. 
Equal values can be on either side of the pivot.
3. Repeat step 2, applying the partition operation to each separate collection formed respectively from the values smaller than, and greater than the pivot.
*/

void quicksort(int *, int, int);
int partition(int *, int, int);
void populateArray(int *);

int main(void)
{
    int i;
    int data[SIZE];
    populateArray(data);

    printf("Quicksort\n");
    printf("Before Sorting...\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    quicksort(data, 0, SIZE - 1);

    printf(" After sorting ...\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int data[], int lower, int upper)
{
    int pivot;
    if (upper > lower)
    {
        pivot = partition(data, lower, upper);
        quicksort(data, lower, pivot - 1);
        quicksort(data, pivot + 1, upper);
    }
}

int partition(int data[], int lower, int upper)
{
    int pivot = data[upper];
    int idx = lower - 1;
    int temp;

    for (int j = lower; j < upper; j++)
    {
        if (data[j] <= pivot)
        {
            idx++;
            temp = data[idx];
            data[idx] = data[j];
            data[j] = temp;
        }
    }

    temp = data[idx + 1];
    data[idx + 1] = data[upper];
    data[upper] = temp;

    return idx + 1;
}
void populateArray(int *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        // Generate random int between 0 & 2999
        int num = rand() % 3000;
        arr[i] = num;
    }
}