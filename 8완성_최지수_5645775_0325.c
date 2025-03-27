/*
FUNCTION MatrixAddition()
    INPUT n, m
    DECLARE arr1[n][m], arr2[n][m]

    PRINT "����� ũ�⸦ �Է��ϼ��� (�� ��): "
    INPUT n, m

    PRINT "ù ��° n��m ��� �Է�:"
    FOR i FROM 0 TO n-1 DO
        FOR j FROM 0 TO m-1 DO
            INPUT arr1[i][j]

    PRINT "�� ��° n��m ��� �Է�:"
    FOR i FROM 0 TO n-1 DO
        FOR j FROM 0 TO m-1 DO
            INPUT arr2[i][j]

    PRINT "��� ���� ���:"
    FOR i FROM 0 TO n-1 DO
        FOR j FROM 0 TO m-1 DO
            PRINT arr1[i][j] + arr2[i][j], " "
        PRINT NEW LINE 

END FUNCTION
*/

#include <stdio.h>

int main() {
    int n, m;
    int arr1[101][101], arr2[101][101];

    printf("����� ũ�⸦ �Է��ϼ��� (�� ��): ");
    scanf_s("%d %d", &n, &m);

    printf("ù ��° %d��%d ��� �Է�:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &arr1[i][j]);
        }
    }

    printf("�� ��° %d��%d ��� �Է�:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &arr2[i][j]);
        }
    }

    printf("��� ���� ���:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
