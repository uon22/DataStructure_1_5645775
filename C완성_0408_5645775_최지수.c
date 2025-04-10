#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

listType* createList() {
    listType* list = (listType*)malloc(sizeof(listType));
    list->size = MAX_SIZE;
    list->last = -1;
    list->move = 0;
    return list;
}

void initList(listType* list) {
    list->last = -1;
    list->move = 0;
}

int compare_item(elementType a, elementType b) {
    if (a.row != b.row) return a.row - b.row;
    return a.col - b.col;
}

int ordered_insertItem(listType* list, elementType item) {
    int i = 0;
    while (i <= list->last && compare_item(list->array[i], item) < 0) i++;

    for (int j = list->last + 1; j > i; j--) {
        list->array[j] = list->array[j - 1];
        list->move++;
    }

    list->array[i] = item;
    list->last++;
    return 1;
}

elementType readItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in readItem\n", index);
        return NULL_ITEM;
    }
    return list->array[index];
}

void printList(listType* list) {
    printf("List: size = %d, last = %d\n", list->size, list->last);
    printf("Items:\n");
    for (int i = 0; i <= list->last; i++) {
        printf("[%d] %d, %d, %d\n", i, list->array[i].row, list->array[i].col, list->array[i].val);
    }
}

listType* inputMatrix() {
    listType* list = createList();
    int r, c, v;
    while (1) {
        scanf_s("%d", &r);
        if (r == -1) break;
        scanf_s("%d %d", &c, &v);
        ordered_insertItem(list, (elementType) { r, c, v });
    }
    return list;
}

listType* addSparseMatrix(listType* A, listType* B) {
    listType* R = createList();
    int i = 0, j = 0;

    while (i <= A->last && j <= B->last) {
        elementType a = A->array[i];
        elementType b = B->array[j];

        if (compare_item(a, b) < 0) {
            ordered_insertItem(R, a);
            i++;
        }
        else if (compare_item(a, b) > 0) {
            ordered_insertItem(R, b);
            j++;
        }
        else {
            int sum = a.val + b.val;
            if (sum != 0)
                ordered_insertItem(R, (elementType) { a.row, a.col, sum });
            i++; j++;
        }
    }

    while (i <= A->last) ordered_insertItem(R, A->array[i++]);
    while (j <= B->last) ordered_insertItem(R, B->array[j++]);

    return R;
}
