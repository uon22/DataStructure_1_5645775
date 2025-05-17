#include <stdio.h>
#include "Linked List_16�ϼ�_������_5645775_0515.h"

int main() {
    linkedList_h* CL = createLinkedList();
    int menu, val, pos, target;

    while (1) {
        printf("=======  Linked_List Menu  =======\n");
        printf("1) insertFirst   (����Ʈ�� ���� �տ� ����)\n");
        printf("2) insertLast    (����Ʈ�� ���� �ڿ� ����)\n");
        printf("3) insertMiddle  (Ư�� �� �ڿ� ����)\n"); //���� �Ǵ� ����
        printf("4) insertNthNode (N��° ��ġ ����)\n"); //���� �Ǵ� ����
        printf("6) deleteNode    (Ư�� �� ����)\n"); //�ߺ��� �տ� �ִ� ������ ����
        printf("7) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu �� ");
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
            printf("Target value �ڿ� ������ �� �Է�: ");
            scanf_s("%d %d", &target, &val);
            insertMiddle(CL, target, val);
            break;
        case 4:
            printf("������ ��ġ�� �� �Է�: ");
            scanf_s("%d %d", &pos, &val);
            insertNthNode(CL, pos, val);
            break;
        case 6:
            printf("������ �� �Է�: ");
            scanf_s("%d", &val);
            deleteNode(CL, val);
            break;
        case 7:
            printList(CL);
            break;
        case 0:
            destroyLinkedList(CL);
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�.\n");
        }
    }
}
