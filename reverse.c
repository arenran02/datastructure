#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 노드 구조체 정의
struct ListNode {
    int val;
    struct ListNode *next;
};

// 연결 리스트를 역전시키는 함수
struct ListNode* reverseLinkedList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    return prev;
}

// 연결 리스트 노드를 생성하는 함수
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 연결 리스트를 출력하는 함수
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// 메모리 해제 함수
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

// 메인 함수
int main() {
    // 테스트용 연결 리스트 생성
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printLinkedList(head);

    // 연결 리스트 역전
    head = reverseLinkedList(head);

    printf("Reversed Linked List: ");
    printLinkedList(head);

    // 메모리 해제
    freeLinkedList(head);

    return 0;
}
