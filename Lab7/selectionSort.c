#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

void populateArray(int *);

int main(void)
{
    int arr[SIZE];
    int idx, target, tmp;

    populateArray(arr);

    printf("Selection Sort\n");
    printf("Before Sorting: \n");
    for (idx = 0; idx < SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    // The Selection Sort
    for (idx = 0; idx < SIZE - 1; idx++)
    {
        for (target = idx + 1; target < SIZE; target++)
        {
            if (arr[idx] > arr[target])
            {
                tmp = arr[idx];
                arr[idx] = arr[target];
                arr[target] = tmp;
                //printf("Inner Loop After iteration %d: %d\n", idx, arr[idx]);
                //printf("Outer Loop After iteration %d: %d\n", idx, arr[target]);
            }
        }
    }

    printf("After Sorting: \n");
    for (idx = 0; idx < SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    return 0;
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