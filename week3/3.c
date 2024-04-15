#include <stdio.h>

// 재귀 함수를 사용하여 각 자릿수를 반대 순서로 출력하는 함수
void printDigitsReverse(int num) {
    if (num < 10) {
        printf("%d\n", num);
    } else {
        printf("%d\n", num % 10);
        printDigitsReverse(num / 10);
    }
}

int main() {
    int num;
    scanf("%d", &num);

    printDigitsReverse(num);

    return 0;
}