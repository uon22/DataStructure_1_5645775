#pragma once

typedef int elementType;

typedef struct ListNode {
    elementType data;
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* tail;   
} linkedList_h;

linkedList_h* createLinkedList(void);
void destroyLinkedList(linkedList_h* CL);
void printList(linkedList_h* CL);
void insertFirstNode(linkedList_h* CL, elementType item);
void insertLastNode(linkedList_h* CL, elementType item);
void insertMiddle(linkedList_h* CL, elementType target, elementType item);
void insertNthNode(linkedList_h* CL, int position, elementType item);
void deleteNode(linkedList_h* CL, elementType target);