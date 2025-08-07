#include <stdio.h>
#include <stdlib.h>

int digitCounterIteration(int n) {
    int count = 0;
    if (n == 0) return 1;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int digitCounterRecursion(int n) {
    if (n == 0) return 0;
    return 1 + digitCounterRecursion(n / 10);
}

int main() {
    int num;
    printf("Masukkan sebuah angka: ");
    scanf("%d", &num);

    printf("Jumlah digit (iteratif): %d\n", digitCounterIteration(num));
    // Untuk angka 0, rekursif harus dikoreksi agar hasilnya 1
    if (num == 0)
        printf("Jumlah digit (rekursif): 1\n");
    else
        printf("Jumlah digit (rekursif): %d\n", digitCounterRecursion(num));

    return 0;
}
