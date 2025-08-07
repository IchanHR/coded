#include <stdio.h>

int main() {
    int X;

    //Asking user to input a number between 1 and 1000
    printf("Input Number (1-1000): ");
    scanf("%d", &X);

    //If the input is not in the range, prompt again, using this input validation loop technique
    while (X < 1 || X > 1000) {
        printf("Please Input Number between 1 and 1000: ");
        scanf("%d", &X);
    }

    //Checking if the number is even or odd
    if (X % 2 == 0) {
        printf("%d is even number\n", X); //displaying if the number is even
    } else {
        printf("%d is odd number\n", X); //displaying if the number is odd
    }

    return 0;
}
