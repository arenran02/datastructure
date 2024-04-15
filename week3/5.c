#include <stdio.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("%c %c\n", from_rod, to_rod);
        return;
    }

    hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("%c %c\n", from_rod, to_rod);
    hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    // printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B'); // 'A', 'C', 'B' are names of rods

    return 0;
}