#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 정의
struct Node {
    char data[4];
    struct Node* link;
};

// 새로운 노드를 생성하는 함수
struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // 새 노드를 위한 메모리 할당
    strncpy(newNode->data, data, 3); // 데이터 복사
    newNode->data[3] = '\0'; // 문자열의 끝에 널 종료 문자 추가
    newNode->link = NULL; // 링크 초기화
    return newNode;
}

// 연결 리스트에 새로운 노드를 추가하는 함수
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

// 연결 리스트의 내용을 출력하는 함수
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // 연결 리스트의 헤드 포인터 초기화

    // 연결 리스트에 월화수목 데이터 추가
    insert(&head, "월");
    insert(&head, "화");
    insert(&head, "수");
    insert(&head, "목");

    // 연결 리스트의 내용 출력
    printf("연결 리스트의 내용: ");

    return 0;
}
