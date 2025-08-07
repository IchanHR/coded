#include <stdio.h>

int main() {
    int size;
    char shape;

    printf("Input Size [5-10] : ");
    scanf("%d", &size);
    
    while (size < 5 || size > 10) {
        printf("Please Input Size between this constraints [5-10] : ");
        scanf("%d", &size);
    }

    printf("Choose Shape [K/S] : ");
    scanf(" %c", &shape);

    while (shape != 'K' && shape != 'k' && shape != 'S' && shape != 's') {
        printf("Choose Shape K(Square) or S(Triangle) : ");
        scanf(" %c", &shape);
    }

    printf("Result :\n");

    if (shape == 'K' || shape == 'k') {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else {
        for (int i = 1; i <= size; i++) {
            for (int s = 0; s < size - i; s++) {
                printf("  ");
            }
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}