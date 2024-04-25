#include <stdio.h>

int main(){
    int x[10];
    x[0]=100;
    x[1]=200;
    printf("%u\n", &x[0]);
    printf("%u\n", &x[1]);

    return 0;
}