#include <stdio.h>

void main() {
    int i = 31, num; //초기값 31

    printf("정수를 입력하세요: "); //문장 출력
    scanf_s("%d", &num); //정수를 입력받음

    printf("입력된 정수의 32비트 표현: "); //문장 출력

    for (i; i >= 0; --i) { //초기값 31부터 0까지 1씩 감소하며 반복
        printf("%d", (num >> i) & 1); //num을 i만큼 오른쪽으로 이동, & 1로 최하위 비트값 추출
    }

    printf("\n"); //줄바꿈
}