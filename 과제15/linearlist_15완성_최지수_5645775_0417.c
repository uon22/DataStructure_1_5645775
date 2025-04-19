#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "linearlist_15완성_최지수_5645775_0417.h"

void addContact(PhoneBook* pb, char name[], char phone[]) {
    if (pb->size >= MAX) {
        printf("전화번호부가 가득 찼습니다.\n");
        return;
    }
    strcpy(pb->contacts[pb->size].name, name);
    strcpy(pb->contacts[pb->size].phone, phone);
    pb->size++;
    printf("연락처가 추가되었습니다.\n");
}

void deleteContact(PhoneBook* pb, char name[]) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("삭제되었습니다.\n");
            return;
        }
    }
    printf("해당 이름의 연락처를 찾을 수 없습니다.\n");
}

void searchContact(PhoneBook* pb, char name[]) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("해당 이름의 연락처를 찾을 수 없습니다.\n");
}

void displayContacts(PhoneBook* pb) {
    if (pb->size == 0) {
        printf("전체 연락처가 비어있습니다.\n");
        return;
    }
    printf("\n==== 전체 연락처 ====\n");
    for (int i = 0; i < pb->size; i++) {
        printf("[%d] 이름: %s, 전화번호: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void menuAddContact(PhoneBook* pb) {
    char name[30], phone[15];
    printf("이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("전화번호를 입력하세요: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';
    addContact(pb, name, phone);
}

void menuDeleteContact(PhoneBook* pb) {
    char name[30];
    printf("삭제할 이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    deleteContact(pb, name);
}

void menuSearchContact(PhoneBook* pb) {
    char name[30];
    printf("검색할 이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    searchContact(pb, name);
}

void menuDisplayContacts(PhoneBook* pb) {
    displayContacts(pb);
}
