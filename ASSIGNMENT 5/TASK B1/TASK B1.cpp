#include <stdio.h>

long long calls = 0;

int digital_root(int n)
{
    if (n < 10)
        return n;

    return digital_root(n % 10 + digital_root(n / 10));
}

long long power_linear(long long base, int exp)
{
    calls++;

    if (exp == 0)
        return 1;

    return base * power_linear(base, exp - 1);
}

long long power_fast(long long base, int exp)
{
    calls++;

    if (exp == 0)
        return 1;

    long long half = power_fast(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;

    return base * half * half;
}

long long power_iterative(long long base, int exp)
{
    long long result = 1;

    while (exp > 0)
    {
        result *= base;
        exp--;
    }

    return result;
}

int main(void)
{
    calls = 0;
    long long a = power_linear(2, 30);
    printf("Linear: %lld in %lld calls\n", a, calls);

    calls = 0;
    long long b = power_fast(2, 30);
    printf("Fast: %lld in %lld calls\n", b, calls);

    printf("\nDigital Root:\n");
    printf("Digital root of 12345 = %d\n", digital_root(12345));
    printf("Digital root of 0 = %d\n", digital_root(0));
    printf("Digital root of 1 = %d\n", digital_root(1));

    printf("\nPower Testing:\n");
    printf("2^0 = %lld\n", power_fast(2, 0));
    printf("2^1 = %lld\n", power_fast(2, 1));
    printf("2^5 = %lld\n", power_fast(2, 5));

    printf("\nRecursive Call Counts:\n");

    int values[] = {10, 100, 1000, 10000};

    for (int i = 0; i < 4; i++)
    {
        calls = 0;
        power_linear(1, values[i]);
        printf("Linear n=%d: %lld calls\n", values[i], calls);

        calls = 0;
        power_fast(1, values[i]);
        printf("Fast n=%d: %lld calls\n", values[i], calls);
    }

    printf("\nIterative Power: %lld\n", power_iterative(2, 30));

    return 0;
}
