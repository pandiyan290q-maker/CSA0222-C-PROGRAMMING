#include <stdio.h>

#define TO_PAISE(r) ((r) * 100)
#define SQUARE(x) ((x) * (x))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main()
{
    int rupees = 50;
    int a = 10, b = 20;

    printf("Paise = %d\n", TO_PAISE(rupees));
    printf("Square = %d\n", SQUARE(5));
    printf("Maximum = %d\n", MAX(a, b));

    return 0;
}
