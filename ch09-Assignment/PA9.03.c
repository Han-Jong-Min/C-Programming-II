/* 파일명: PA9.03.c
 * 내용: 입력받은 문자열의 소문자는 대문자로, 대문자는 소문자로 변환하는 프로그램.
 *      
 * 작성자: 한종민
 * 날짜: 2025.10.10
 * 버전: v1.1
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // 함수 원형 선언
void assignment03(void);
void convert_case(char* str);

int main()
{
    assignment03();
    return 0;
}

/*
 * 함수명: assignment03()
 * 기능: 문자열을 입력받아 대소문자를 변환하고 결과를 출력한다.
 */
void assignment03(void)
{
    char str[200];

    printf("문자열? ");
    fgets(str, sizeof(str), stdin); // 공백 포함 입력 받기

    // 대소문자 변환
    convert_case(str);

    // 결과 출력
    printf("변환 후: %s", str);
}

/*
 * 함수명: convert_case()
 * 기능: 소문자는 대문자로, 대문자는 소문자로 변환한다.
 */

void convert_case(char* str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        // 'A'(65) ~ 'Z'(90): 대문자
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A'); // 32 더하기 → 소문자 변환
        }
        // 'a'(97) ~ 'z'(122): 소문자
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A'); // 32 빼기 → 대문자 변환
        }
    }
}
