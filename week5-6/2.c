#include <stdio.h>
#include <stdlib.h>

// 다항식의 각 항을 표현하는 노드 구조체
struct Node {
    int coef; // 계수
    int exp;  // 차수
    struct Node* next; // 다음 노드를 가리키는 포인터
};

// 새로운 항을 추가하는 함수
// 새로운 항을 추가하는 함수
void addTerm(struct Node** poly, int coef, int exp) {
    // 새로운 항을 위한 노드 생성
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    // 다항식이 비어있을 경우
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        // 마지막 노드까지 이동
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // 새로운 노드를 마지막 노드의 다음에 추가
        temp->next = newNode;
    }
}


// 두 다항식을 더하는 함수
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    // 두 다항식의 항을 차수에 대해 순차적으로 탐색하며 더하기
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp > temp2->exp) {
            addTerm(&result, temp1->coef, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            addTerm(&result, temp2->coef, temp2->exp);
            temp2 = temp2->next;
        } else {
            int sum_coef = temp1->coef + temp2->coef;
            if (sum_coef != 0) {
                addTerm(&result, sum_coef, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // 남은 항들을 결과 다항식에 추가
    while (temp1 != NULL) {
        addTerm(&result, temp1->coef, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        addTerm(&result, temp2->coef, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// 다항식을 출력하는 함수
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%d %d", poly->coef, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

// 메모리 해제 함수
void freeList(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    int num_terms1, num_terms2;
    scanf("%d", &num_terms1); // 첫 번째 다항식의 항의 개수 입력
    struct Node* poly1 = NULL; // 첫 번째 다항식의 연결 리스트 초기화
    int coef, exp;
    // 첫 번째 다항식의 항들 입력 받기
    for (int i = 0; i < num_terms1; i++) {
        scanf("%d %d", &coef, &exp);
        if (coef != 0) {
            addTerm(&poly1, coef, exp);
        }
    }

    scanf("%d", &num_terms2); // 두 번째 다항식의 항의 개수 입력
    struct Node* poly2 = NULL; // 두 번째 다항식의 연결 리스트 초기화
    // 두 번째 다항식의 항들 입력 받기
    for (int i = 0; i < num_terms2; i++) {
        scanf("%d %d", &coef, &exp);
        if (coef != 0) {
            addTerm(&poly2, coef, exp);
        }
    }

    // 두 다항식을 더한 결과 계산
    struct Node* result = addPolynomials(poly1, poly2);

    // 결과 다항식 출력
    printPolynomial(result);

    // 메모리 해제
    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}
