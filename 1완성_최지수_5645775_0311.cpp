#include <stdio.h>

void main() {
    int i = 31, num;

    printf("정수를 입력하세요: ");
    scanf_s("%d", &num);

    printf("입력된 정수의 32비트 표현: ");

    for (i; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }

    printf("\n");
}