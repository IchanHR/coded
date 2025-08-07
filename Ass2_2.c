#include <stdio.h>
#include <stdlib.h>

struct Answer {
    int number;
    char answer;
};

int cmp(const void *a, const void *b) {
    struct Answer *x = (struct Answer*)a;
    struct Answer *y = (struct Answer*)b;
    return x->number - y->number;
}

int main() {
    FILE *fp = fopen("testdata2.in", "r");
    if (!fp) {
        printf("File testdata.in not found!\n");
        return 1;
    }
    int T;
    fscanf(fp, "%d", &T);
    for (int t = 0; t < T; t++) {
        int N;
        fscanf(fp, "%d", &N);
        struct Answer arr[100];
        for (int i = 0; i < N; i++) {
            fscanf(fp, "%d.%c", &arr[i].number, &arr[i].answer);
        }
        qsort(arr, N, sizeof(struct Answer), cmp);
        for (int i = 0; i < N; i++) {
            printf("%d.%c\n", arr[i].number, arr[i].answer);
        }
    }
    fclose(fp);
    return 0;
}
