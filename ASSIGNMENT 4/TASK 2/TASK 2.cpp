#include <stdio.h>

struct date {
    int day, month, year;
};

struct address {
    char name[30];
    char city[20];
    int pincode;
};

struct parcel {
    int id;
    float weight;
    struct address sender, receiver;
    struct date booked;
    char service[10];
    float charge;
};

void print_parcel(const struct parcel *p)
{
    printf("%d %.1f kg %s-%d %02d/%02d/%04d\n",
           p->id, p->weight, p->receiver.city,
           p->receiver.pincode,
           p->booked.day, p->booked.month,
           p->booked.year);
}

void sort_by_weight(struct parcel p[], int n)
{
    int i, j, min;
    struct parcel temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (p[j].weight < p[min].weight)
                min = j;
        }

        if (min != i) {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
}

int main(void)
{
    struct parcel list[3] = {
        {501, 4.5, {"Ravi", "Madurai", 625001},
         {"Arun", "Madurai", 625001}, {12, 10, 2026}, "Normal", 100},

        {502, 1.2, {"Kumar", "Chennai", 600077},
         {"Naveen", "Chennai", 600077}, {12, 10, 2026}, "Express", 150},

        {503, 2.8, {"Mani", "Coimbatore", 641001},
         {"Vijay", "Coimbatore", 641001}, {13, 10, 2026}, "Normal", 120}
    };

    int i;

    sort_by_weight(list, 3);

    printf("Parcel Details Sorted by Weight:\n");

    for (i = 0; i < 3; i++) {
        print_parcel(&list[i]);
    }

    printf("\nReceiver PIN of Third Parcel: %d\n",
           list[2].receiver.pincode);

    return 0;
}
