/* 파일명: PA10.02.c
 * 내용: 1번 프로그램의 아이디와 패스워드를 항상 소문자로 저장하려고 한다. LOGIN 구조체를 매개변수로 전달받아 
        구조체에 저장된 아이디와 패스워드를 모두 소문자로 만드는 make_lower 함수와 아이디와 패스워드를 출력하는 
        print_login 함수를 정의하시오
 * 작성자: 한종민
 * 작성일: 2025.10.11
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN 20

 // LOGIN 구조체 정의
typedef struct
{
    char id[MAX_LEN + 1];
    char password[MAX_LEN + 1];
} LOGIN;

// 함수 원형 선언
void assignment02(void);
void removeNewline(char* str);
void make_lower(LOGIN* user);
void print_login(const LOGIN* user);

/*
 * 함수명: main()
 * 기능: assignment02 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment02();
    return 0;
}

/*
 * 함수명: assignment02()
 * 기능: LOGIN 구조체 변수에 아이디와 패스워드를 입력받아 소문자로 변환 후 출력
 */
void assignment02(void)
{
    LOGIN user;

    // 아이디 입력
    printf("아이디 입력: ");
    fgets(user.id, sizeof(user.id), stdin);
    removeNewline(user.id);

    // 패스워드 입력
    printf("패스워드 입력: ");
    fgets(user.password, sizeof(user.password), stdin);
    removeNewline(user.password);

    // 소문자로 변환
    make_lower(&user);

    // 출력
    print_login(&user);
}

/*
 * 함수명: make_lower()
 * 기능: LOGIN 구조체 변수에 저장된 아이디와 패스워드를 모두 소문자로 변환
 */
void make_lower(LOGIN* user)
{
    for (int i = 0; user->id[i] != '\0'; i++)
    {
        if (user->id[i] >= 'A' && user->id[i] <= 'Z')
            user->id[i] += 'a' - 'A';
    }

    for (int i = 0; user->password[i] != '\0'; i++)
    {
        if (user->password[i] >= 'A' && user->password[i] <= 'Z')
            user->password[i] += 'a' - 'A';
    }
}

/*
 * 함수명: print_login()
 * 기능: 아이디와 패스워드를 출력, 패스워드는 '*'로 표시
 */
void print_login(const LOGIN* user)
{
    printf("\n");
    printf("아이디: %s\n", user->id);
    printf("패스워드: ");
    for (int i = 0; user->password[i] != '\0'; i++)
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
