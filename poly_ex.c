#include <stdio.h>
#include <stdlib.h>

// 다항식의 항을 표현하는 구조체
typedef struct Term {
    int coefficient;  // 계수
    int exponent;     // 지수
    struct Term *next; // 다음 항을 가리키는 포인터
} Term;

// 다항식을 나타내는 구조체
typedef struct Polynomial {
    Term *head; // 다항식의 첫 항을 가리키는 포인터
} Polynomial;

// 다항식 생성 함수
Polynomial *createPolynomial() {
    Polynomial *poly = (Polynomial *)malloc(sizeof(Polynomial));
    poly->head = NULL;
    return poly;
}

// 다항식 항 추가 함수
void addTerm(Polynomial *poly, int coefficient, int exponent) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    // 다항식이 비어있는 경우
    if (poly->head == NULL) {
        poly->head = newTerm;
        return;
    }

    // 다항식이 비어있지 않은 경우
    Term *current = poly->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
}

// 다항식 출력 함수
void printPolynomial(Polynomial *poly) {
    if (poly->head == NULL) {
        printf("다항식이 비어 있습니다.\n");
        return;
    }

    Term *current = poly->head;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

// 두 다항식의 덧셈 함수
Polynomial *addPolynomials(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *result = createPolynomial();

    Term *current1 = poly1->head;
    Term *current2 = poly2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            addTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            addTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            addTerm(result, current1->coefficient + current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    // poly1이나 poly2가 남아 있는 경우
    while (current1 != NULL) {
        addTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        addTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

// 두 다항식의 뺄셈 함수
Polynomial *subtractPolynomials(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *result = createPolynomial();

    Term *current1 = poly1->head;
    Term *current2 = poly2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            addTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            addTerm(result, -(current2->coefficient), current2->exponent);
            current2 = current2->next;
        } else {
            addTerm(result, current1->coefficient - current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    // poly1이나 poly2가 남아 있는 경우
    while (current1 != NULL) {
        addTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        addTerm(result, -(current2->coefficient), current2->exponent);
        current2 = current2->next;
    }

    return result;
}

// 두 다항식의 곱셈 함수
Polynomial *multiplyPolynomials(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *result = createPolynomial();

    Term *current1 = poly1->head;
    while (current1 != NULL) {
        Term *current2 = poly2->head;
        while (current2 != NULL) {
            addTerm(result, current1->coefficient * current2->coefficient, current1->exponent + current2->exponent);
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}

// 다항식의 미분 함수
Polynomial *differentiatePolynomial(Polynomial *poly) {
    Polynomial *result = createPolynomial();

    Term *current = poly->head;
    while (current != NULL) {
        if (current->exponent > 0) {
            addTerm(result, current->coefficient * current->exponent, current->exponent - 1);
        }
        current = current->next;
    }

    return result;
}

// 다항식의 적분 함수
Polynomial *integratePolynomial(Polynomial *poly) {
    Polynomial *result = createPolynomial();

    Term *current = poly->head;
    while (current != NULL) {
        addTerm(result, current->coefficient / (current->exponent + 1), current->exponent + 1);
        current = current->next;
    }

    return result;
}

// 메모리 해제 함수
void freePolynomial(Polynomial *poly) {
    Term *current = poly->head;
    while (current != NULL) {
        Term *temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

int main() {
    // 첫 번째 다항식 생성 및 추가
    Polynomial *poly1 = createPolynomial();
    addTerm(poly1, 5, 2);
    addTerm(poly1, 3, 1);
    addTerm(poly1, 1, 0);
    printf("첫 번째 다항식: ");
    printPolynomial(poly1);

    // 두 번째 다항식 생성 및 추가
    Polynomial *poly2 = createPolynomial();
    addTerm(poly2, 4, 3);
    addTerm(poly2, 2, 2);
    addTerm(poly2, 1, 0);
    printf("두 번째 다항식: ");
    printPolynomial(poly2);

    // 다항식 덧셈
    Polynomial *sum = addPolynomials(poly1, poly2);
    printf("두 다항식의 합: ");
    printPolynomial(sum);

    // 다항식 뺄셈
    Polynomial *difference = subtractPolynomials(poly1, poly2);
    printf("두 다항식의 차: ");
    printPolynomial(difference);

    // 다항식 곱셈
    Polynomial *product = multiplyPolynomials(poly1, poly2);
    printf("두 다항식의 곱: ");
    printPolynomial(product);

    // 다항식 미분
    Polynomial *derivative = differentiatePolynomial(poly1);
    printf("첫 번째 다항식의 미분: ");
    printPolynomial(derivative);

    // 다항식 적분
    Polynomial *integral = integratePolynomial(poly1);
    printf("첫 번째 다항식의 적분: ");
    printPolynomial(integral);

    // 메모리 해제
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    freePolynomial(difference);
    freePolynomial(product);
    freePolynomial(derivative);
    freePolynomial(integral);

    return 0;
}
