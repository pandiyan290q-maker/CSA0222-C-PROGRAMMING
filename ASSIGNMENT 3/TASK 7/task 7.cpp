#include <stdio.h>

int main()
{
    int votes[5000], count[13] = {0};
    int n, c, i, j, temp;
    int valid = 0, invalid = 0, max = 0, tie = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &c);

    printf("Enter number of votes: ");
    scanf("%d", &n);

    printf("Enter votes:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &votes[i]);

        if(votes[i] >= 1 && votes[i] <= c)
        {
            count[votes[i]]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    printf("\nValid votes: %d", valid);
    printf("\nInvalid votes: %d\n", invalid);

    for(i = 1; i <= c; i++)
    {
        for(j = i + 1; j <= c; j++)
        {
            if(count[i] < count[j])
            {
                temp = count[i];
                count[i] = count[j];
                count[j] = temp;

                temp = i;
                i = j;
                j = temp;
            }
        }
    }

    printf("\nCandidate vote counts:\n");

    for(i = 1; i <= c; i++)
    {
        printf("Candidate %d: %d votes\n", i, count[i]);

        if(count[i] > max)
            max = count[i];
    }

    for(i = 1; i <= c; i++)
    {
        if(count[i] == max)
            tie++;
    }

    if(tie > 1)
        printf("\nResult: Election is tied.");
    else
        printf("\nWinner has %d votes.", max);

    return 0;
}
