#include <stdio.h>
#include <string.h>

int main() {
    char str[1000]; //�ִ� 999�� + ���ڿ� ���� ����

    printf("���ڿ��� �Է��ϼ���: ");
    fgets(str, sizeof(str), stdin); //�Է� ����(���� ����)

    if (str[strlen(str) - 1] == '\n') //���� ���� ����
        str[strlen(str) - 1] = '\0';

    printf("���ڿ��� ����: %ld\n", strlen(str)); //���� ���� ���ڿ� ���� ���

    printf("��ȯ�� ���ڿ�: ");
    for (int i = 0; str[i]; i++) //���ڿ��� ���� ������ �ݺ�
        printf("%c",
            (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : //�빮�ڸ� �ҹ��ڷ� ��ȯ
            (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : //�ҹ��ڸ� �빮�ڷ� ��ȯ
            str[i]); //�������� �״�� ���
    printf("\n");

    return 0;
}