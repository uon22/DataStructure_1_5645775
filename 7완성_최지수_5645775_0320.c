#include <stdio.h>

//사칙연산 함수 선언
double add(double a, double b); //덧셈 함수
double subtract(double a, double b); //뺄셈 함수
double multiply(double a, double b); //곱셈 함수
double divide(double a, double b); //나눗셈 함수

int main() {
    char ch;
    double num, term, sum = 0; //term으로 곱셈/나눗셈 중간값 저장
    char prev_op = '+'; //이전 연산자 저장

    //수식 입력받음
    printf("계산할 수식을 입력하세요 (예: 3+5*2-8/4=): ");
    scanf_s("%lf", &term);

    sum = 0; //초기화

    while (1) {
        scanf_s(" %c", &ch, 1); //연산자 입력

        if (ch == '=') {
            sum = (prev_op == '+') ? add(sum, term) : subtract(sum, term); //마지막 계산 적용
            printf("결과: %.6f\n", sum); //결과 출력
            break;
        }

        scanf_s("%lf", &num); //다음 숫자 입력

        if (ch == '*' || ch == '/') {
            // 곱셈, 나눗셈은 term에 적용
            if (ch == '*') term = multiply(term, num);
            else term = divide(term, num);
        }
        else {
            // 덧셈, 뺄셈이면 이전 곱셈/나눗셈 결과를 sum에 반영 후 term 초기화
            sum = (prev_op == '+') ? add(sum, term) : subtract(sum, term);
            term = num;
            prev_op = ch;
        }
    }

    return 0;
}

//사칙연산 함수 정의
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return (b != 0) ? (a / b) : 0; //0으로 나누는 경우 방지
}
