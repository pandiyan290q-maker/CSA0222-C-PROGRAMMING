#include <stdio.h>

int calls = 0;

int verify()
{
    calls++;
    return 1;
}

int main()
{
    int age = 0, category = 1;

    if(age && verify())
        printf("Eligible\n");
    else
        printf("Not Eligible\n");

    printf("AND Calls = %d\n", calls);

    if(category || verify())
        printf("OR Short Circuit\n");

    printf("OR Calls = %d\n", calls);

    if(0 & verify())
        printf("True\n");

    printf("Bitwise Calls = %d\n", calls);

    return 0;
}
