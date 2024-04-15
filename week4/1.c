#include <stdio.h>
#include <stdlib.h>

// 뒤집는 함수
void reverse_subsequence(int *sequence, int start, int end) {
    int temp;
    while (start < end) {
        temp = sequence[start];
        sequence[start] = sequence[end];
        sequence[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int N, P;
    
    // N 입력받기
    scanf("%d", &N);
    
    // 수열 입력받기
    int *sequence = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }
    
    // 뒤집을 횟수 입력받기
    scanf("%d", &P);
    
    // 뒤집을 횟수만큼 뒤집을 구간 입력받고 수행하기
    for (int i = 0; i < P; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        reverse_subsequence(sequence, start, end); // 0-based index로 변환
    }
    
    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", sequence[i]);
    }
    
    // 메모리 해제
    free(sequence);
    
    return 0;
}
