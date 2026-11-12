#include <stdio.h>

int main()
{
    double balance = 10000, rate = 0.02, payment = 2000;
    double interest, totalInterest = 0, paid;
    int month = 0;

    while (balance > 0 && month < 360)
    {
        month++;
        interest = balance * rate;
        totalInterest += interest;

        if (payment <= interest)
        {
            printf("Loan cannot be repaid\n");
            return 0;
        }

        paid = (balance + interest < payment) ?
               balance + interest : payment;

        balance = balance + interest - paid;

        if (balance < 0.005)
            balance = 0;

        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",
               month, balance + paid - interest,
               interest, paid, balance);
    }

    printf("\nTotal Interest: Rs. %.2f", totalInterest);
    printf("\nTotal Months: %d\n", month);

    return 0;
}
