#include <stdio.h>

int main()
{
    // Variable declaration of type int
    int integerVariable;
    unsigned int unsignedIntVariable;
    char charVariable;
    unsigned char unsignedCharVariable;
    short shortVariable;
    unsigned unsignedShortVariable;
    long longVariable;
    unsigned long unsignedLongVariable;
    float floatVariable;
    double doubleVariable;
    long double longDoubleVariable;

    // sizeof returns the size of the given variable
    printf("The size of Integer Variable is %zu bytes\n", sizeof(integerVariable));
    printf("The size of Unsigned Integer Variable is %zu bytes\n", sizeof(unsignedIntVariable));
    printf("The size of Char Variable is %zu bytes\n", sizeof(charVariable));
    printf("The size of Unsigned Char Variable is %zu bytes\n", sizeof(unsignedCharVariable));
    printf("The size of Short Variable is %zu bytes\n", sizeof(shortVariable));
    printf("The size of UnsignedShort Variable is %zu bytes\n", sizeof(unsignedShortVariable));
    printf("The size of Long Variable is %zu bytes\n", sizeof(longVariable));
    printf("The size of Unsigned Long Variable is %zu bytes\n", sizeof(unsignedLongVariable));
    printf("The size of Float Variable is %zu bytes\n", sizeof(floatVariable));
    printf("The size of Double Variable is %zu bytes\n", sizeof(doubleVariable));
    printf("The size of Long Double Variable is %zu bytes\n", sizeof(longDoubleVariable));

    return 0;
}