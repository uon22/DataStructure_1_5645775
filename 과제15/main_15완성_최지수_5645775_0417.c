#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linearlist_15�ϼ�_������_5645775_0417.h"

int main() {
    PhoneBook pb = { .size = 0 };
    int menu;

    while (1) {
        printf("\n===== ��ȭ��ȣ�� �޴� =====\n");
        printf("1. ����ó �߰�\n");
        printf("2. ����ó ����\n");
        printf("3. ����ó �˻�\n");
        printf("4. ��ü ����ó ���\n");
        printf("0. ����\n");
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            menuAddContact(&pb);
            break;
        case 2:
            menuDeleteContact(&pb);
            break;
        case 3:
            menuSearchContact(&pb);
            break;
        case 4:
            menuDisplayContacts(&pb);
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �޴��Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }
}
