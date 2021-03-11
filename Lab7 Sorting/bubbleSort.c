#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

void populateArray(int *);

int main(void)
{
    int arr[SIZE];
    int idx, target, tmp;

    populateArray(arr);

    printf("Bubble Sort\n");
    printf("Before Sorting: \n");
    for (idx = 0; idx < SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    // The Bubble Sort
    for (idx = 0; idx < SIZE - 1; idx++)
    {
        for (target = 0; target < (SIZE - 1) - idx; target++)
        {
            if (arr[target] > arr[target + 1])
            {
                tmp = arr[target];
                //printf("Sorting.. %d\n", tmp);
                arr[target] = arr[target + 1];
                arr[target + 1] = tmp;
                //printf("Sorting.. %d\n", arr[target]);
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