#include <stdio.h>
#include <string.h>

struct Course {
    char code[20];
    int credits;
    char grade;
};

struct Student {
    char nim[20];
    char name[50];
    struct Course courses[5];
};

int gradeWeight(char grade) {
    switch (grade) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'E': return 0;
        default: return 0;
    }
}

float calculateGPA(struct Student student) {
    int totalCredits = 0;
    int totalWeighted = 0;
    for (int i = 0; i < 5; i++) {
        int weight = gradeWeight(student.courses[i].grade);
        totalCredits += student.courses[i].credits;
        totalWeighted += student.courses[i].credits * weight;
    }
    if (totalCredits == 0) return 0.0f;
    return (float)totalWeighted / totalCredits;
}

int main() {
    struct Student student;
    printf("NIM   : ");
    fgets(student.nim, sizeof(student.nim), stdin);
    student.nim[strcspn(student.nim, "\n")] = 0;
    printf("Nama  : ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = 0;

    for (int i = 0; i < 5; i++) {
        printf("\nInput Data %d :\n", i+1);
        printf("Kode MK : ");
        fgets(student.courses[i].code, sizeof(student.courses[i].code), stdin);
        student.courses[i].code[strcspn(student.courses[i].code, "\n")] = 0;
        printf("SKS     : ");
        scanf("%d", &student.courses[i].credits);
        printf("GRADE   : ");
        scanf(" %c", &student.courses[i].grade);
        while (getchar() != '\n');
    }

    float gpa = calculateGPA(student);

    printf("\nOUTPUT :\n");
    printf("NIM   : %s\n", student.nim);
    printf("NAMA  : %s\n", student.name);
    printf("GPA   : %.2f\n", gpa);

    return 0;
}
