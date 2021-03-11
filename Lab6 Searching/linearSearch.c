#include <stdio.h>
#include <time.h>

#define SIZE 20

void code(int *, int);

void code(int *array, int item)
{
    /*for (int i = 0; i < 1000000; i++)
    {
        //printf(".");
    }*/
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] == item)
            printf("Item %d found in array.", item);
    }
    printf("\n");
}

int main()
{
    int runtime;

    int timesToRun = 10000;

    double totalRunTime;

    int array[SIZE] = {10, 4, 100, 3, 27, 102, 43, 1400, 35, 267, 170, 48, 1900, 322, 237, 150, 411, 40, 31, 227};

    clock_t t;
    printf("Start: %d \n", (int)(t = clock()));

    for (int i = 0; i < timesToRun; i++)
    {
        code(array, 3);
    }
    // Store run time (seconds) in int variable
    int stopTime = (int)(t = clock() - t);
    printf("Stop: %d \n", stopTime);
    printf("Elapsed: %f seconds\n", (double)t / CLOCKS_PER_SEC);
    // Multiply number of run times by 1000
    int timesToRunMultiplied = timesToRun * 1000;
    // Calculate average - run time (seconds) divided by number of times run (thousands)
    double averageRunTime = (double)stopTime / timesToRunMultiplied;
    printf("Average RunTime: %f seconds\n", averageRunTime);

    return 0;
}