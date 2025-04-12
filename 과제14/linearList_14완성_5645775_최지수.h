#pragma once

#define NULL_ITEM (elementType) {0, 0}

typedef struct ElementType {
    int coef;  
    int expo;  
} elementType;

typedef struct ListType {
    int size;
    int last;
    int move;
    elementType* array;
} listType;

extern listType* createList(int size);
extern int destroyList(listType* list);
extern int initList(listType* list);

extern elementType readItem(listType* list, int index);
extern elementType deleteItem(listType* list, int index);

extern int insertItem(listType* list, int index, elementType item);
extern int ordered_insertItem(listType* list, elementType item);
extern int printList(listType* list);