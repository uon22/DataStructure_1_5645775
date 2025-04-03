/*
FUNCTION fibonacci_recursive(n)
    IF n == 0 RETURN 0
    IF n == 1 RETURN 1
    RETURN fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

FUNCTION fibonacci_iterative(n)
    IF n == 0 RETURN 0
    IF n == 1 RETURN 1
    DECLARE a = 0, b = 1, temp
    FOR i FROM 2 TO n DO
        temp = a + b
        a = b
        b = temp
    RETURN b

FUNCTION main()
    DECLARE method, n
    WHILE TRUE DO
        PRINT "�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����): "
        INPUT method
        SWITCH (method)
            CASE 0:
                PRINT "���α׷��� ����Ǿ����ϴ�."
                RETURN 0
            CASE 1, 2:
                PRINT "���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): "
                INPUT n
                IF n == 0 THEN
                    PRINT "���α׷��� ����Ǿ����ϴ�."
                    RETURN 0
                SWITCH (method)
                    CASE 1:
                        PRINT "F(n) =", fibonacci_recursive(n), "(����� ���)"
                    CASE 2:
                        PRINT "F(n) =", fibonacci_iterative(n), "(��ȯ�� ���)"
                END SWITCH
            DEFAULT:
                PRINT "�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �����ϼ���."
    END WHILE
END FUNCTION
*/

#include <stdio.h>

//����� ���
int fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

//��ȯ�� ��� (�ݺ���)
int fibonacci_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int method, n;

    while (1) {
        printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����): ");
        scanf_s("%d", &method);

        switch (method) {
        case 0:
            printf("���α׷��� ����Ǿ����ϴ�.\n");
            return 0;

        case 1:
        case 2:
            printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
            scanf_s("%d", &n);

            if (n == 0) {
                printf("���α׷��� ����Ǿ����ϴ�.\n");
                return 0;
            }

            switch (method) {
            case 1:
                printf("F(%d) = %d (����� ���)\n", n, fibonacci_recursive(n));
                break;
            case 2:
                printf("F(%d) = %d (��ȯ�� ���)\n", n, fibonacci_iterative(n));
                break;
            }
            break;

        default:
            printf("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �����ϼ���.\n");
        }
    }

    return 0;
}
