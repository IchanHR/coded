#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_hearts() {
    printf("\u2665\u2665\u2665\u2665\u2665\u2665\u2665\u2665\u2665\u2665\n");
}

void inputD(const char *prompt, char *name, int *age) {
    printf("%s\n", prompt);
    print_hearts();
    printf("Masukkan Nama         : ");
    fgets(name, 50, stdin);
    printf("Masukkan Umur         : ");
    scanf("%d", age);
    getchar();
}

float calcR() {
    int X;
    srand((unsigned int)time(NULL));
    X = rand() % 51 + 50;
    return X / 1.1;
}

int main() {
    char name[50], coupleName[50];
    int age, coupleAge;
    float comp;

    printf("Selamat Datang Di Program Ramalan Cupu\n");
    printf("+++++++++++++++++++++++++++++++++++++++\n\n");

    inputD("Data Anda :", name, &age);
    inputD("\nData Pasangan Anda :", coupleName, &coupleAge);

    printf("\n\nHasil Ramalan:\n");
    printf("Nama Anda         : %s", name);
    printf("Umur Anda         : %d\n", age);
    printf("Nama Pasangan Anda: %s", coupleName);
    printf("Umur Pasangan     : %d\n", coupleAge);

    comp = calcR();
    printf("\nTingkat Kecocokan : %.2f%%\n", comp);

    printf("\nTerima kasih telah menggunakan program ramalan cupu!\n");
    return 0;
}
