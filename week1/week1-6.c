#include <stdio.h>
#pragma warning(disable:4996)

struct Student {
    char name[20];
    int score;
};

int main() {

    struct Student students[5];

    int num = 5;
    int sum = 0;

    for (int i = 0; i < num; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
        sum += students[i].score;
    }

    float avg = (float)sum / num; 

    for (int i = 0; i < num; i++) {
        if (students[i].score <= avg) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}