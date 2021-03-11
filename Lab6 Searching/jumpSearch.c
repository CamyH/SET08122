#include <stdio.h>
#include <math.h>

#define SIZE 16

void jumpSearch(int *, int);

int main(void)
{
    int arr[SIZE] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};

    jumpSearch(arr, 89);

    jumpSearch(arr, 100);

    return (0);
}

void jumpSearch(int *array, int item)
{
    int previous = 0;
    int n = sizeof(array);
    // Find number of times to jump forward
    // Find Sqaure Root of size of array
    int jump = floor(sqrt(n));

    // As long as current item in array is smaller than the item to find, keep searching
    while (array[previous] < item)
    {
        // If the element in the array is greater than the item, after jumping, or, the number to jump is greater than the size of the array
        //  Stop the loop
        // Otherwise, set previous to the number of jumps and
        // Add the square root of the array to jump
        if (array[jump] > item || jump >= n)
        {
            break;
        }
        else
        {
            previous = jump;
            jump = jump + floor(sqrt(n));
        }
    }

    // Linear Search from index at position previous to find the item

    while (array[previous] < item)
    {
        previous++;
    }
    if (array[previous] == item)
    {
        printf("%d is found in the array at position %d\n", item, previous + 1);
    }
    else
    {
        printf("%d is not found in the array.", item);
    }
}