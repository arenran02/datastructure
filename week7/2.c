#include <stdio.h>
#include <stdlib.h>

// 집합의 각 원소를 표현하는 노드 구조체
struct Node {
    int num;
    struct Node* next; // 다음 노드를 가리키는 포인터
};

// 집합 출력 함수
void printSet(struct Node* node) {
    if (node == NULL) {
        printf("0\n");
    }

    while (node != NULL) {
        printf("%d ", node->num);
        node = node->next;
    }

    printf("\n");
}

// 집합에 원소 추가 함수 (직접 구현)
void addElement(struct Node** set, int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->num = n;
    newNode->next = NULL;

    // 집합이 비어있을 경우
    if (*set == NULL) {
        *set = newNode;
    } else {
        struct Node* temp = *set;
        struct Node* prev = NULL; // 이전 노드를 추적하기 위한 포인터

        // 새로운 원소가 적절한 위치에 삽입될 때까지 노드를 순회
        while (temp != NULL && temp->num < n) {
            prev = temp;
            temp = temp->next;
        }

        // 새로운 원소를 적절한 위치에 삽입
        if (prev == NULL) {
            // 새로운 원소가 첫 번째 원소보다 작은 경우
            newNode->next = *set;
            *set = newNode;
        } else {
            // 새로운 원소가 중간에 삽입되는 경우
            prev->next = newNode;
            newNode->next = temp;
        }
    }
}

// 집합의 메모리 해제 함수
void freeSet(struct Node* set) {
    while (set != NULL) {
        struct Node* temp = set;
        set = set->next;
        free(temp);
    }
}

// 집합에 해당 요소가 있는지 확인하는 함수
int isElementInSet(struct Node* set, int n) {
    while (set != NULL) {
        if (set->num == n)
            return 1; // 요소가 이미 집합에 존재함
        set = set->next;
    }
    return 0; // 요소가 집합에 없음
}

// 두 집합의 합집합 구하는 함수 (직접 구현)
struct Node* UnionSet(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    // 두 집합이 모두 비어있는 경우
    if (a == NULL && b == NULL)
        return NULL;

    // 집합 a를 순회하면서 각 원소를 결과 집합에 추가
    while (a != NULL) {
        // 이미 있는 요소는 추가하지 않음
        if (!isElementInSet(result, a->num))
            addElement(&result, a->num);
        a = a->next;
    }

    // 집합 b를 순회하면서 결과 집합에 추가
    while (b != NULL) {
        // 이미 있는 요소는 추가하지 않음
        if (!isElementInSet(result, b->num))
            addElement(&result, b->num);
        b = b->next;
    }

    return result;
}


// 두 집합의 교집합 구하는 함수
struct Node* IntersectSet(struct Node* a, struct Node* b) {
    struct Node* tempA = a;
    struct Node* result = NULL;

    // 두 집합이 모두 비어있는 경우
    if (a == NULL && b == NULL)
        return NULL;

    // 집합 b를 순회하면서 각 원소를 결과 집합에 추가
    while (b != NULL) {
        // 이미 있는 요소는 추가하지 않음
        if (isElementInSet(tempA, b->num))
            addElement(&result, b->num);
        b = b->next;
    }

    return result;
}

int main() {
    struct Node* set1 = NULL;
    struct Node* set2 = NULL;

    // 첫 번째 집합의 크기를 입력 받음
    int num1;
    scanf("%d", &num1);

    if (num1 != 0) {
        // 첫 번째 집합의 원소를 입력 받음
        for (int i = 0; i < num1; i++) {
            int temp;
            scanf("%d", &temp);
            addElement(&set1, temp);
        }
    }

    // 두 번째 집합의 크기를 입력 받음
    int num2;
    scanf("%d", &num2);

    if (num2 != 0) {
        // 두 번째 집합의 원소를 입력 받음
        for (int i = 0; i < num2; i++) {
            int temp;
            scanf("%d", &temp);
            addElement(&set2, temp);
        }
    }

    // 합집합 출력
    printSet(UnionSet(set1, set2));
    
    //교집합 출력
    printSet(IntersectSet(set1, set2));

    // 집합 메모리 해제
    freeSet(set1);
    freeSet(set2);

    return 0;
}
