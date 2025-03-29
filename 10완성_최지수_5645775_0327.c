/*
FUNCTION MatrixAddition()
    DECLARE A, B, C AS int* //2x2 ��� (4�� ����)

    //�޸� �Ҵ� ���� �� ����
    IF memory allocation fails THEN
        PRINT "�޸� �Ҵ� ����"
        RETURN ERROR

    //ù ��° ��� �Է�
    PRINT "ù ��° 2x2 ��� �Է�:"
    FOR i FROM 0 TO 3 DO
        INPUT A[i]

    //�� ��° ��� �Է�
    PRINT "�� ��° 2x2 ��� �Է�:"
    FOR i FROM 0 TO 3 DO
        INPUT B[i]

    //��� ���� ����
    FOR i FROM 0 TO 3 DO
        C[i] = A[i] + B[i]

    //��� ���
    PRINT "��� ���� ���:"
    FOR i FROM 0 TO 3 DO
        PRINT C[i]
        IF i % 2 == 1 THEN PRINT NEW LINE

    //���� �޸� ����
    FREE A, B, C
END FUNCTION
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* A, * B, * C;
    int i;

    A = (int*)malloc(4 * sizeof(int));
    B = (int*)malloc(4 * sizeof(int));
    C = (int*)malloc(4 * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    printf("ù ��° 2x2 ��� �Է�:\n");
    for (i = 0; i < 4; i++) {
        scanf_s("%d", A + i);
    }

    printf("�� ��° 2x2 ��� �Է�:\n");
    for (i = 0; i < 4; i++) {
        scanf_s("%d", B + i);
    }

    for (i = 0; i < 4; i++) {
        *(C + i) = *(A + i) + *(B + i);
    }

    printf("��� ���� ���:\n");
    for (i = 0; i < 4; i++) {
        printf("%d ", *(C + i));
        if (i % 2 == 1) printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}

