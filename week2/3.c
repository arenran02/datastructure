#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void prefixAverages1(int* X, int n) {
    float* A = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            A[i] += X[j];
        }

        float average = A[i] / (i + 1);

        if (average - (int)average >= 0.5) {
            average++;
        }

        printf("%d ", (int)average);
    }

    printf("\n");  // 결과 출력 후 줄바꿈 추가

    free(A);
}

void prefixAverages2(int* X, int n) {
    float sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += X[i];
        float average = sum / (i + 1);

        if (average - (int)average >= 0.5) {
            average++;
        }

        printf("%d ", (int)average);
    }

    printf("\n");  // 결과 출력 후 줄바꿈 추가
}

int main() {
    int n = 0;
    //printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* X = (int*)malloc(n * sizeof(int));
    if (X == NULL) {
        // 동적 할당 실패
        //printf("Memory allocation failed.\n");
        return 1;
    }

    //printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    //printf("Prefix Averages 1:\n");
    prefixAverages1(X, n);

    //printf("Prefix Averages 2:\n");
    prefixAverages2(X, n);

    // 동적 할당한 메모리 해제
    free(X);

    return 0;
}
