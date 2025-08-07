#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int number;
    char answer;
} Data;

int comp(const void* a, const void* b) {
    return ((Data*)a)->number - ((Data*)b)->number;
}

int main() {
    FILE *fp = fopen("testdata2.in", "r");
    int T;
    fscanf(fp, "%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        fscanf(fp, "%d", &N);
        Data answers[100];

        for (int i = 0; i < N; i++) {
            fscanf(fp, "%d. %c", &answers[i].number, &answers[i].answer);
        }

        qsort(answers, N, sizeof(Data), comp);

        printf("Case #%d:\n", t);
        for (int i = 0; i < N; i++) {
            printf("%d. %c\n", answers[i].number, answers[i].answer);
        }
    }

    fclose(fp);
    return 0;
}