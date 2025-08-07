#include <stdio.h>
#include <stdlib.h>

void tambahSatu(int x) {
    x = x + 1;
    printf("Nilai di dalam tambahSatu (pass by value): %d\n", x);
}

void tambahSatuRef(int *x) {
    *x = *x + 1;
    printf("Nilai di dalam tambahSatuRef (pass by reference): %d\n", *x);
}

int main() {
    int a, b;
    printf("Masukkan nilai awal a: ");
    scanf("%d", &a);
    printf("Nilai awal a: %d\n", a);
    tambahSatu(a);
    printf("Nilai a setelah tambahSatu: %d\n\n", a);

    printf("Masukkan nilai awal b: ");
    scanf("%d", &b);
    printf("Nilai awal b: %d\n", b);
    tambahSatuRef(&b);
    printf("Nilai b setelah tambahSatuRef: %d\n", b);
    return 0;
}
