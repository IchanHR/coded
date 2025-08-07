#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("testdata3.in", "r");
    int T;
    fscanf(fp, "%d\n", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        fscanf(fp, "%d\n", &N);
        char names[100][31], target[31];
        for (int i = 0; i < N; i++) {
            fgets(names[i], 31, fp);
            names[i][strcspn(names[i], "\n")] = 0;
        }
        fgets(target, 31, fp);
        target[strcspn(target, "\n")] = 0;

        int get = 0;
        for (int i = 0; i < N; i++) {
            if (strcmp(names[i], target) == 0) {
                printf("Case #%d: %d\n", t, i + 1);
                get = 1;
                break;
            }
        }
        if (!get)
            printf("Case #%d: Not found\n", t);
    }

    fclose(fp);
    return 0;
}