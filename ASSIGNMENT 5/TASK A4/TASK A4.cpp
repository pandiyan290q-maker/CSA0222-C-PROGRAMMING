#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Donor
{
    int id;
    char name[30];
    char bloodGroup[5];
};

int main()
{
    struct Donor *donors;
    struct Donor *temp;
    int count = 0, capacity = 2, i;

    donors = (struct Donor *)malloc(capacity * sizeof(struct Donor));

    if (donors == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1)
    {
        if (count == capacity)
        {
            capacity = capacity * 2;

            temp = (struct Donor *)realloc(donors,
                    capacity * sizeof(struct Donor));

            if (temp == NULL)
            {
                printf("Memory reallocation failed\n");
                free(donors);
                return 1;
            }

            donors = temp;
        }

        printf("Enter Donor ID (0 to stop): ");
        scanf("%d", &donors[count].id);

        if (donors[count].id == 0)
            break;

        printf("Enter Donor Name: ");
        scanf("%29s", donors[count].name);

        printf("Enter Blood Group: ");
        scanf("%4s", donors[count].bloodGroup);

        count++;
    }

    printf("\n--- Donor Details ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d  Name: %s  Blood Group: %s\n",
               donors[i].id,
               donors[i].name,
               donors[i].bloodGroup);
    }

    printf("\nTotal Donors: %d\n", count);
    printf("Final Capacity: %d\n", capacity);

    free(donors);
    donors = NULL;

    return 0;
}
