#include <stdio.h>


//���� �Լ�: �� ������ ���� �� ��ȯ
int add(int num1, int num2);

//���� �Լ�: �� ������ ���� ��ȯ
int subtract(int num1, int num2);

//���� �Լ�: �� ������ ���� ��ȯ
int multiply(int num1, int num2);

//������ �Լ�: �� ������ ���� �� ��ȯ, ������ ���� 0�� ��� ���� �޽��� ���
float divide(int num1, int num2);

int main() {
    int num1, num2;

    printf("ù ��° ���� ������ �Է��ϼ���: "); //���� ���
    scanf_s("%d", &num1); //ù ��° ���� ���� �Է¹ޱ�, ���� �Է��� �ޱ� ���� ���� ������ %d

   
    printf("�� ��° ���� ������ �Է��ϼ���: "); //���� ���
    scanf_s("%d", &num2); //�� ��° ���� ���� �Է¹ޱ�

    //��Ģ���� ��� ���
    printf("����: %d\n", add(num1, num2)); //���� ��� ���
    printf("����: %d\n", subtract(num1, num2)); //���� ��� ���
    printf("����: %d\n", multiply(num1, num2)); //���� ��� ���
    printf("������: %.2f\n", divide(num1, num2)); //������ ��� ��� (�Ҽ��� �� �ڸ������� ���)

    return 0; //���α׷� ����
}

//���� �Լ� ����: �� ������ ���� �� ��ȯ
int add(int num1, int num2) {
    return num1 + num2;  // �� ���� ���� ��ȯ
}

//���� �Լ� ����: �� ������ ���� ��ȯ
int subtract(int num1, int num2) {
    return num1 - num2; //�� ���� ���� ��ȯ
}

//���� �Լ� ����: �� ������ �� ��ȯ
int multiply(int num1, int num2) {
    return num1 * num2; //�� ���� ���� ��ȯ
}

//������ �Լ� ����: �� ������ ���� ���� ��ȯ (������ ���� 0�̸� ���� ó��)
float divide(int num1, int num2) {
    if (num2 == 0) { //������ ���� 0�� ���
        printf("0���� ���� �� �����ϴ�.\n"); //���� �޽��� ���
        return 0.0; //������ ���� 0 ��ȯ
    }
    return (float)num1 / num2; //������ ��� �� �Ҽ����� �����Ͽ� ��� ��ȯ
}
