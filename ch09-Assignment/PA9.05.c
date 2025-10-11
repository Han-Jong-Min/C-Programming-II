/* 파일명: PA9.05.c
 * 내용: 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic 함수를 작성하시오. strcmp_ic(lhs, rhs) 함수의 리턴값은 strcmp와 마찬가지로
         lhs가 rhs보다 크면 0보다 큰 값, 두 문자열이 같으면 0, lhs가 rhs보다 작으면 0보다 작은 값을 리턴한다. strcmp_ic 함수를 이용해서 
         입력받은 두 문자열을 비교하는 프로그램을 작성하시오.
 * 작성자: 한종민
 * 작성일: 2025.10.10
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // 함수 원형 선언
void assignment05(void);
int strcmp_ic(const char* lhs, const char* rhs);
void removeNewline(char* str);

/*
 * 함수명: main()
 * 기능: assignment05 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment05();
    return 0;
}

/*
 * 함수명: assignment05()
 * 기능: 문자열을 입력받고 strcmp_ic 함수를 이용하여 두 문자열을 비교한다.
 */
void assignment05(void)
{
    char str1[100], str2[100];
    int result;

    printf("첫 번째 문자열: ");
    fgets(str1, sizeof(str1), stdin);
    printf("두 번째 문자열: ");
    fgets(str2, sizeof(str2), stdin);

    // fgets로 입력된 문자열의 개행 문자 제거
    removeNewline(str1);
    removeNewline(str2);

    // 대소문자 구분 없는 문자열 비교
    result = strcmp_ic(str1, str2);

    if (result == 0)
        printf("\"%s\"과 \"%s\"이 같습니다.\n", str1, str2);
    else if (result > 0)
        printf("\"%s\" > \"%s\"\n", str1, str2);
    else
        printf("\"%s\" < \"%s\"\n", str1, str2);
}

/*
 * 함수명: strcmp_ic()
 * 기능: 두 문자열을 대소문자 구분 없이 비교한다.
 * 매개변수: const char* lhs - 첫 번째 문자열
 *           const char* rhs - 두 번째 문자열
 * 반환값: lhs > rhs → 양수, lhs == rhs → 0, lhs < rhs → 음수
 */
int strcmp_ic(const char* lhs, const char* rhs)
{
    while (*lhs && *rhs)
    {
        char c1 = *lhs;
        char c2 = *rhs;

        // 소문자를 대문자로 변환 (ctype.h 사용하지 않음)
        if (c1 >= 'a' && c1 <= 'z')
            c1 = c1 - 'a' + 'A';
        if (c2 >= 'a' && c2 <= 'z')
            c2 = c2 - 'a' + 'A';

        if (c1 != c2)
            return (unsigned char)c1 - (unsigned char)c2;

        lhs++;
        rhs++;
    }

    // 문자열의 길이가 다를 경우 차이 반환
    return (unsigned char)*lhs - (unsigned char)*rhs;
}

/*
 * 함수명: removeNewline()
 * 기능: fgets로 입력받은 문자열의 끝에 남은 개행 문자를 제거한다.
 * 매개변수: char* str - 처리할 문자열
 * 반환값: 없음
 */
void removeNewline(char* str)
{
    int i;
    for (i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
