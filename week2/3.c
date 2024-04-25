#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996) // 컴파일러 경고 4996을 무시합니다.

// X 배열의 접두사 평균을 계산하여 출력합니다. 첫 번째 방법입니다.
void prefixAverages1(int* X, int n) {
    // 각 접두사 합을 저장할 배열을 동적으로 할당합니다.
    float* A = (float*)malloc(n * sizeof(float));

    // A 배열을 모두 0으로 초기화합니다.
    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }

    // 각 위치마다 접두사 평균을 계산하고 출력합니다.
    for (int i = 0; i < n; i++) {
        // 현재 위치까지의 합을 계산합니다.
        for (int j = 0; j <= i; j++) {
            A[i] += X[j];
        }

        // 접두사 평균을 계산합니다.
        float average = A[i] / (i + 1);

        // 평균을 반올림합니다.
        if (average - (int)average >= 0.5) {
            average++;
        }

        // 평균을 정수로 변환하여 출력합니다.
        printf("%d ", (int)average);
    }

    printf("\n");  // 결과 출력 후 줄바꿈 추가

    free(A); // 동적으로 할당한 배열을 해제합니다.
}

// X 배열의 접두사 평균을 계산하여 출력합니다. 두 번째 방법입니다.
void prefixAverages2(int* X, int n) {
    float sum = 0.0;

    // 각 위치마다 접두사 평균을 계산하고 출력합니다.
    for (int i = 0; i < n; i++) {
        // 현재 위치까지의 합을 계산합니다.
        sum += X[i];

        // 접두사 평균을 계산합니다.
        float average = sum / (i + 1);

        // 평균을 반올림합니다.
        if (average - (int)average >= 0.5) {
            average++;
        }

        // 평균을 정수로 변환하여 출력합니다.
        printf("%d ", (int)average);
    }

    printf("\n");  // 결과 출력 후 줄바꿈 추가
}

int main() {
    int n = 0;
    scanf("%d", &n); // 사용자로부터 배열의 크기를 입력 받습니다.

    // 배열 X를 동적으로 할당합니다.
    int* X = (int*)malloc(n * sizeof(int));
    if (X == NULL) {
        // 동적 할당 실패 시 오류를 출력하고 종료합니다.
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 배열의 요소를 사용자로부터 입력 받습니다.
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    // 첫 번째 방법으로 접두사 평균을 계산하고 출력합니다.
    prefixAverages1(X, n);

    // 두 번째 방법으로 접두사 평균을 계산하고 출력합니다.
    prefixAverages2(X, n);

    // 동적으로 할당한 메모리를 해제합니다.
    free(X);

    return 0;
}
