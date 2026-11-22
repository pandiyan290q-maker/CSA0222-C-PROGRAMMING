#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[20];
    char bloodGroup[5];
    FILE *fp;

    if (argc > 2)
    {
        printf("Error: Too many arguments.\n");
        return 1;
    }

    printf("Enter donor name: ");

    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Invalid input.\n");
        return 1;
    }

    name[strcspn(name, "\n")] = '\0';

    printf("Donor Name: %s\n", name);

    printf("Enter blood group: ");
    scanf("%4s", bloodGroup);

    if (strcmp(bloodGroup, "A+") != 0 &&
        strcmp(bloodGroup, "A-") != 0 &&
        strcmp(bloodGroup, "B+") != 0 &&
        strcmp(bloodGroup, "B-") != 0 &&
        strcmp(bloodGroup, "AB+") != 0 &&
        strcmp(bloodGroup, "AB-") != 0 &&
        strcmp(bloodGroup, "O+") != 0 &&
        strcmp(bloodGroup, "O-") != 0)
    {
        printf("Error: Invalid blood group.\n");
        return 1;
    }

    fp = fopen("donor.txt", "r");

    if (fp == NULL)
    {
        perror("File opening error");
    }
    else
    {
        printf("File opened successfully.\n");
        fclose(fp);
    }

    printf("Blood Group: %s\n", bloodGroup);
    printf("Program completed safely.\n");

    return 0;
}
