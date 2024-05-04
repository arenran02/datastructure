#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��� ����ü ����
struct Node {
    char data[4];
    struct Node* link;
};

// ���ο� ��带 �����ϴ� �Լ�
struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // �� ��带 ���� �޸� �Ҵ�
    strncpy(newNode->data, data, 3); // ������ ����
    newNode->data[3] = '\0'; // ���ڿ��� ���� �� ���� ���� �߰�
    newNode->link = NULL; // ��ũ �ʱ�ȭ
    return newNode;
}

// ���� ����Ʈ�� ���ο� ��带 �߰��ϴ� �Լ�
void insert(struct Node** head, const char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// ���� ����Ʈ�� ������ ����ϴ� �Լ�
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // ���� ����Ʈ�� ��� ������ �ʱ�ȭ

    // ���� ����Ʈ�� ��ȭ���� ������ �߰�
    insert(&head, "��");
    insert(&head, "ȭ");
    insert(&head, "��");
    insert(&head, "��");

    // ���� ����Ʈ�� ���� ���
    printf("���� ����Ʈ�� ����: ");

    return 0;
}
