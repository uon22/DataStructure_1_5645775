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
    a. 해당 인덱스에 있는 소수를 출력한다.
   5.3 출력 후에 줄바꿈 한다.

6. 프로그램 종료
*/

#include <stdio.h>

int main() {
    int num;
    int arr[1000];
    int length = 0;

    printf("정수 N을 입력하세요: ");
    scanf_s("%d", &num);

    for (int i = 2; i <= num; i++) {
        int isPrime = 1; //소수 판별 변수
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            arr[length++] = i; //배열에 소수 저장
        }
    }

    printf("N 이하의 소수: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
