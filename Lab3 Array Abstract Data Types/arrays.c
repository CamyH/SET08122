#include <stdio.h>

#define MAX 5

void init(int *array);
void insert(int *, int pos, int num);
void replace(int *, int pos, int num);
void delete (int *, int pos);
void reverse(int *);
void display(int *);
void search(int *, int num);

int main()
{
    int array[MAX];
    // Initialise Array
    init(array);
    // Insert numbers into array
    insert(array, 1, 5);
    insert(array, 2, 10);
    insert(array, 3, 3);
    insert(array, 4, 20);
    insert(array, 5, 8);

    printf("Array Contents after Insertion: \n");
    // Invoke display function
    display(array);

    // Replace numbers in the array
    replace(array, 0, 10);
    replace(array, 1, 5);
    replace(array, 2, 6);
    replace(array, 3, 200);
    replace(array, 4, 2);

    printf("Array Contents after numbers have been replaced: \n");
    // Invoke display function
    display(array);

    delete (array, 5);
    delete (array, 4);

    printf("Array Contents after Deletion: \n");
    // Invoke display function
    display(array);

    insert(array, 4, 200);
    insert(array, 5, 2);

    printf("Array Contents after Insertion: \n");
    // Invoke display function
    display(array);

    reverse(array);

    printf("Array Contents after Reversal: \n");
    // Invoke display function
    display(array);

    // Searching for numbers within the array
    search(array, 2);
    search(array, 5);
    search(array, 8);

    return 0;
}

void display(int *array)
{
    int idx;
    for (idx = 0; idx < MAX; idx++)
    {
        printf("%d\t", idx);
    }
    printf("\n");

    for (idx = 0; idx < MAX; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
}

void init(int *array)
{
    int idx;
    for (idx = 0; idx < MAX; idx++)
    {
        array[idx] = 0;
    }
}

void insert(int *array, int pos, int num)
{
    int idx;
    for (idx = MAX - 1; idx >= pos; idx--)
    {
        array[idx] = array[idx - 1];
    }
    array[idx] = num;
}

void replace(int *array, int pos, int num)
{
    int idx;
    for (idx = 0; idx < MAX; idx++)
    {
        if (idx == pos)
            array[idx] = num;
    }
}

void delete (int *array, int pos)
{
    int idx;
    for (idx = pos; idx < MAX; idx++)
    {
        array[idx - 1] = array[idx];
    }
    array[idx - 1] = 0;
}

void reverse(int *array)
{
    int idx;
    for (idx = 0; idx < MAX / 2; idx++)
    {
        int temp = array[idx];
        array[idx] = array[MAX - 1 - idx];
        array[MAX - 1 - idx] = temp;
    }
}

void search(int *array, int num)
{
    int idx;
    for (idx = 0; idx < MAX; idx++)
    {
        if (array[idx] == num)
        {
            printf("%d found at position %d\n", num, idx + 1);
            return;
        }
    }
    if (idx == MAX)
        printf("%d not found in array\n", num);
}