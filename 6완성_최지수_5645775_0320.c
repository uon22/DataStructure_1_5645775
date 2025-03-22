/*
1. 시작한다.

2. 사용자에게 정수 N을 입력받는다.

3. 소수를 저장할 배열과 소수 개수를 위한 변수를 초기화 한다.

4. 2부터 N까지 i를 반복한다.
   4.1 i가 소수인지 판별하는 isPrime 변수를 1로 초기화 한다.
   4.2 j를 2부터 i의 제곱근까지 반복한다.
        a. i가 j로 나누어 떨어진다면 isPrime을 0으로 설정 후 반복을 종료한다.
   4.3 isPrime이 1이면 i를 소수 배열에 저장한다.

5. 출력 단계:
   5.1 "N 이하의 소수: "를 출력한다.
   5.2 저장된 배열의 인덱스 0부터 Length-1까지 반복한다.
   5.3 해당 인덱스에 있는 소수를 출력한다.
   5.4 출력 후에 줄바꿈 한다.

6. 프로그램 종료

/* 시간 복잡도 분석:
2부터 N까지의 수를 하나씩 확인하는 외부 반복문 → O(N)
각 수 i에 대해 2부터 sqrt(i)까지 나누어보는 내부 반복문 → O(√N)
따라서 전체 시간 복잡도는 O(N√N)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    printf("정수 n을 입력하세요 : ");
    scanf_s("%d", &num);

    //동적 배열 크기 할당
    int* arr = (int*)malloc(num * sizeof(int));

    //메모리 할당 실패 시 오류 메시지 출력 후 종료
    if (arr == NULL) {
        printf("메모리 할당 실패!\n");
        return 1; //메모리 할당 실패 시 종료
    }

    int length = 0; //소수를 저장할 배열의 길이 초기화
    int i, j; //반복문을 위한 변수들 선언
    int isPrime; //소수 판별을 위한 변수

    //2부터 num까지 반복하며 소수를 찾음
    for (i = 2; i <= num; i++) {
        isPrime = 1; //i가 소수라고 가정하고 시작

        //i의 제곱근까지 확인하여 i가 소수인지 판별
        for (j = 2; j * j <= i; j++) {
            //i가 j로 나누어떨어지면 소수가 아니므로 isPrime을 0으로 설정하고 반복 종료
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        //isPrime이 1이면 i는 소수이므로 배열에 저장
        if (isPrime == 1) {
            arr[length] = i; //소수를 배열에 저장
            length++; //소수가 하나 추가되었으므로 배열 길이 증가
        }
    }

    //소수 출력
    printf("N 이하의 소수: ");
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]); //배열에 저장된 소수 출력
    }
    printf("\n");

    //동적 할당 메모리 해제
    free(arr);

    return 0; //프로그램 종료
}
