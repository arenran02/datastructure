#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N;

    // 행렬 크기 입력받기
    scanf("%d %d", &M, &N);

    // 행렬 동적 할당
    int **matrix = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }

    // 행렬 채우기 - 패턴에 따라 숫자 채워넣기
    int count = 1;
    for (int col = 0; col < N; col++) {
        int row = 0;
        // 대각선 방향으로 숫자를 채워넣기
        for (int j = col; j >= 0 && row < M; j--) {
            matrix[row][j] = count++;
            row++;
        }
    }
    
    // 맨 아래 행의 나머지 부분 채우기
    for (int row = 1; row < M; row++) {
        int col = N - 1;
        // 대각선 방향으로 숫자를 채워넣기
        for (int j = row; j < M && col >= 0; j++) {
            matrix[j][col] = count++;
            col--;
        }
    }

    // 결과 출력
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // 행 출력 후 줄바꿈
    }

    // 동적 할당 해제
    for (int i = 0; i < M; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
