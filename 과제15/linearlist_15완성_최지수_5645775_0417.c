#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "linearlist_15�ϼ�_������_5645775_0417.h"

void addContact(PhoneBook* pb, char name[], char phone[]) {
    if (pb->size >= MAX) {
        printf("��ȭ��ȣ�ΰ� ���� á���ϴ�.\n");
        return;
    }
    strcpy(pb->contacts[pb->size].name, name);
    strcpy(pb->contacts[pb->size].phone, phone);
    pb->size++;
    printf("����ó�� �߰��Ǿ����ϴ�.\n");
}

void deleteContact(PhoneBook* pb, char name[]) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("�����Ǿ����ϴ�.\n");
            return;
        }
    }
    printf("�ش� �̸��� ����ó�� ã�� �� �����ϴ�.\n");
}

void searchContact(PhoneBook* pb, char name[]) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("�̸�: %s, ��ȭ��ȣ: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("�ش� �̸��� ����ó�� ã�� �� �����ϴ�.\n");
}

void displayContacts(PhoneBook* pb) {
    if (pb->size == 0) {
        printf("��ü ����ó�� ����ֽ��ϴ�.\n");
        return;
    }
    printf("\n==== ��ü ����ó ====\n");
    for (int i = 0; i < pb->size; i++) {
        printf("[%d] �̸�: %s, ��ȭ��ȣ: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void menuAddContact(PhoneBook* pb) {
    char name[30], phone[15];
    printf("�̸��� �Է��ϼ���: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("��ȭ��ȣ�� �Է��ϼ���: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';
    addContact(pb, name, phone);
}

void menuDeleteContact(PhoneBook* pb) {
    char name[30];
    printf("������ �̸��� �Է��ϼ���: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    deleteContact(pb, name);
}

void menuSearchContact(PhoneBook* pb) {
    char name[30];
    printf("�˻��� �̸��� �Է��ϼ���: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    searchContact(pb, name);
}

void menuDisplayContacts(PhoneBook* pb) {
    displayContacts(pb);
}
