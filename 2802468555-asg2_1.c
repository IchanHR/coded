#include <stdio.h>
#include <math.h>

int isPrimeRecursive(int x, int i) {
    if (x <= 1) {
        return 0;
    }
    if (x == 2) {
        return 1;
    }
    if (x % i == 0) {
        return 0;
    }
    if (i * i > x) {
        return 1;
    }
    return isPrimeRecursive(x, i + 1);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int X;
        scanf("%d", &X);

        printf("Case #%d: ", i);
        if (isPrimeRecursive(X, 2)) {
            printf("Prime Number\n");
        } else {
            printf("Not Prime Number\n");
        }
    }
    return 0;
}
