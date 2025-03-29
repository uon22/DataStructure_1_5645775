/*
FUNCTION MatrixAddition()
    DECLARE A, B, C AS int* //2x2 행렬 (4개 원소)

    //메모리 할당 실패 시 종료
    IF memory allocation fails THEN
        PRINT "메모리 할당 실패"
        RETURN ERROR

    //첫 번째 행렬 입력
    PRINT "첫 번째 2x2 행렬 입력:"
    FOR i FROM 0 TO 3 DO
        INPUT A[i]

    //두 번째 행렬 입력
    PRINT "두 번째 2x2 행렬 입력:"
    FOR i FROM 0 TO 3 DO
        INPUT B[i]

    //행렬 덧셈 수행
    FOR i FROM 0 TO 3 DO
        C[i] = A[i] + B[i]

    //결과 출력
    PRINT "행렬 덧셈 결과:"
    FOR i FROM 0 TO 3 DO
        PRINT C[i]
        IF i % 2 == 1 THEN PRINT NEW LINE

    //동적 메모리 해제
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
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("첫 번째 2x2 행렬 입력:\n");
    for (i = 0; i < 4; i++) {
        scanf_s("%d", A + i);
    }

    printf("두 번째 2x2 행렬 입력:\n");
    for (i = 0; i < 4; i++) {
        scanf_s("%d", B + i);
    }

    for (i = 0; i < 4; i++) {
        *(C + i) = *(A + i) + *(B + i);
    }

    printf("행렬 덧셈 결과:\n");
    for (i = 0; i < 4; i++) {
        printf("%d ", *(C + i));
        if (i % 2 == 1) printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}

