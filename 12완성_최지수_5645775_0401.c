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
        PRINT "피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): "
        INPUT method
        SWITCH (method)
            CASE 0:
                PRINT "프로그램이 종료되었습니다."
                RETURN 0
            CASE 1, 2:
                PRINT "정수 N을 입력하세요 (종료하려면 0 입력): "
                INPUT n
                IF n == 0 THEN
                    PRINT "프로그램이 종료되었습니다."
                    RETURN 0
                SWITCH (method)
                    CASE 1:
                        PRINT "F(n) =", fibonacci_recursive(n), "(재귀적 방법)"
                    CASE 2:
                        PRINT "F(n) =", fibonacci_iterative(n), "(순환적 방법)"
                END SWITCH
            DEFAULT:
                PRINT "잘못된 입력입니다. 1 또는 2를 선택하세요."
    END WHILE
END FUNCTION
*/

#include <stdio.h>

//재귀적 방법
int fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

//순환적 방법 (반복문)
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
        printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): ");
        scanf_s("%d", &method);

        switch (method) {
        case 0:
            printf("프로그램이 종료되었습니다.\n");
            return 0;

        case 1:
        case 2:
            printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
            scanf_s("%d", &n);

            if (n == 0) {
                printf("프로그램이 종료되었습니다.\n");
                return 0;
            }

            switch (method) {
            case 1:
                printf("F(%d) = %d (재귀적 방법)\n", n, fibonacci_recursive(n));
                break;
            case 2:
                printf("F(%d) = %d (순환적 방법)\n", n, fibonacci_iterative(n));
                break;
            }
            break;

        default:
            printf("잘못된 입력입니다. 1 또는 2를 선택하세요.\n");
        }
    }

    return 0;
}
