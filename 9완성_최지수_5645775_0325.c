/*
FUNCTION compare(a, b)
    RETURN (a - b)

FUNCTION SortNumbers()
    // ���� ���� �Է¹ޱ�
    PRINT "������ ������ �Է��ϼ���: "
    INPUT N

    // ũ�� N�� �迭 ���� �Ҵ�
    DECLARE arr[N]

    // ���� �Է¹ޱ� (���� �Ǵ� ���ͷ� ���� ����)
    PRINT "N���� ������ �Է��ϼ���:"
    FOR i FROM 0 TO N-1 DO
        INPUT arr[i]

    // ���� ���� (qsort ���)
    CALL qsort(arr, N, sizeof(int), compare)

    // ���ĵ� ���� ���
    PRINT "������������ ���ĵ� ������:"
    FOR i FROM 0 TO N-1 DO
        PRINT arr[i], " "
    PRINT NEW LINE  // �� �ٲ�

    // ���� �Ҵ� ����
    FREE arr

END FUNCTION
*/


#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    printf("������ ������ �Է��ϼ���: ");
    scanf_s("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));

    printf("%d���� ������ �Է��ϼ���:\n", N);
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    printf("������������ ���ĵ� ������:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
