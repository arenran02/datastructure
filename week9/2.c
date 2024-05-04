#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX_LENGTH 1000

// 스택 구조체 정의
typedef struct {
    char items[MAX_LENGTH];
    int top;
} Stack;

// 스택 초기화 함수
void initStack(Stack *s) {
    s->top = -1;
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack *s) {
    return (s->top == -1);
}

// 스택에 요소를 추가하는 함수
void push(Stack *s, char item) {
    s->items[++(s->top)] = item;
}

// 스택에서 요소를 제거하고 반환하는 함수
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// 괄호의 총 개수를 반환하는 함수
int countParentheses(char *expression) {
    int count = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{' || ch == ')' || ch == ']' || ch == '}') {
            count++;
        }
    }

    return count;
}

// 괄호 짝 검사 함수
bool isValidExpression(char *expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&stack)) {
                return false;
            } else {
                char top = pop(&stack);
                // 괄호 짝이 맞지 않으면 유효하지 않음
                if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }
    }

    // 스택이 비어있어야 유효한 표현식
    return isEmpty(&stack);
}

int main() {
    char expression[MAX_LENGTH];
    fgets(expression, MAX_LENGTH, stdin);

    // 개행 문자 제거
    expression[strcspn(expression, "\n")] = '\0';

    int totalCount = countParentheses(expression);
    bool isValid = isValidExpression(expression);

    if (isValid) {
        printf("OK_%d\n", totalCount);
    } else {
        printf("Wrong_%d\n", totalCount);
    }

    return 0;
}
