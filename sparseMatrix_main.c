#include <stdio.h>
#include "sparseMatrix.h"

int main() {
    listType* A, * B, * R;

    printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
    A = inputMatrix();

    printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
    B = inputMatrix();

    R = addSparseMatrix(A, B);
    printf("두 행렬의 합\n");
    printList(R);

    free(A);
    free(B);
    free(R);
    return 0;
}
