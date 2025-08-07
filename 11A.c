#include <stdio.h>

int getScore() {
    int X;
    printf("Input Score (0-100): ");
    scanf("%d", &X);
    while (X < 0 || X > 100) {
        printf("Please Input Score between (0-100): ");
        scanf("%d", &X);
    }
    return X;
}

void getGrade(int X) {
    printf("Your Grade = ");
    if (X >= 96 && X <= 100) {
        printf("A\n");
    } else if (X >= 91) {
        printf("A-\n");
    } else if (X >= 86) {
        printf("B+\n");
    } else if (X >= 81) {
        printf("B\n");
    } else if (X >= 76) {
        printf("B-\n");
    } else if (X >= 71) {
        printf("C+\n");
    } else if (X >= 66) {
        printf("C\n");
    } else if (X >= 61) {
        printf("C-\n");
    } else if (X >= 40) {
        printf("D\n");
    } else {
        printf("E\n");
    }
}

int main() {
    int X = getScore();
    getGrade(X);
    return 0;
}