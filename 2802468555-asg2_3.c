#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("testdata3.in", "r");
    if (fp == NULL) {
        printf("File testdata.in tidak ditemukan.\n");
        return 1;
    }

    int T;
    fscanf(fp, "%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        fscanf(fp, "%d", &N);

        char names[N][31];
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%s", names[j]);
        }

        char nameToFind[31];
        fscanf(fp, "%s", nameToFind);

        int foundIndex = -1;
        for (int j = 0; j < N; j++) {
            if (strcmp(names[j], nameToFind) == 0) {
                foundIndex = j + 1;
                break;
            }
        }
        
        printf("Case #%d: ", i);
        if (foundIndex != -1) {
            printf("%d\n", foundIndex);
        } else {
            printf("Not found\n");
        }
    }
    
    fclose(fp);
    return 0;
}