/*
FUNCTION compare(a, b)
    RETURN (a - b)

FUNCTION SortNumbers()
    // 정수 개수 입력받기
    PRINT "정수의 개수를 입력하세요: "
    INPUT N

    // 크기 N의 배열 동적 할당
    DECLARE arr[N]

    // 정수 입력받기 (공백 또는 엔터로 구분 가능)
    PRINT "N개의 정수를 입력하세요:"
    FOR i FROM 0 TO N-1 DO
        INPUT arr[i]

    // 정렬 수행 (qsort 사용)
    CALL qsort(arr, N, sizeof(int), compare)

    // 정렬된 정수 출력
    PRINT "오름차순으로 정렬된 정수들:"
    FOR i FROM 0 TO N-1 DO
        PRINT arr[i], " "
    PRINT NEW LINE  // 줄 바꿈

    // 동적 할당 해제
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
    printf("정수의 개수를 입력하세요: ");
    scanf_s("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));

    printf("%d개의 정수를 입력하세요:\n", N);
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    printf("오름차순으로 정렬된 정수들:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
