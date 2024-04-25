#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 연결 리스트 초기화 함수
void initializeList(Node** head) {
    *head = NULL;
}

// 새로운 노드를 생성하는 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트에 새로운 노드를 추가하는 함수
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// 최댓값을 삭제하는 함수
void maxdel(Node** head) {
    if (*head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    
    Node* current = *head;
    Node* prev = NULL;
    Node* maxNode = *head;
    Node* prevMaxNode = NULL;
    int max = (*head)->data;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
            maxNode = current;
            prevMaxNode = prev;
        }
        prev = current;
        current = current->next;
    }

    if (maxNode == *head) {
        *head = (*head)->next;
    } else {
        prevMaxNode->next = maxNode->next;
    }

    free(maxNode);
    printf("최댓값 %d가 삭제되었습니다.\n", max);
}

// 리스트의 내용을 출력하는 함수
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head;
    initializeList(&head);

    // 예시로 몇 개의 노드를 추가
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 15);
    insert(&head, 25);

    printf("리스트 내용: ");
    printList(head);

    maxdel(&head);

    printf("최댓값 삭제 후 리스트 내용: ");
    printList(head);

    return 0;
}
