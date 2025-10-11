/* 파일명: PA10.03.c
 * 내용: LOGIN 구조체 배열을 이용하여 로그인 과정을 처리하는 프로그램.
 *       아이디를 입력받아 등록된 LOGIN 배열에서 검색하고,
 *       패스워드가 일치하면 로그인 성공 출력.
 * 작성자: 한종민
 * 작성일: 2025.10.11
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define USER_COUNT 5

 // LOGIN 구조체 정의
typedef struct
{
    char id[MAX_LEN + 1];
    char password[MAX_LEN + 1];
} LOGIN;

// 함수 원형 선언
void assignment03(void);
void removeNewline(char* str);

/*
 * 함수명: main()
 * 기능: assignment03 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment03();
    return 0;
}

/*
 * 함수명: assignment03()
 * 기능: LOGIN 배열에서 아이디/패스워드를 확인하여 로그인 성공 여부 출력
 */
void assignment03(void)
{
    // LOGIN 구조체 배열 초기화
    LOGIN users[USER_COUNT] = {
        {"aaaaaa", "abcd123"},
        {"bbbbbb", "abcd456"},
        {"cccccc", "abcd789"},
        {"dddddd", "abcd321"},
        {"eeeeee", "abcd654"}
    };

    char inputId[MAX_LEN + 1];
    char inputPw[MAX_LEN + 1];
    int i;
    int found = 0;

    // 아이디 입력
    printf("ID? ");
    fgets(inputId, sizeof(inputId), stdin);
    removeNewline(inputId);

    // 배열에서 아이디 검색
    for (i = 0; i < USER_COUNT; i++)
    {
        if (strcmp(users[i].id, inputId) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("로그인 실패: 아이디가 존재하지 않습니다.\n");
        return;
    }

    // 패스워드 입력
    printf("PW? ");
    fgets(inputPw, sizeof(inputPw), stdin);
    removeNewline(inputPw);

    if (strcmp(users[i].password, inputPw) == 0)
        printf("로그인 성공\n");
    else
        printf("로그인 실패\n");
}

/*
 * 함수명: removeNewline()
 * 기능: fgets로 입력받은 문자열 끝의 개행 문자 제거
 */
void removeNewline(char* str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
