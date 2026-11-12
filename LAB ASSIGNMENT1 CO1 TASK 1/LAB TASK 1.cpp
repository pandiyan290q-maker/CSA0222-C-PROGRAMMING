#include <stdio.h>

int main()
{
    int household, previous, current, units;
    char category;

    printf("Enter Household Number: ");
    scanf("%d", &household);

    printf("Enter Category: ");
    scanf(" %c", &category);

    printf("Enter Previous Reading: ");
    scanf("%d", &previous);

    printf("Enter Current Reading: ");
    scanf("%d", &current);

    if(previous < 0 || current < 0 ||
       previous > 65535 || current > 65535)
        printf("Invalid Reading");

    else if(current >= previous)
        units = current - previous;
    else
        units = (65535 - previous) + current + 1;

    if(previous >= 0 && current >= 0 &&
       previous <= 65535 && current <= 65535)
    {
        printf("Household: %d\n", household);
        printf("Category: %c\n", category);
        printf("Units Consumed: %d\n", units);
    }

    return 0;
}
