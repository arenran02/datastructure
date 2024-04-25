#include <stdio.h>
#include <stdlib.h>

// 주어진 배열에서 start부터 end까지의 구간을 뒤집는 함수
void reverse_subsequence(int *sequence, int start, int end) {
    int temp;
    // start부터 end까지의 구간을 반복하여 뒤집습니다.
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
    
    // 수열의 길이 입력받기
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
        reverse_subsequence(sequence, start, end); // start부터 end까지의 구간을 뒤집음
    }
    
    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", sequence[i]);
    }
    
    // 동적으로 할당한 메모리 해제
    free(sequence);
    
    return 0;
}
