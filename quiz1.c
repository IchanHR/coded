#include<stdio.h>

int main(){
    char ss[100];
    scanf("%[^0-9]", ss);
    printf("%s\n", ss);
    return 0;
}