/* 파일명: PA9.01.c
 * 내용: 한 줄의 문자열을 입력받아서 공백 문자(' ', '\n', '\t', '\f', '\r', '\v')의 개수를 세는 프로그램.
 *
 * 작성자: 한종민
 * 날짜: 2025.10.10
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // 함수 원형 선언
void assignment01(void);
int count_whitespace(const char* str);

int main()
{
    assignment01();
    return 0;
}

/*
 * 함수명: assignment01()
 * 기능: 사용자로부터 문자열을 입력받고, 공백 문자의 개수를 세어 출력한다.
 */
void assignment01(void)
{
    char str[200]; // 입력 문자열 저장용 (최대 199자 + NULL)
    int count;

    printf("문자열? ");
    fgets(str, sizeof(str), stdin); // 공백 포함 입력 받기

    // 공백 문자 개수 계산
    count = count_whitespace(str);

    printf("공백 문자의 개수: %d\n", count);
}

/*
 * 함수명: count_whitespace()
 * 기능: 주어진 문자열 내의 공백 문자(' ', '\n', '\t', '\f', '\r', '\v') 개수를 센다.
 * 매개변수: const char* str - 검사할 문자열
 * 반환값: int - 공백 문자의 개수
 */
int count_whitespace(const char* str)
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case ' ':
        case '\n':
        case '\t':
        case '\f':
        case '\r':
        case '\v':
            count++;
            break;
        }
    }

    return count;
}
