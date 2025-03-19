#include <stdio.h>

union FloatToBits { //float ���� unsigned int�� ��ȯ�ϱ� ���� ����ü
    float f;
    unsigned int bits; //�޸𸮸� �����ϴ� ������
};

int main() {
    union FloatToBits num; //���Ͽ� ����

    printf("�Ǽ��� �Է��ϼ���: ");
    scanf_s("%f", &num.f); //�Է¹��� ���� f�� ����

    unsigned int bits = num.bits; //IEEE 754 32��Ʈ ������ ������ ����

    printf("��ȣ (1��Ʈ): %d\n", bits >> 31); //31��Ʈ ���������� �̵� �� �ֻ��� ��Ʈ�� ����

    printf("���� (8��Ʈ): ");
    for (int i = 7; i >= 0; i--) //8��Ʈ �ݺ�
        printf("%d ", (bits >> (23 + i)) & 1); //23+i��ŭ ���������� �̵�, ���� �κ� �������� �̵�, &1�� �ش� ��Ʈ�� ���

    printf("\n");

    printf("���� (23��Ʈ): ");
    for (int i = 22; i >= 0; i--) //23��Ʈ �ݺ�
        printf("%d ", (bits >> i) & 1); //i��ŭ ���������� �̵�, ���� �κ� ������ �̵�, &1�� �ش� ��Ʈ�� ���

    printf("\n");

    return 0;
}