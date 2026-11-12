#include <stdio.h>
#include <limits.h>

int main()
{
    int bills[] = {4000, 60000, 800000};
    int i;

    for(i = 0; i < 3; i++)
    {
        double total = 123.45 * bills[i];
        long long paise = 12345LL * bills[i];

        printf("\nBills: %d", bills[i]);
        printf("\nDouble: %.2f", total);
        printf("\nPaise: %.2f\n", paise / 100.0);
    }

    printf("\nInt size: %zu", sizeof(int));
    printf("\nLong size: %zu", sizeof(long));
    printf("\nLong long size: %zu", sizeof(long long));

    return 0;
}
