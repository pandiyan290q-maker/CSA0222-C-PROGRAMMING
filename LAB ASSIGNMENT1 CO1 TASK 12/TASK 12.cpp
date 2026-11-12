#include <stdio.h>

int main()
{
    long long watt, total = 0;
    double rate, bill = 0;
    int hour, i;

    printf("Enter tariff rate: ");
    scanf("%lf", &rate);

    for(i = 1; i <= 5; i++)
    {
        printf("Enter watt-hours and hour: ");
        scanf("%lld %d", &watt, &hour);

        total += watt;

        if(hour >= 18 && hour < 22)
            bill += (watt / 1000.0) * rate * 1.2;
        else
            bill += (watt / 1000.0) * rate;
    }

    printf("Total Watt-hours = %lld\n", total);
    printf("Total Bill = Rs. %.2f", bill);

    return 0;
}
