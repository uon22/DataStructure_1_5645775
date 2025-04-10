#pragma once

#define NULL_ITEM (elementType){-1, -1, -1}
#define MAX_SIZE 20

typedef struct {
    int row;
    int col;
    int val;
} elementType;

typedef struct {
    elementType array[MAX_SIZE];
    int size;
    int last;
    int move;
} listType;

listType* createList();
void initList(listType* list);
int ordered_insertItem(listType* list, elementType item);
elementType readItem(listType* list, int index);
void printList(listType* list);
listType* addSparseMatrix(listType* A, listType* B);
listType* inputMatrix();
