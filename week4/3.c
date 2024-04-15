#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    // 행렬 크기 입력받기
    scanf("%d", &N);

    // 행렬 동적 할당
    int **matrix = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }

    // 행렬 채우기
    int count = 1;
    for (int i = 0; i < N; i++) {
        // 짝수 행: 오른쪽 방향
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = count++;
            }
        }
        // 홀수 행: 왼쪽 방향
        else {
            for (int j = N - 1; j >= 0; j--) {
                matrix[i][j] = count++;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 동적 할당 해제
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
