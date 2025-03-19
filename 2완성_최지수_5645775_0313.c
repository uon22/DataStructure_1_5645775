#include <stdio.h>

union FloatToBits { //float 값을 unsigned int로 변환하기 위한 구조체
    float f;
    unsigned int bits; //메모리를 공유하는 정수값
};

int main() {
    union FloatToBits num; //유니온 변수

    printf("실수를 입력하세요: ");
    scanf_s("%f", &num.f); //입력받은 값을 f에 저장

    unsigned int bits = num.bits; //IEEE 754 32비트 패턴을 변수에 저장

    printf("부호 (1비트): %d\n", bits >> 31); //31비트 오른쪽으로 이동 후 최상위 비트만 남김

    printf("지수 (8비트): ");
    for (int i = 7; i >= 0; i--) //8비트 반복
        printf("%d ", (bits >> (23 + i)) & 1); //23+i만큼 오른쪽으로 이동, 지수 부분 최하위로 이동, &1로 해당 비트만 출력

    printf("\n");

    printf("가수 (23비트): ");
    for (int i = 22; i >= 0; i--) //23비트 반복
        printf("%d ", (bits >> i) & 1); //i만큼 오른쪽으로 이동, 가수 부분 최하위 이동, &1로 해당 비트만 출력

    printf("\n");

    return 0;
}