#include <stdio.h>
#include <string.h>

void reverse(char *s, int left, int right) {
    if (left >= right) return; //checking if left is bigger and eaqual to right if yes continue the function
    char temp = s[left]; //declaring variable temp as the left part of the inputted strings
    s[left] = s[right]; //setting left to right
    s[right] = temp; //setting right to temp
    reverse(s, left + 1, right - 1); //recursive the function.
}

int main() {
    int T;
    scanf("%d", &T); //input test case
    for (int tc = 1; tc <= T; tc++) { //loop within the inputted test case
        char s[1005]; //declaring the given variable as strings for better accuracy 
        scanf("%s", s); //inputting the variables
        int len = strlen(s); //checking the string length using strlen function from the string.h library
        reverse(s, 0, len - 1); //reversing using reverse function above the main function
        printf("Case #%d: %s\n", tc, s); //output the result for each cases
    }
    return 0;
}