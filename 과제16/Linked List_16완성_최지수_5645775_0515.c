#include <stdio.h>
#include <stdlib.h>
#include "Linked List_16완성_최지수_5645775_0515.h"

linkedList_h* createLinkedList(void) {
    linkedList_h* CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL->tail = NULL;
    return CL;
}

void destroyLinkedList(linkedList_h* CL) {
    if (CL->tail == NULL) return;
    listNode* current = CL->tail->link;
    listNode* next;
    while (current != CL->tail) {
        next = current->link;
        free(current);
        current = next;
    }
    free(CL->tail);
    free(CL);
}

void printList(linkedList_h* CL) {
    if (CL->tail == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    listNode* p = CL->tail->link;
    printf("원형 Linked List: ");
    do {
        printf("[%d] ", p->data);
        p = p->link;
    } while (p != CL->tail->link);
    printf("\n");
}

void insertFirstNode(linkedList_h* CL, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    if (CL->tail == NULL) {
        CL->tail = newNode;
        newNode->link = newNode;
    }
    else {
        newNode->link = CL->tail->link;
        CL->tail->link = newNode;
    }
}

void insertLastNode(linkedList_h* CL, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    if (CL->tail == NULL) {
        CL->tail = newNode;
        newNode->link = newNode;
    }
    else {
        newNode->link = CL->tail->link;
        CL->tail->link = newNode;
        CL->tail = newNode;
    }
}

void insertMiddle(linkedList_h* CL, elementType target, elementType item) {
    if (CL->tail == NULL) return;
    listNode* current = CL->tail->link;
    do {
        if (current->data == target) {
            listNode* newNode = (listNode*)malloc(sizeof(listNode));
            newNode->data = item;
            newNode->link = current->link;
            current->link = newNode;
            if (current == CL->tail) CL->tail = newNode;
            return;
        }
        current = current->link;
    } while (current != CL->tail->link);
}

void insertNthNode(linkedList_h* CL, int position, elementType item) {
    if (position < 1) return;
    if (position == 1) {
        insertFirstNode(CL, item);
        return;
    }
    listNode* current = CL->tail->link;
    int count = 1;
    while (count < position - 1 && current != CL->tail) {
        current = current->link;
        count++;
    }
    if (count == position - 1) {
        listNode* newNode = (listNode*)malloc(sizeof(listNode));
        newNode->data = item;
        newNode->link = current->link;
        current->link = newNode;
        if (current == CL->tail) CL->tail = newNode;
    }
}

void deleteNode(linkedList_h* CL, elementType target) {
    if (CL->tail == NULL) return;
    listNode* current = CL->tail->link;
    listNode* prev = CL->tail;
    do {
        if (current->data == target) {
            if (current == CL->tail && current->link == current) {
                CL->tail = NULL;
            }
            else {
                prev->link = current->link;
                if (current == CL->tail) CL->tail = prev;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->link;
    } while (current != CL->tail->link);
}
