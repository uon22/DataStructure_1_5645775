#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linearlist_15완성_최지수_5645775_0417.h"

int main() {
    PhoneBook pb = { .size = 0 };
    int menu;

    while (1) {
        printf("\n===== 전화번호부 메뉴 =====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 전체 연락처 출력\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
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
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴입니다. 다시 선택하세요.\n");
        }
    }
}
