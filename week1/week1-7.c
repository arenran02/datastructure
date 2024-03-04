#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
    int N;
    scanf("%d", &N);

    int *arr1 = (int *)malloc(N * sizeof(int));
    int *arr2 = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i=0; i<N; i++){
        printf("%d ", arr1[i]+arr2[N-1-i]);
    }

    free(arr1);
    free(arr2);

    return 0;
}