#include <stdio.h>

int main()
{
    int a, paise;
    float b;
    double c;
    char ch;
    char name[20];

    printf("Enter integer: ");
    scanf("%d", &a);

    printf("Enter float: ");
    scanf("%f", &b);

    printf("Enter double: ");
    scanf("%lf", &c);

    printf("Enter character: ");
    scanf(" %c", &ch);

    printf("Enter name: ");
    scanf("%19s", name);

    printf("Enter amount in paise: ");
    scanf("%d", &paise);

    printf("\nInteger = %d", a);
    printf("\nFloat = %.2f", b);
    printf("\nDouble = %.2lf", c);
    printf("\nCharacter = %c", ch);
    printf("\nName = %s", name);
    printf("\nAmount = Rs.%d.%02d",
           paise / 100, paise % 100);

    return 0;
}
