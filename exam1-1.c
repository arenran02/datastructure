#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 다항식의 항을 표현하는 구조체
typedef struct Term {
    int coefficient;  // 계수
    int exponent;     // 지수
    struct Term* next; // 다음 항을 가리키는 포인터
} Term;

// 다항식을 나타내는 구조체
typedef struct Polynomial {
    Term* head; // 다항식의 첫 항을 가리키는 포인터
} Polynomial;

// 다항식 생성 함수
Polynomial* createPolynomial() {
    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->head = NULL;
    return poly;
}

// 다항식 항 추가 함수
void addTerm(Polynomial* poly, int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    // 다항식이 비어있는 경우
    if (poly->head == NULL) {
        poly->head = newTerm;
        return;
    }

    // 다항식이 비어있지 않은 경우
    Term* current = poly->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
}

// 두 다항식의 곱셈 함수
Polynomial* multiplyPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();

    Term* current1 = poly1->head;
    while (current1 != NULL) {
        Term* current2 = poly2->head;
        while (current2 != NULL) {
            addTerm(result, current1->coefficient * current2->coefficient, current1->exponent + current2->exponent);
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    //result에서 exponent가 같은 값은 합쳐서 보여준다
    Term* current = result->head;
    while (current != NULL) {
        Term* temp = current->next;
        while (temp != NULL) {
            if (current->exponent == temp->exponent) {
                current->coefficient += temp->coefficient;
                current->next = temp->next;
                free(temp);
                temp = current->next;
            }
            else {
                temp = temp->next;
            }
        }
        current = current->next;
    }


    return result;
}

// 메모리 해제 함수
void freePolynomial(Polynomial* poly) {
    Term* current = poly->head;
    while (current != NULL) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

// 다항식 출력 함수
void printPolynomial(Polynomial* poly) {
    if (poly->head == NULL) {
        //printf("다항식이 비어 있습니다.\n");
        return;
    }

    Term* current = poly->head;
    while (current != NULL) {
        printf("%d %d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {

    // 첫 번째 다항식 생성 및 추가
    Polynomial* poly1 = createPolynomial();
    Polynomial* poly2 = createPolynomial();

    int num_terms1 = 0;
    int num_terms2 = 0;
    int temp1 = 0;
    int temp2 = 0;

    scanf("%d ", &num_terms1);

    for (int i = 0; i < num_terms1; i++) {
        scanf("%d %d", &temp1, &temp2);
        addTerm(poly1, temp1, temp2);
    }

    scanf("%d ", &num_terms2);

    for (int i = 0; i < num_terms1; i++) {
        scanf("%d %d", &temp1, &temp2);
        addTerm(poly2, temp1, temp2);
    }

    Polynomial* product = multiplyPolynomials(poly1, poly2);
    printPolynomial(product);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(product);

    return 0;
}
