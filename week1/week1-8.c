#include <stdio.h>
#pragma warning(disable:4996)

struct Student {
    char name[50];
    int korean;
    int english;
    int math;
};

void printStudentInfo(struct Student student);

int main() {
    int N;
    scanf("%d", &N);

    struct Student *students = (struct Student *)malloc(N * sizeof(struct Student));

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].korean, &students[i].english, &students[i].math);

        printStudentInfo(students[i]);
    }

    free(students);

    return 0;
}

void printStudentInfo(struct Student student) {
    if (student.korean >= 90 || student.english >= 90 || student.math >= 90) {
        if (student.korean < 70 || student.english < 70 || student.math < 70){
            printf("%s %.1f GREAT BAD\n", student.name, (float)(student.korean + student.english + student.math) / 3);
        }

        else {
            printf("%s %.1f GREAT\n", student.name, (float)(student.korean + student.english + student.math) / 3);
        }
        
    } else if (student.korean < 70 || student.english < 70 || student.math < 70) {
        printf("%s %.1f BAD\n", student.name, (float)(student.korean + student.english + student.math) / 3);
    }
}