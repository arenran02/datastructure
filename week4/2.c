#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, P;

    // N 입력받기
    scanf("%d", &N);

    // 수열 입력받기
    int *sequence = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }

    // 바꿈 정보의 개수 입력받기
    scanf("%d", &P);

    // 바꿈 정보 수열 입력받기
    int *swap_indices = (int *)malloc(P * sizeof(int));
    for (int i = 0; i < P; i++) {
        scanf("%d", &swap_indices[i]);
    }

    // 새로운 수열을 저장할 배열 동적 할당
    int *sequence2 = (int *)malloc(N * sizeof(int));

    // 바꿈 정보를 기반으로 새로운 수열 생성
    for (int i = 0; i < P - 1; i ++) {
        int src_index = swap_indices[i]; // 바꾸기 전 인덱스
        int dest_index = swap_indices[i + 1]; // 바꿀 인덱스

        sequence2[dest_index] = sequence[src_index]; // 바꿀 인덱스에 바꾸기 전 값을 저장
    }

    // 나머지 위치에 원래 수열의 값 복사
    for (int i = 0; i < N; i++) {
        if (sequence2[i] == 0) { // 새로운 수열의 해당 인덱스가 비어있는 경우
            sequence2[i] = sequence[i]; // 원래 수열의 값 복사
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", sequence2[i]);
    }

    // 동적으로 할당한 메모리 해제
    free(sequence);
    free(swap_indices);
    free(sequence2);

    return 0;
}
