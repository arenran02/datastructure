#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드 구조체 정의
struct Node {
    char data;
    struct Node* next;
};

// 연결 리스트에 새로운 노드 추가하는 함수
void add(struct Node** list, int r, char e) {
    // 새로운 노드 생성
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = e;
    newNode->next = NULL;

    if (r <= 0) {
        printf("invalid position\n");
        free(newNode); // 메모리 누수 방지를 위해 새로운 노드 메모리 해제
        return;
    }

    if (r == 1) { // 새로운 노드를 리스트의 맨 앞에 추가
        newNode->next = *list;
        *list = newNode;
    } else {
        struct Node* temp = *list;
        // 리스트의 r-1 번째 노드까지 이동
        for (int i = 1; i < r - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        // 유효한 위치라면 새로운 노드를 삽입
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("invalid position\n");
            free(newNode); // 메모리 누수 방지를 위해 새로운 노드 메모리 해제
            return;
        }
    }
}

// 연결 리스트에서 노드 삭제하는 함수
void delete_node(struct Node** list, int r) {
    if (*list == NULL || r <= 0) {
        printf("invalid position\n");
        return;
    }
    if (r == 1) { // 첫 번째 노드를 삭제
        struct Node* temp = *list;
        *list = (*list)->next;
        free(temp);
    } else {
        struct Node* temp = *list;
        // 리스트의 r-1 번째 노드까지 이동
        for (int i = 1; i < r - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        // 유효한 위치라면 노드를 삭제
        if (temp != NULL && temp->next != NULL) {
            struct Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        } else {
            printf("invalid position\n");
            return;
        }
    }
}

// 연결 리스트에서 특정 위치의 노드 값을 반환하는 함수
char get(struct Node* list, int r) {
    struct Node* temp = list;
    // 리스트의 r 번째 노드까지 이동
    for (int i = 1; i < r && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        return temp->data;
    } else {
        printf("invalid position\n");
        return '\0'; // 에러를 나타내는 값 반환
    }
}

// 연결 리스트의 모든 노드 값을 출력하는 함수
void print(struct Node* list) {
    while (list != NULL) {
        printf("%c", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* list = NULL; // 연결 리스트 초기화

    for (int i = 0; i < n; i++) {
        char operation;
        int r=0;
        char e='a';

        scanf(" %c", &operation);

        switch(operation) {
            case 'A':
                scanf("%d %c", &r, &e);
                add(&list, r, e);
                break;
            case 'D':
                scanf("%d", &r);
                delete_node(&list, r);
                break;
            case 'G':
                scanf("%d", &r);
                char value = get(list, r);
                if (value != '\0') {
                    printf("%c\n", value);
                }
                break;
            case 'P':
                print(list);
                break;
            default:
                printf("invalid operation\n");
                break;
        }
    }

    return 0;
}
