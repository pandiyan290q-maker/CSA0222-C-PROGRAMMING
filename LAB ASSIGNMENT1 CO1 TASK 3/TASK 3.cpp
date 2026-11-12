#include <stdio.h>

#define RATE1 2
#define RATE2 3
#define RATE3 5
#define FIXED 50

int main()
{
    int units, charge, bill;

    printf("Enter Units: ");
    scanf("%d", &units);

    if(units < 0)
        printf("Invalid Units");

    else if(units <= 100)
        charge = units * RATE1;

    else if(units <= 200)
        charge = 100 * RATE1 +
                 (units - 100) * RATE2;

    else
        charge = 100 * RATE1 + 100 * RATE2 +
                 (units - 200) * RATE3;

    if(units >= 0)
    {
        bill = charge + FIXED;

        printf("Energy Charge = Rs.%d\n", charge);
        printf("Total Bill = Rs.%d\n", bill);
    }

    return 0;
}
