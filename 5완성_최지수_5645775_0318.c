#include <stdio.h>


//덧셈 함수: 두 정수를 더한 값 반환
int add(int num1, int num2);

//뺄셈 함수: 두 정수의 차를 반환
int subtract(int num1, int num2);

//곱셈 함수: 두 정수의 곱을 반환
int multiply(int num1, int num2);

//나눗셈 함수: 두 정수를 나눈 값 반환, 나누는 수가 0일 경우 오류 메시지 출력
float divide(int num1, int num2);

int main() {
    int num1, num2;

    printf("첫 번째 양의 정수를 입력하세요: "); //문장 출력
    scanf_s("%d", &num1); //첫 번째 양의 정수 입력받기, 정수 입력을 받기 위한 형식 지정자 %d

   
    printf("두 번째 양의 정수를 입력하세요: "); //문장 출력
    scanf_s("%d", &num2); //두 번째 양의 정수 입력받기

    //사칙연산 결과 출력
    printf("덧셈: %d\n", add(num1, num2)); //덧셈 결과 출력
    printf("뺄셈: %d\n", subtract(num1, num2)); //뺄셈 결과 출력
    printf("곱셈: %d\n", multiply(num1, num2)); //곱셈 결과 출력
    printf("나눗셈: %.2f\n", divide(num1, num2)); //나눗셈 결과 출력 (소수점 두 자릿수까지 출력)

    return 0; //프로그램 종료
}

//덧셈 함수 구현: 두 정수를 더한 값 반환
int add(int num1, int num2) {
    return num1 + num2;  // 두 수의 합을 반환
}

//뺄셈 함수 구현: 두 정수의 차를 반환
int subtract(int num1, int num2) {
    return num1 - num2; //두 수의 차를 반환
}

//곱셈 함수 구현: 두 정수의 곱 반환
int multiply(int num1, int num2) {
    return num1 * num2; //두 수의 곱을 반환
}

//나눗셈 함수 구현: 두 정수를 나눈 값을 반환 (나누는 수가 0이면 오류 처리)
float divide(int num1, int num2) {
    if (num2 == 0) { //나누는 수가 0일 경우
        printf("0으로 나눌 수 없습니다.\n"); //오류 메시지 출력
        return 0.0; //오류로 인해 0 반환
    }
    return (float)num1 / num2; //나누기 계산 후 소수점을 포함하여 결과 반환
}
