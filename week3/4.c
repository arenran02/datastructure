#include <stdio.h>

// 배열에서 최댓값을 찾는 재귀 함수
int findMax(int arr[], int n) {
    // 기저 사례: 배열의 크기가 1이면 해당 원소가 최댓값
    if (n == 1) {
        return arr[0];
    }
    // 배열의 처음과 두 번째 원소 중 더 큰 값을 선택하여 재귀 호출
    int max_rest = findMax(arr + 1, n - 1);
    // 현재 원소와 나머지 배열의 최댓값을 비교하여 더 큰 값을 반환
    return (arr[0] > max_rest) ? arr[0] : max_rest;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // 최댓값 출력
    printf("%d", findMax(arr, n));

    return 0;
}