#ifndef BILLING_H
#define BILLING_H

#define RATE 2
#define FIXED 50

int calculate(int units);

#endif
#include <stdio.h>


int calculate(int units)
{
    return units * RATE + FIXED;
}

int main()
{
    int units, bill;

    printf("Enter units: ");
    scanf("%d", &units);

    bill = calculate(units);

    #ifdef DEBUG
    printf("Debug: Units = %d\n", units);
    #endif

    printf("Total Bill = Rs.%d\n", bill);

    return 0;
}
