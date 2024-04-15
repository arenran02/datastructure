#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int mostOnes(int** A, int n) {
    int index = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {


        if (A[i][max] == 1) {
            for (int j = max; j< n; j++) {

                if (A[i][j] == 0) {
                    index = i;
                    max = j;

                  /*  printf("index: %d\n", index);
                    printf("max: %d\n", max);*/
                    break;
                }

                if (j == n - 1 && A[i][j] == 1) {
                    index = i;
                    return index;
                }
            }
        }

    }

    return index;
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int** mymatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mymatrix[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mymatrix[i][j]);
        }
    }

    printf("%d", mostOnes(mymatrix, n));


    for (int i = 0; i < n; i++) {
        free(mymatrix[i]);
    }

    free(mymatrix);

    return 0;
}
