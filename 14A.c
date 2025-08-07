#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int input_tebakan(int ke) {
    int tebakan;
    printf("Tebakan ke %d : ", ke);
    scanf("%d", &tebakan);
    return tebakan;
}

char tanya_ulang() {
    char ulang;
    printf("\nMau Mengulang permainan [Y/T] : ");
    while ((getchar()) != '\n'); 
    ulang = getchar();
    ulang = toupper(ulang);
    while ((getchar()) != '\n' && !feof(stdin));
    printf("\n");
    return ulang;
}

void main_game() {
    int angka, tebakan, menang = 0;
    srand((unsigned int)time(NULL));
    angka = rand() % 100 + 1;

    printf("Tebak angka [1-100], anda mempunyai 5 kesempatan\n");

    for (int i = 1; i <= 5; i++) {
        tebakan = input_tebakan(i);
        if (tebakan > angka) {
            printf("TEBAKAN TERLALU BESAR\n");
        } else if (tebakan < angka) {
            printf("TEBAKAN TERLALU KECIL\n");
        } else {
            printf("ANDA MENANG\n");
            menang = 1;
            break;
        }
    }

    if (!menang) {
        printf("PERMAINAN SELESAI\n");
        printf("Jawaban yang benar adalah: %d\n", angka);
    }
}

int main() {
    char ulang;
    do {
        main_game();
        ulang = tanya_ulang();
    } while (ulang == 'Y');
    printf("Terima kasih telah bermain!\n");
    return 0;
}
