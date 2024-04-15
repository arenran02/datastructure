#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    // 최대공약수 계산
    int result = gcd(num1, num2);

    printf("%d", result);

    return 0;
}
