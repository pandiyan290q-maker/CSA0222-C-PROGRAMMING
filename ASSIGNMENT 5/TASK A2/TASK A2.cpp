#include <stdio.h>

int digitalRoot(int n)
{
    if (n < 10)
        return n;

    int sum = 0;

    while (n > 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }

    return digitalRoot(sum);
}

int powerLinear(int base, int n)
{
    if (n == 0)
        return 1;

    return base * powerLinear(base, n - 1);
}

int powerHalving(int base, int n)
{
    if (n == 0)
        return 1;

    int half = powerHalving(base, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main()
{
    int n, base, exponent;

    printf("Enter donor ID: ");
    scanf("%d", &n);

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    printf("\nDigital Root = %d", digitalRoot(n));
    printf("\nLinear Power = %d", powerLinear(base, exponent));
    printf("\nHalving Power = %d\n", powerHalving(base, exponent));

    return 0;
}
