#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a;
    float b;
    double c;
    long long d;

    printf("Size of int = %zu bytes\n", sizeof(a));
    printf("Size of float = %zu bytes\n", sizeof(b));
    printf("Size of double = %zu bytes\n", sizeof(c));
    printf("Size of long long = %zu bytes\n", sizeof(d));

    printf("Maximum int = %d\n", INT_MAX);
    printf("Maximum float = %e\n", FLT_MAX);
    printf("Maximum double = %e\n", DBL_MAX);

    return 0;
}
