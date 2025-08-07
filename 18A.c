#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char nim[20];
    char name[50];
    float gpa;
};

void inputStudent(struct Student *student, int idx) {
    printf("\nInput Data :\n");
    printf("NIM   : ");
    fgets(student->nim, sizeof(student->nim), stdin);
    student->nim[strcspn(student->nim, "\n")] = 0;
    printf("Nama  : ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = 0;
    printf("GPA   : ");
    scanf("%f", &student->gpa);
    while (getchar() != '\n'); // flush input buffer
}

int main() {
    int n;
    do {
        printf("Berapa banyak data (5 - 50) : ");
        scanf("%d", &n);
        while (getchar() != '\n'); // flush input buffer
    } while (n < 5 || n > 50);

    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));
    if (!students) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nData %d :\n", i+1);
        inputStudent(&students[i], i+1);
    }

    printf("\nOUTPUT :\n");
    printf("NO.  NIM           NAMA                      GPA\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d %-13s %-25s %.2f\n", i+1, students[i].nim, students[i].name, students[i].gpa);
    }

    free(students);
    return 0;
}
