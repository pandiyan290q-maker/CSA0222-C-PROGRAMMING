#include <stdio.h>

struct date {
    int day, month, year;
};

struct item {
    int id, stock, sold;
    char name[30];
    float price;
    int type;
    union {
        struct date expiry;
        int preparedTime;
    } details;
};

int main()
{
    struct item a[4] = {
        {1, 10, 0, "Milk", 20, 1, {{23, 11, 2026}}},
        {2, 8, 0, "Rice", 50, 2, {0}},
        {3, 5, 0, "Juice", 30, 1, {{22, 11, 2026}}},
        {4, 10, 0, "Combo", 80, 3, {0}}
    };

    int id, qty, i, j;
    float total, revenue[4] = {0}, temp;

    printf("Enter item ID and quantity (0 0 to stop):\n");

    while (1) {
        scanf("%d%d", &id, &qty);

        if (id == 0)
            break;

        if (id < 1 || id > 4 || qty <= 0) {
            printf("Invalid input\n");
            continue;
        }

        i = id - 1;

        if (qty > a[i].stock) {
            printf("Insufficient stock\n");
            continue;
        }

        a[i].stock -= qty;
        a[i].sold += qty;
        revenue[i] += qty * a[i].price;

        printf("Sale successful: Rs. %.2f\n", qty * a[i].price);
    }

    printf("\nExpiry Warning:\n");

    for (i = 0; i < 4; i++) {
        if (a[i].type == 1 &&
            a[i].details.expiry.month == 11 &&
            a[i].details.expiry.year == 2026 &&
            a[i].details.expiry.day <= 23)
            printf("%s is expiring soon\n", a[i].name);
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (revenue[i] < revenue[j]) {
                temp = revenue[i];
                revenue[i] = revenue[j];
                revenue[j] = temp;

                struct item t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    printf("\nDaily Revenue Summary:\n");
    printf("Item\tRevenue\n");

    for (i = 0; i < 4; i++)
        printf("%s\t%.2f\n", a[i].name, revenue[i]);

    return 0;
}
