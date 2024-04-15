#include <stdio.h>
#include <stdlib.h>

// 다항식의 각 항을 표현하는 노드 구조체
struct Node {
    int num;
    struct Node* next; // 다음 노드를 가리키는 포인터
};

// 다항식 출력 함수
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->num);
        node = node->next;
    }
    printf("\n");
}

// 다항식의 부분집합 여부 확인 함수
int subset(struct Node* a, struct Node* b) {
    // 두 다항식이 모두 비어있는 경우
    if (a == NULL && b == NULL)
        return 0;

    // 다항식 b가 비어있는 경우
    if (b == NULL&&a!=NULL)
        return a->num;

    // 다항식 a가 비어있는 경우
    if (a == NULL&&b!=NULL)
        return 0;

    // 다항식 a를 순회하면서 각 항이 다항식 b에 포함되어 있는지 확인
    struct Node* tempA = a;
    while (tempA != NULL) {
        struct Node* tempB = b;
        int found = 0; // 다항식 b에 현재 항이 존재하는지 여부를 나타내는 플래그
        while (tempB != NULL) {
            if (tempA->num == tempB->num) {
                found = 1; // 다항식 b에 현재 항이 존재함
                break;
            }
            tempB = tempB->next;
        }
        // 다항식 b에 현재 항이 존재하지 않으면 subset이 아님
        if (!found)
            return tempA->num;
        tempA = tempA->next;
    }
    // 다항식 a의 모든 항이 다항식 b에 포함되어 있으면 a는 b의 subset임
    return 0;
}

// 다항식에 항 추가 함수
void addTerm(struct Node** a, int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->num = n;
    newNode->next = NULL;

    // 다항식이 비어있을 경우
    if (*a == NULL) {
        *a = newNode;
    } else {
        struct Node* temp = *a;
        // 마지막 노드까지 이동
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // 새로운 노드를 마지막 노드의 다음에 추가
        temp->next = newNode;
    }
}

int main() {
    struct Node* MyNode1 = NULL;
    struct Node* MyNode2 = NULL;

    // 첫 번째 다항식의 크기를 입력 받음
    int num1;
    scanf("%d", &num1);
    int temp = 0;

    if (num1 != 0){
        // 첫 번째 다항식의 항을 입력 받음
        for (int i = 0; i < num1; i++) {
            scanf("%d ", &temp);
            addTerm(&MyNode1, temp);
        }
    }
   

    // 두 번째 다항식의 크기를 입력 받음
    int num2;
    scanf("%d", &num2);

    if (num2 != 0){
        // 두 번째 다항식의 항을 입력 받음
        for (int i = 0; i < num2; i++) {
            scanf("%d ", &temp);
            addTerm(&MyNode2, temp);
        }
    }

    // subset 함수 호출하여 두 다항식이 부분집합인지 확인
    printf("%d", subset(MyNode1, MyNode2));

    return 0;
}
