#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void leftShift(char *str);

int main() {
    char inputString[100];
    scanf("%s", inputString);
    printf("%s\n", inputString);
    
    for (int i=0; i<strlen(inputString)-1; i++){
        leftShift(inputString);
        printf("%s\n", inputString);
    }

    return 0;
}

void leftShift(char *str) {
    int length = strlen(str);
    char temp = str[0];

    for (int i = 1; i < length; i++) {
        str[i - 1] = str[i];
    }

    str[length - 1] = temp;
}