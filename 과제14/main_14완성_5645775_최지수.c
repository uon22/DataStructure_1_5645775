#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linearList_14완성_5645775_최지수.h"

#define MAX_INPUT 256

void parsePolynomialInput(char* input, listType* poly) {
    int coef = 0, expo = 0;
    char* token = strtok(input, "+");

    while (token != NULL) {
        if (strchr(token, 'x') || strchr(token, 'X')) {
            if (strchr(token, '^')) {
                sscanf_s(token, "%dx^%d", &coef, &expo);
            }
            else {
                sscanf_s(token, "%dx", &coef);
                expo = 1;
            }
        }
        else {
            coef = atoi(token);
            expo = 0;
        }
        ordered_insertItem(poly, (elementType) { coef, expo });
        token = strtok(NULL, "+");
    }
}

listType* multiplyPoly(listType* a, listType* b) {
    listType* result = createList(a->size * b->size);
    for (int i = 0; i <= a->last; i++) {
        for (int j = 0; j <= b->last; j++) {
            elementType t1 = a->array[i];
            elementType t2 = b->array[j];
            elementType temp = { t1.coef * t2.coef, t1.expo + t2.expo };

            int found = 0;
            for (int k = 0; k <= result->last; k++) {
                if (result->array[k].expo == temp.expo) {
                    result->array[k].coef += temp.coef;
                    found = 1;
                    break;
                }
            }
            if (!found) ordered_insertItem(result, temp);
        }
    }
    return result;
}

int main() {
    char input1[MAX_INPUT], input2[MAX_INPUT];

    printf("첫 번째 다항식을 입력하세요 (예: 4x^3+3x^2+3):\n");
    fgets(input1, MAX_INPUT, stdin);
    input1[strcspn(input1, "\n")] = 0;

    printf("두 번째 다항식을 입력하세요 (예: 3x+7):\n");
    fgets(input2, MAX_INPUT, stdin);
    input2[strcspn(input2, "\n")] = 0;

    listType* poly1 = createList(50);
    listType* poly2 = createList(50);

    parsePolynomialInput(input1, poly1);
    parsePolynomialInput(input2, poly2);

    listType* result = multiplyPoly(poly1, poly2);

    printf("\n[곱셈 결과]\n");
    printList(result);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(result);
    return 0;
}