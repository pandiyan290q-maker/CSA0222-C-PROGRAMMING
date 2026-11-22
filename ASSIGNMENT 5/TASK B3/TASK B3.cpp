#include <stdio.h>

typedef struct
{
    int group_code;
    int units;
} Stock;

int update_units(FILE *fp, int index, int units)
{
    Stock s;

    if (fseek(fp, index * sizeof(Stock), SEEK_SET) != 0)
        return 0;

    if (fread(&s, sizeof(Stock), 1, fp) != 1)
        return 0;

    s.units = units;

    if (fseek(fp, -(long)sizeof(Stock), SEEK_CUR) != 0)
        return 0;

    if (fwrite(&s, sizeof(Stock), 1, fp) != 1)
        return 0;

    return 1;
}

int main(void)
{
    FILE *fp = fopen("C:\\Users\\Public\\stock.dat", "w+b");

    if (fp == NULL)
    {
        perror("fopen");
        return 1;
    }

    Stock initial[5] = {
        {1, 40},
        {2, 25},
        {3, 12},
        {4, 8},
        {5, 30}
    };

    if (fwrite(initial, sizeof(Stock), 5, fp) != 5)
    {
        printf("File writing failed\n");
        fclose(fp);
        return 1;
    }

    printf("update record 3: %s\n",
           update_units(fp, 3, 20) ? "done" : "failed");

    printf("update record 9: %s\n",
           update_units(fp, 9, 20) ? "done" : "failed");

    rewind(fp);

    Stock s;

    while (fread(&s, sizeof(Stock), 1, fp) == 1)
    {
        printf("%d:%d ", s.group_code, s.units);
    }

    printf("\n");

    fclose(fp);

    return 0;
}
