/*
FUNCTION MatrixAddition()
    INPUT n, m
    DECLARE arr1[n][m], arr2[n][m]

    PRINT "행렬의 크기를 입력하세요 (행 열): "
    INPUT n, m

    PRINT "첫 번째 n×m 행렬 입력:"
    FOR i FROM 0 TO n-1 DO
        FOR j FROM 0 TO m-1 DO
            INPUT arr1[i][j]

    PRINT "두 번째 n×m 행렬 입력:"
    FOR i FROM 0 TO n-1 DO
        FOR j FROM 0 TO m-1 DO
            INPUT arr2[i][j]

    PRINT "행렬 덧셈 결과:"
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

    printf("행렬의 크기를 입력하세요 (행 열): ");
    scanf_s("%d %d", &n, &m);

    printf("첫 번째 %d×%d 행렬 입력:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &arr1[i][j]);
        }
    }

    printf("두 번째 %d×%d 행렬 입력:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &arr2[i][j]);
        }
    }

    printf("행렬 덧셈 결과:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
