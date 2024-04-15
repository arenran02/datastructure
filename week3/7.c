#include <stdio.h>

// 재귀 함수를 사용하여 문자열에서 특정 문자의 등장 횟수를 검사하는 함수
int countOccurrences(char *str, char target) {
    if (*str == '\0') {
        return 0;
    }
    if (*str == target) {
        return 1 + countOccurrences(str + 1, target);
    }
    return countOccurrences(str + 1, target);
}

int main() {
    char str[100]; 
    char target;
    scanf("%s", str);

    scanf(" %c", &target); 

    // 문자열에서 특정 문자가 몇 번 등장하는지 검사
    int occurrences = countOccurrences(str, target);
    printf("%d", occurrences);

    return 0;
}