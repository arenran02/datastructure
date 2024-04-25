#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996) // 컴파일러 경고 4996을 무시합니다. (주석 달았습니다.)

// 2D 배열 A에서 가장 많은 1이 있는 행의 인덱스를 반환합니다.
int mostOnes(int** A, int n) {
    int index = 0; // 가장 많은 1이 있는 행의 인덱스
    int max = 0;   // 가장 많은 1의 개수

    // 각 행을 반복하여 가장 많은 1을 찾습니다.
    for (int i = 0; i < n; i++) {
        // 현재 행에서 가장 많은 1이 있는 열을 찾습니다.
        if (A[i][max] == 1) {
            // 현재 행에서 가장 많은 1의 열부터 끝까지 반복합니다.
            for (int j = max; j < n; j++) {
                // 0을 만나면 해당 열의 인덱스와 행의 인덱스를 저장하고 반복을 종료합니다.
                if (A[i][j] == 0) {
                    index = i;
                    max = j;
                    break;
                }
                // 행의 끝까지 도달하고도 1이면 현재 행이 가장 많은 1을 가진 행입니다. 해당 인덱스를 반환합니다.
                if (j == n - 1 && A[i][j] == 1) {
                    index = i;
                    return index;
                }
            }
        }
    }

    return index; // 가장 많은 1을 가진 행의 인덱스를 반환합니다.
}

int main() {
    int n = 0;
    scanf("%d", &n); // 사용자로부터 n 값을 입력 받습니다.

    // n x n 크기의 2D 배열 동적 할당
    int** mymatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mymatrix[i] = (int*)malloc(n * sizeof(int));
    }

    // 사용자로부터 2D 배열의 값을 입력 받습니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mymatrix[i][j]);
        }
    }

    // mostOnes 함수를 호출하여 가장 많은 1을 가진 행의 인덱스를 출력합니다.
    printf("%d", mostOnes(mymatrix, n));

    // 동적으로 할당한 메모리를 해제합니다.
    for (int i = 0; i < n; i++) {
        free(mymatrix[i]);
    }
    free(mymatrix);

    return 0;
}
