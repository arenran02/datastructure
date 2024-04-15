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

    // 바꿈 정보 수열 입력받고 처리하기
    int *swap_indices = (int *)malloc(P * sizeof(int));
    for (int i = 0; i < P; i++) {
        scanf("%d", &swap_indices[i]);
    }

    int *sequence2 = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < P - 1; i ++) {
        int src_index = swap_indices[i];
        int dest_index = swap_indices[i + 1];

        sequence2[dest_index]=sequence[src_index];
    }

    for (int i=0; i<N; i++){
        if (sequence2[i]==NULL){
            sequence2[i]=sequence[i];
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", sequence2[i]);
    }

    // 동적 할당 해제
    free(sequence);
    free(swap_indices);
    free(sequence2);

    return 0;
}