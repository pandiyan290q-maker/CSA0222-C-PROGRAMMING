
#include <stdio.h>

#define D 3
#define M 4

void calculateTotal(int rain[D][M])
{
    int i, j, total;

    printf("\nAnnual Rainfall Total:\n");

    for(i = 0; i < D; i++)
    {
        total = 0;
        for(j = 0; j < M; j++)
            total += rain[i][j];

        printf("District %d = %d mm\n", i + 1, total);
    }
}

void calculateAverage(int rain[D][M])
{
    int i, j, sum = 0;

    for(i = 0; i < D; i++)
        for(j = 0; j < M; j++)
            sum += rain[i][j];

    printf("\nState Monthly Average = %.2f mm\n",
           (float)sum / (D * M));
}

void findMaximum(int rain[D][M])
{
    int i, j, max = rain[0][0];
    int district = 0, month = 0;

    for(i = 0; i < D; i++)
        for(j = 0; j < M; j++)
            if(rain[i][j] > max)
            {
                max = rain[i][j];
                district = i;
                month = j;
            }

    printf("\nWettest District = %d", district + 1);
    printf("\nMonth = %d", month + 1);
    printf("\nMaximum Rainfall = %d mm\n", max);
}

void findDeficient(int rain[D][M])
{
    int i, j, sum = 0;

    for(i = 0; i < D; i++)
        for(j = 0; j < M; j++)
            sum += rain[i][j];

    float average = (float)sum / (D * M);

    printf("\nDeficient Districts:\n");

    for(i = 0; i < D; i++)
    {
        int total = 0;

        for(j = 0; j < M; j++)
            total += rain[i][j];

        if(total < 0.6 * average * M)
            printf("District %d\n", i + 1);
    }
}

int main()
{
    int rain[D][M];
    int i, j;

    printf("Enter rainfall for 3 districts and 4 months:\n");

    for(i = 0; i < D; i++)
        for(j = 0; j < M; j++)
            scanf("%d", &rain[i][j]);

    calculateTotal(rain);
    calculateAverage(rain);
    findMaximum(rain);
    findDeficient(rain);

    return 0;
}

