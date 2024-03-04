#include <stdio.h>
#pragma warning(disable:4996)

void swap(int *a, int *b);

int main(){
    int input=0;
    scanf("%d", &input);

    int arr[input];
    for (int i=0; i<input; i++){
        scanf("%d ", &arr[i]);
    }

    int index1, index2;
    scanf("%d %d", &index1, &index2);

    swap(&arr[index1], &arr[index2]);
    for(int i=0; i<input; i++){
        printf("%d ", arr[i]);
    }

    return 0;

}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}