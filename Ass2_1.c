#include <stdio.h>

int isPrimeRecursive(int x, int divisor) {
    if (x < 2) return 0;
    if (divisor == 1) return 1;
    if (x % divisor == 0) return 0;
    return isPrimeRecursive(x, divisor - 1);
}

int isPrime(int x) {
    return isPrimeRecursive(x, x - 1);
}

int main() {
    int T, X;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &X);
        printf("Case #%d: %s\n", i, isPrime(X) ? "Prime Number" : "Not Prime Number");
    }
    return 0;
}
