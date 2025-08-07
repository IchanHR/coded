#include <stdio.h>

struct RectangularPrism {
    int L;
    int W;
    int H;
};

int Calc(struct RectangularPrism block) {
    return block.L * block.W * block.H;
}

int main() {
    struct RectangularPrism block;
    char repeat;
    do {
        printf("Masukkan panjang (P): ");
        scanf("%d", &block.L);
        printf("Masukkan lebar (L): ");
        scanf("%d", &block.W);
        printf("Masukkan tinggi (T): ");
        scanf("%d", &block.H);

        int volume = Calc(block);
        printf("Volume = %d\n", volume);

        getchar();
        printf("\nAkan mengulang perhitungan? [Y/T]: ");
        repeat = getchar();
    } while (repeat == 'Y' || repeat == 'y');

    printf("Terima kasih!\n");
    return 0;
}

