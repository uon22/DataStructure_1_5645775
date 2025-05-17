#include <stdio.h>
#include "Linked List_16완성_최지수_5645775_0515.h"

int main() {
    linkedList_h* CL = createLinkedList();
    int menu, val, pos, target;

    while (1) {
        printf("=======  Linked_List Menu  =======\n");
        printf("1) insertFirst   (리스트의 제일 앞에 삽입)\n");
        printf("2) insertLast    (리스트의 제일 뒤에 삽입)\n");
        printf("3) insertMiddle  (특정 값 뒤에 삽입)\n"); //띄어쓰기 또는 엔터
        printf("4) insertNthNode (N번째 위치 삽입)\n"); //띄어쓰기 또는 엔터
        printf("6) deleteNode    (특정 값 삭제)\n"); //중복시 앞에 있는 값부터 삭제
        printf("7) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu ▶ ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            printf("Insert First Value: ");
            scanf_s("%d", &val);
            insertFirstNode(CL, val);
            break;
        case 2:
            printf("Insert Last Value: ");
            scanf_s("%d", &val);
            insertLastNode(CL, val);
            break;
        case 3:
            printf("Target value 뒤에 삽입할 값 입력: ");
            scanf_s("%d %d", &target, &val);
            insertMiddle(CL, target, val);
            break;
        case 4:
            printf("삽입할 위치와 값 입력: ");
            scanf_s("%d %d", &pos, &val);
            insertNthNode(CL, pos, val);
            break;
        case 6:
            printf("삭제할 값 입력: ");
            scanf_s("%d", &val);
            deleteNode(CL, val);
            break;
        case 7:
            printList(CL);
            break;
        case 0:
            destroyLinkedList(CL);
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다.\n");
        }
    }
}
