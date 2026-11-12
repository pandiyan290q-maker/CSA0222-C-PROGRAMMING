#include <stdio.h>

int main()
{
    int prev, curr, units;
    float bill;

    printf("Enter previous reading: ");
    scanf("%d", &prev);

    printf("Enter current reading: ");
    scanf("%d", &curr);

    if(prev < 0 || curr < 0 || prev > 65535 || curr > 65535)
        printf("Invalid reading");

    else
    {
        if(prev == 65535 && curr == 0)
            units = 1;
        else if(curr < prev)
        {
            printf("Invalid reading");
            return 0;
        }
        else
            units = curr - prev;

        if(units <= 100)
            bill = units * 1.5;
        else if(units <= 200)
            bill = 150 + (units - 100) * 2.5;
        else
            bill = 400 + (units - 200) * 4;

        printf("\nUnits = %d", units);
        printf("\nTotal Bill = Rs. %.2f", bill);
    }

    return 0;
}
