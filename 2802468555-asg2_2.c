#include <stdio.h>

struct Answer {
    int number;
    char answerChar;
};

void swap(struct Answer *a, struct Answer *b) {
    struct Answer temp = *a;
    *a = *b;
    *b = temp;
}

void sortAnswers(struct Answer arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].number > arr[j + 1].number) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    FILE *fp = fopen("testdata2.in", "r");
    if (fp == NULL) {
        printf("File testdata.in tidak ditemukan.\n");
        return 1;
    }

    int T;
    fscanf(fp, "%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        fscanf(fp, "%d", &N);

        struct Answer answers[N];
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d. %c", &answers[j].number, &answers[j].answerChar);
        }

        sortAnswers(answers, N);

        printf("Case #%d:\n", i);
        for (int j = 0; j < N; j++) {
            printf("%d. %c\n", answers[j].number, answers[j].answerChar);
        }
    }

    fclose(fp);
    return 0;
}