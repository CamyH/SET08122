#include <stdio.h>
#include <time.h>

void code()
{
    for (int i = 0; i < 1000000; i++)
    {
        printf(".");
    }
    printf("\n");
}

int main()
{
    int runtime;
    int timesToRun = 5;
    double totalRunTime;
    clock_t t;
    printf("Start: %d \n", (int)(t = clock()));

    for (int i = 0; i < timesToRun; i++)
    {
        code();
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