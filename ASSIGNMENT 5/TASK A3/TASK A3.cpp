#include <stdio.h>
#include <string.h>

int stock[8] = {20, 15, 30, 10, 25, 18, 12, 22};

char *bloodGroups[8] = {
    "A+", "A-", "B+", "B-", "O+", "O-", "AB+", "AB-"
};

int *findLowestStock(int *p, int n)
{
    int *lowest = p;

    for (int i = 1; i < n; i++)
    {
        if (*(p + i) < *lowest)
        {
            lowest = p + i;
        }
    }

    return lowest;
}

int main(int argc, char *argv[])
{
    int *p = stock;

    if (argc == 2 && strcmp(argv[1], "find") == 0)
    {
        int *lowest = findLowestStock(p, 8);
        int index = lowest - stock;

        printf("Lowest Stock Blood Group: %s\n", bloodGroups[index]);
        printf("Available Units: %d\n", *lowest);
    }
    else if (argc == 4 && strcmp(argv[1], "issue") == 0)
    {
        int units;

        if (sscanf(argv[3], "%d", &units) != 1 || units <= 0)
        {
            printf("Invalid number of units.\n");
            return 1;
        }

        int found = -1;

        for (int i = 0; i < 8; i++)
        {
            if (strcmp(argv[2], bloodGroups[i]) == 0)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            printf("Invalid blood group.\n");
        }
        else if (stock[found] < units)
        {
            printf("Insufficient stock.\n");
        }
        else
        {
            stock[found] -= units;
            printf("Blood issued successfully.\n");
            printf("Remaining Stock: %d\n", stock[found]);
        }
    }
    else
    {
        printf("Invalid command.\n");
        printf("Usage: bloodbank find\n");
        printf("Usage: bloodbank issue A- 2\n");
    }

    return 0;
}
