#include <stdio.h>

// 재귀 함수를 사용하여 1부터 N까지의 합을 구하는 함수
int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", sum(n));

    return 0;
}