#include <stdio.h>
#include "sparseMatrix.h"

int main() {
    listType* A, * B, * R;

    printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
    A = inputMatrix();

    printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
    B = inputMatrix();

    R = addSparseMatrix(A, B);
    printf("�� ����� ��\n");
    printList(R);

    free(A);
    free(B);
    free(R);
    return 0;
}
