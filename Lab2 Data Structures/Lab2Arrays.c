#include <stdio.h>

int main()
{
    // Int array for 1st year module grades
    // Grades are fictional
    int grades[] = {62, 73, 81, 75, 68, 71};
    printf("%d\n", grades[2]);
    printf("The size of Integer array is %zu bytes\n", sizeof(grades));

    int a[100];
    size_t s = sizeof(a);
    printf("%zu bytes\n", s);

    size_t num = s / sizeof(int);
    printf("Space for storing %zu elements\n", num);

    return 0;
}