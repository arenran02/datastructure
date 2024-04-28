#include <stdio.h>
#pragma warning(disable:4996)

int pascal(int n, int k) {
	if (k == 0 || k == n) return 1;
	return pascal(n - 1, k-1) + pascal(n - 1, k);
}

int main() {

	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);
	if (num1 >= 1 && num2 >= 1) {
		printf("%d", pascal(num1 - 1, num2 - 1));
	}

	return 0;
}
