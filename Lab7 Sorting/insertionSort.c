#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

void populateArray(int *);

int main(void)
{
    int arr[SIZE];
    int idx, shift, cmp, tmp;

    populateArray(arr);

    printf("Insertion Sort\n");
    printf("Before Sorting: \n");
    for (idx = 0; idx < SIZE; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");

    // The Insertion Sort
    for (cmp = 1; cmp < SIZE; cmp++)
    {
        for (idx = 0; idx < cmp; idx++)
        {
            if (arr[idx] > arr[cmp])
            {
                tmp = arr[idx];
                arr[idx] = arr[cmp];
                //printf("Sorting: %d\n", arr[idx]);

                // Move all elements along to target element can be inserted into final location
                for (shift = cmp; shift > idx; shift--)
                    arr[shift] = arr[shift - 1];
                arr[shift + 1] = tmp;
                //printf("Shift:  %d\n", arr[shift + 1]);
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