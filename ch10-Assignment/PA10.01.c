/* 파일명: PA10.01.c
 * 내용: 인터넷 사이트 로그인 정보를 저장하는 LOGIN 구조체를 정의하고
 *       아이디와 패스워드를 입력받아 출력하는 프로그램.
 *       패스워드는 글자 수만큼 '*'로 표시.
 * 작성자: 한종민
 * 작성일: 2025.10.11
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

 // LOGIN 구조체 정의
typedef struct
{
    char id[MAX_LEN + 1];
    char password[MAX_LEN + 1];
} LOGIN;

// 함수 원형 선언
void assignment01(void);
void removeNewline(char* str);

/*
 * 함수명: main()
 * 기능: assignment01 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment01();
    return 0;
}

/*
 * 함수명: assignment01()
 * 기능: LOGIN 구조체 변수에 아이디와 패스워드를 입력받아 저장하고 출력
 */
void assignment01(void)
{
    LOGIN user;

    // 아이디 입력
    printf("ID? ");
    fgets(user.id, sizeof(user.id), stdin);
    removeNewline(user.id);

    // 패스워드 입력
    printf("PW? ");
    fgets(user.password, sizeof(user.password), stdin);
    removeNewline(user.password);

    // 출력
    printf("\n");
    printf("ID: %s\n", user.id);
    printf("PW: ");
    for (int i = 0; user.password[i] != '\0'; i++)
        printf("*");
    printf("\n");
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
