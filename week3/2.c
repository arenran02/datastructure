#include <stdio.h>

// 재귀 함수를 사용하여 각 자릿수를 낮은 자릿수부터 출력하는 함수
void printDigits(int num) {
    if (num < 10) {
        printf("%d\n", num);
    } else {
        printDigits(num / 10);
        printf("%d\n", num % 10);
    }
}

int main() {
    int num;
    scanf("%d", &num);

    printDigits(num);

    return 0;
}