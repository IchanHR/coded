#include <stdio.h>

void binary(int n) {
    int bits[32], idx = 0; //declaring needed varibales for the function
    if (n == 0) { //checking if the inputted variable is 0
        printf("0"); //output 0 if yes
        return; //return nothing
    }
    //input variable checking
    while (n > 0) { //as long as the inputted variable is bigger than 0 loop it
        bits[idx++] = n % 2; //
        n /= 2;
    }
    //reversing
    for (int i = idx - 1; i >= 0; i--) { //looping through the bits array in reverse order
        printf("%d", bits[i]); //displaying the bits in reverse order
    }
}

int main() {
    int T, N; //declaring needed variables for the main function
    scanf("%d", &T); //asking for test case input
    for (int tc = 1; tc <= T; tc++) { //looping through the test cases
        scanf("%d", &N); //asking for the input of the number to be converted to binary number
        printf("Case #%d: ", tc); //displaying the test case number 
        binary(N); //converting using the function above the main function
        printf("\n"); //prompting next line each display
    }
    return 0;
}