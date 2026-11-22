#include <stdio.h>
#include <string.h>

struct Donor {
    int id;
    char name[30];
    int age;
    char bloodGroup[5];
    int units;
};

struct Result {
    int eligibleCount;
    int youngestID;
};

void registerDonor(struct Donor *d);
int checkEligibility(const struct Donor *d);
int findDonors(const struct Donor d[], int n);
void updateStock(int *stock, int units);
void saveDonor(const struct Donor *d);
void loadDonors(const struct Donor d[], int n);
struct Result getYoungest(const struct Donor d[], int n);

void registerDonor(struct Donor *d) {
    printf("Enter Donor ID: ");
    scanf("%d", &d->id);

    printf("Enter Name: ");
    scanf("%29s", d->name);

    printf("Enter Age: ");
    scanf("%d", &d->age);

    printf("Enter Blood Group: ");
    scanf("%4s", d->bloodGroup);

    printf("Enter Units: ");
    scanf("%d", &d->units);
}

int checkEligibility(const struct Donor *d) {
    return d->age >= 18 && d->age <= 65;
}

int findDonors(const struct Donor d[], int n) {
    int count = 0;

    printf("\nEligible Donors:\n");

    for (int i = 0; i < n; i++) {
        if (checkEligibility(&d[i])) {
            printf("%d  %s  %d  %s\n",
                   d[i].id, d[i].name,
                   d[i].age, d[i].bloodGroup);
            count++;
        }
    }

    return count;
}

void updateStock(int *stock, int units) {
    *stock += units;
}

void saveDonor(const struct Donor *d) {
    FILE *fp = fopen("donors.txt", "a");

    if (fp != NULL) {
        fprintf(fp, "%d %s %d %s %d\n",
                d->id, d->name, d->age,
                d->bloodGroup, d->units);
        fclose(fp);
    }
}

void loadDonors(const struct Donor d[], int n) {
    printf("\nDonor Records:\n");

    for (int i = 0; i < n; i++) {
        printf("%d %s %d %s %d\n",
               d[i].id, d[i].name,
               d[i].age, d[i].bloodGroup,
               d[i].units);
    }
}

struct Result getYoungest(const struct Donor d[], int n) {
    struct Result r;
    r.eligibleCount = 0;
    r.youngestID = -1;

    int minAge = 100;

    for (int i = 0; i < n; i++) {
        if (checkEligibility(&d[i])) {
            r.eligibleCount++;

            if (d[i].age < minAge) {
                minAge = d[i].age;
                r.youngestID = d[i].id;
            }
        }
    }

    return r;
}

int main() {
    struct Donor d[10];
    int n, stock = 0;

    printf("Enter number of donors: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number of donors.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("\nRegister Donor %d\n", i + 1);

        registerDonor(&d[i]);

        if (checkEligibility(&d[i])) {
            updateStock(&stock, d[i].units);
        }

        saveDonor(&d[i]);
    }

    int count = findDonors(d, n);

    struct Result r = getYoungest(d, n);

    printf("\nTotal Eligible Donors: %d\n", count);
    printf("Youngest Eligible Donor ID: %d\n", r.youngestID);
    printf("Total Blood Stock: %d units\n", stock);

    loadDonors(d, n);

    return 0;
}
