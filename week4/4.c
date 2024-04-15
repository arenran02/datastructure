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

    // 행렬 채우기
    int count = 1;
    int startRow = 0, endRow = M - 1;
    int startCol = 0, endCol = N - 1;
    while (startRow <= endRow && startCol <= endCol) {
        // 위쪽 행 채우기
        for (int i = startCol; i <= endCol; i++) {
            matrix[startRow][i] = count++;
        }
        startRow++;

        // 오른쪽 열 채우기
        for (int i = startRow; i <= endRow; i++) {
            matrix[i][endCol] = count++;
        }
        endCol--;

        // 아래쪽 행 채우기
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                matrix[endRow][i] = count++;
            }
            endRow--;
        }

        // 왼쪽 열 채우기
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                matrix[i][startCol] = count++;
            }
            startCol++;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 동적 할당 해제
    for (int i = 0; i < M; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;

}