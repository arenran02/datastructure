#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ�� ��� ����
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ���� ����Ʈ �ʱ�ȭ �Լ�
void initializeList(Node** head) {
    *head = NULL;
}

// ���ο� ��带 �����ϴ� �Լ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ����Ʈ�� ���ο� ��带 �߰��ϴ� �Լ�
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// �ִ��� �����ϴ� �Լ�
void maxdel(Node** head) {
    if (*head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
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
    printf("�ִ� %d�� �����Ǿ����ϴ�.\n", max);
}

// ����Ʈ�� ������ ����ϴ� �Լ�
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

    // ���÷� �� ���� ��带 �߰�
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 15);
    insert(&head, 25);

    printf("����Ʈ ����: ");
    printList(head);

    maxdel(&head);

    printf("�ִ� ���� �� ����Ʈ ����: ");
    printList(head);

    return 0;
}
