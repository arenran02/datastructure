#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void push(char* stack, char data, int* top, int size) {
    if (*top >= size - 1) {
        printf("Stack FULL\n");
    }
    else {
        stack[++(*top)] = data;
    }
}

char pop(char* stack, int* top) {
    if (*top < 0) {
        printf("Stack Empty\n");
        return '\0';
    }
    else {
        return stack[(*top)--];
    }
}

void peek(char* stack, int top) {
    if (top < 0) {
        printf("Stack Empty\n");
    }
    else {
        printf("%c\n", stack[top]);
    }
}

// void duplicate(char* stack, int* top){
//     if (*top >= strlen(stack) - 1) {
//         return;
//     }

//     else {
//         stack[(*top)+1]=stack[(*top)]; 
//         (*top)++;
//     }

// }

void duplicate(char* stack, int* top, int size){
    if (*top >= size - 1) {
        printf("Stack FULL\n");
        return;
    }

    stack[(*top)+1]=stack[(*top)]; 
    (*top)++;
}

void upRotate(char* stack, int top, char value) {
    int index = value - '0';
    
    if (index > top+1) {
        return;
    }

    char temp = stack[top];

    for (int i = top-1; i > top-index; i--) {
        stack[i+1] = stack[i];
    }

    stack[top-index+1]=temp;
}

void downRotate(char* stack, int top, char value) {
    int index = value - '0';

    if (index > top+1) {
        return;
    }

    char temp = stack[top-index+1];

    for (int i = top-index+2; i < top+1; i++) {
        stack[i-1] = stack[i];
    }
    stack[top] = temp;
}

void print(char* stack, int top) {
    for (int i = top; i >= 0; i--) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int IsEmpty(int top){
    return (top < 0);
}

int main() {
    int size, num;
    char input[200];
    int top = -1;

    scanf("%d", &size);
    scanf("%d", &num);
    getchar(); // 입력 버퍼 비우기

    char* stack = (char*)malloc(size * sizeof(char));

    for (int i = 0; i < num; i++) {
        fgets(input, sizeof(input), stdin);

        char* command = strtok(input, " \n");
        char* value = strtok(NULL, " \n");

        if (strcmp(command, "PUSH") == 0) {
            push(stack, *value, &top, size);
        }
        else if (strcmp(command, "POP") == 0) {
            pop(stack, &top);
        }
        else if (strcmp(command, "PEEK") == 0) {
            peek(stack, top);
        }
        else if (strcmp(command, "DUP") == 0) {
            duplicate(stack, &top, size);
        }
        else if (strcmp(command, "UpR") == 0) {
            upRotate(stack, top, *value);
        }
        else if (strcmp(command, "DownR") == 0) { 
            downRotate(stack, top, *value);
        }
        else if (strcmp(command, "PRINT") == 0) {
            print(stack, top);
        }
        
    }
    
    free(stack);
    return 0;
}
