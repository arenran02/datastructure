#include <stdio.h>
#pragma warning (disable:4996)

void ABC(int arr[], int k);

int main(){

    int arr[10];
    for (int i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<10; i++){
        ABC(arr, i);
    }

    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void ABC(int arr[10], int k) {
    int maxIndex = k;
    for (int i = k + 1; i < 10; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    int temp = arr[k];
    arr[k] = arr[maxIndex];
    arr[maxIndex] = temp;
}