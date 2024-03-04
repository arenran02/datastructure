#include <stdio.h>
#pragma warning(disable:4996)

int sum(int n) {
    int result = 0;
    
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    
    return result;
}

int main() {
    int n=0;
    int total=0;

    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        total+=sum(i);
    }

    printf("%d", total);
    
    return 0;
}