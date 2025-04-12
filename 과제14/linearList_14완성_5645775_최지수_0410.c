#include <stdio.h>
#include <stdlib.h>
#include "linearList_14완성_5645775_최지수.h"

listType* createList(int size) {
    listType* lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
}

int destroyList(listType* list) {
    free(list->array);
    free(list);
    return 1;
}

int initList(listType* list) {
    list->last = -1;
    list->move = 0;
    return 1;
}

elementType readItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in readItem\n", index);
        return NULL_ITEM;
    }
    return list->array[index];
}

elementType deleteItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in deleteItem\n", index);
        return NULL_ITEM;
    }
    elementType removed = list->array[index];
    for (int i = index; i < list->last; i++) {
        list->array[i] = list->array[i + 1];
        list->move++;
    }
    list->last--;
    return removed;
}

int insertItem(listType* list, int index, elementType item) {
    if (index < 0 || index > list->last + 1) return -1;
    for (int i = list->last + 1; i > index; i--) {
        list->array[i] = list->array[i - 1];
        list->move++;
    }
    list->array[index] = item;
    list->last++;
    return 1;
}

int ordered_insertItem(listType* list, elementType item) {
    int i, j;
    for (i = 0; i <= list->last; i++) {
        if (list->array[i].expo < item.expo) break;
    }
    for (j = list->last + 1; j > i; j--) {
        list->array[j] = list->array[j - 1];
        list->move++;
    }
    list->array[i] = item;
    list->last++;
    return 1;
}

int printList(listType* list) {
    printf("List: size = %d, last = %d, move = %d\n", list->size, list->last, list->move);
    printf("    Items: P(x) = ");
    for (int i = 0; i <= list->last; i++) {
        elementType t = list->array[i];
        if (t.coef == 0) continue;

        if (i > 0 && t.coef > 0) printf("+");
        if (t.expo == 0) printf("%d", t.coef);
        else if (t.expo == 1) printf("%dx", t.coef);
        else printf("%dx^%d", t.coef, t.expo);
    }
    printf("\n");
    return 1;
}
