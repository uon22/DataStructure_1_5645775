#include <stdio.h>

void main() {
    int i = 31, num;

    printf("������ �Է��ϼ���: ");
    scanf_s("%d", &num);

    printf("�Էµ� ������ 32��Ʈ ǥ��: ");

    for (i; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }

    printf("\n");
}