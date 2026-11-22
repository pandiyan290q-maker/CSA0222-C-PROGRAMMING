#include <stdio.h>
#include <string.h>

int main()
{
    char names[6][30] = {
        "Naveen",
        "Hari",
        "Jay",
        "Vignesh",
        "Akash",
        "Madan"
    };

    char temp[30], key[] = "Naveen";
    int i, j, found = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = i + 1; j < 6; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Sorted Names:\n");

    for(i = 0; i < 6; i++)
        printf("%s\n", names[i]);

    printf("\nDuplicate Names:\n");

    for(i = 0; i < 5; i++)
    {
        if(strcmp(names[i], names[i + 1]) == 0)
            printf("%s\n", names[i]);
    }

    int low = 0, high = 5, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(strcmp(names[mid], key) == 0)
        {
            found = 1;
            break;
        }
        else if(strcmp(names[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("\nSearching Name: %s\n", key);

    if(found)
        printf("Name Found");
    else
        printf("Name Not Found");

    return 0;
}
