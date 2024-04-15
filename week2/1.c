#include <stdio.h>
#pragma warning(disable:4996)

void modulo(int a, int b) {
	int temp = 0;
	temp = a / b;
	//printf("temp=%d", temp);

	int remain = 0;
	remain = temp * b - a;
	if (remain < 0) {
		remain *= -1;
	}

	printf("%d", remain);

}

int main() {

	int a, b;
	scanf("%d %d", &a, &b);
	modulo(a, b);

	return 0;
}