#include <stdio.h>

struct Date {
    int day, month, year;
};

struct BP {
    int systolic, diastolic;
};

struct Patient {
    char name[30], phone[11];
    int age;
    struct BP bp;
    struct Date date;
};

struct Patient p[100];
int count = 0;

void addPatient(struct Patient *x) {
    if (count < 100)
        p[count++] = *x;
    else
        printf("Register Full");
}

int main() {
    struct Patient x;

    printf("Enter name: ");
    scanf("%29s", x.name);

    printf("Enter age: ");
    scanf("%d", &x.age);

    printf("Enter phone: ");
    scanf("%10s", x.phone);

    printf("Enter BP (systolic diastolic): ");
    scanf("%d %d", &x.bp.systolic, &x.bp.diastolic);

    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &x.date.day, &x.date.month, &x.date.year);

    addPatient(&x);

    printf("\nPatient Details\n");
    printf("Name: %s\nAge: %d\nPhone: %s\n", p[0].name, p[0].age, p[0].phone);
    printf("BP: %d/%d\n", p[0].bp.systolic, p[0].bp.diastolic);
    printf("Date: %02d/%02d/%04d\n", p[0].date.day, p[0].date.month, p[0].date.year);

    return 0;
}
