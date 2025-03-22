#include <stdio.h>

//��Ģ���� �Լ� ����
double add(double a, double b); //���� �Լ�
double subtract(double a, double b); //���� �Լ�
double multiply(double a, double b); //���� �Լ�
double divide(double a, double b); //������ �Լ�

int main() {
    char ch;
    double num, term, sum = 0; //term���� ����/������ �߰��� ����
    char prev_op = '+'; //���� ������ ����

    //���� �Է¹���
    printf("����� ������ �Է��ϼ��� (��: 3+5*2-8/4=): ");
    scanf_s("%lf", &term);

    sum = 0; //�ʱ�ȭ

    while (1) {
        scanf_s(" %c", &ch, 1); //������ �Է�

        if (ch == '=') {
            sum = (prev_op == '+') ? add(sum, term) : subtract(sum, term); //������ ��� ����
            printf("���: %.6f\n", sum); //��� ���
            break;
        }

        scanf_s("%lf", &num); //���� ���� �Է�

        if (ch == '*' || ch == '/') {
            // ����, �������� term�� ����
            if (ch == '*') term = multiply(term, num);
            else term = divide(term, num);
        }
        else {
            // ����, �����̸� ���� ����/������ ����� sum�� �ݿ� �� term �ʱ�ȭ
            sum = (prev_op == '+') ? add(sum, term) : subtract(sum, term);
            term = num;
            prev_op = ch;
        }
    }

    return 0;
}

//��Ģ���� �Լ� ����
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return (b != 0) ? (a / b) : 0; //0���� ������ ��� ����
}
