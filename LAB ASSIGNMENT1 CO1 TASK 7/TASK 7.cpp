#include <stdio.h>

int main()
{
    int a = 5, b = 2;
    float x;
    double bill = 162.50;
    long int value = 500000;
    int small;

    printf("Integer Division: %d\n", a / b);

    x = (float)a / b;
    printf("Floating Division: %.2f\n", x);

    printf("Implicit Conversion: %.2f\n", a + 2.5);

    printf("Explicit Conversion: %.2f\n", (float)a / b);

    printf("Bill Amount: %.2f\n", bill);

    printf("Rounded Paise: %lld\n",
           (long long)(bill * 100 + 0.5));

    small = (int)value;
    printf("Converted Value: %d\n", small);

    printf("Unexpected Result: %.2f\n", 0.1 + 0.2);

    return 0;
}
