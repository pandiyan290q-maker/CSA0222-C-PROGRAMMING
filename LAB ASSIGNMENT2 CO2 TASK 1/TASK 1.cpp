#include <stdio.h>

int main()
{
    int i;
    double price[3] = {100, 250, 80};
    int quantity[3] = {2, 1, 5};
    int senior[3] = {1, 0, 1};

    double total, discount, gst, net;
    double discountRate = 10.0;
    double gstRate = 5.0;

    int count = 0;

    printf("JAN AUSHADHI PHARMACY BILLING\n");
    printf("------------------------------------------\n");

    for(i = 0; i < 3; i++)
    {
        total = price[i] * quantity[i];

        if(senior[i] == 1)
            discount = total * discountRate / 100.0;
        else
            discount = 0.0;

        gst = (total - discount) * gstRate / 100.0;

        net = (total - discount) + gst;

        count++;

        printf("\nScenario %d\n", i + 1);
        printf("Total    = Rs. %.2f\n", total);
        printf("Discount = Rs. %.2f\n", discount);
        printf("GST      = Rs. %.2f\n", gst);
        printf("Net Bill = Rs. %.2f\n", net);
    }

    printf("\nTotal Customers = %d\n", count);

    return 0;
}
