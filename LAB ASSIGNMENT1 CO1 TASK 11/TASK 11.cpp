#include <stdio.h>

#define RATE1 1.5
#define RATE2 2.5
#define RATE3 4.0

int main()
{
    int units = 150;
    double bill;

    if(units <= 100)
        bill = units * RATE1;
    else if(units <= 200)
        bill = 100 * RATE1 + (units - 100) * RATE2;
    else
        bill = 100 * RATE1 + 100 * RATE2
               + (units - 200) * RATE3;

    printf("Units = %d\n", units);
    printf("Total Bill = Rs. %.2f\n", bill);

    return 0;
}
