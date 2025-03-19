#include <stdio.h>
#include <string.h>

int main() {
    char str[1000]; //최대 999자 + 문자열 종료 문자

    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin); //입력 받음(공백 포함)

    if (str[strlen(str) - 1] == '\n') //개행 문자 제거
        str[strlen(str) - 1] = '\0';

    printf("문자열의 길이: %ld\n", strlen(str)); //공백 포함 문자열 길이 계산

    printf("변환된 문자열: ");
    for (int i = 0; str[i]; i++) //문자열이 끝날 때까지 반복
        printf("%c",
            (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : //대문자를 소문자로 변환
            (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : //소문자를 대문자로 변환
            str[i]); //나머지는 그대로 출력
    printf("\n");

    return 0;
}