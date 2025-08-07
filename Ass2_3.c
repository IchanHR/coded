#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("testdata3.in", "r");
    if (!fp) {
        printf("File testdata.in not found!\n");
        return 1;
    }
    int T;
    fscanf(fp, "%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        fscanf(fp, "%d", &N);
        char names[105][35];
        for (int i = 0; i < N; i++) {
            fscanf(fp, "%s", names[i]);
        }
        char search[35];
        fscanf(fp, "%s", search);
        int get = 0;
        for (int i = 0; i < N; i++) {
            if (strcmp(names[i], search) == 0) {
                printf("Case #%d: %d\n", t, i+1);
                get = 1;
                break;
            }
        }
        if (!get) {
            printf("Case #%d: Not found\n", t);
        }
    }
    fclose(fp);
    return 0;
}
