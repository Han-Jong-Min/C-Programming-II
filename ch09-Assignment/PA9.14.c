/* 파일명: PA9.14.c
 * 내용: 인터넷 사이트에 회원 가입을 하려는 사용자로부터 아이디를 입력받아
 *       유효한 아이디인지 검사하는 프로그램을 작성한다.
 *       아이디는 영문자로 시작해야 하고, 영문자와 숫자로만 구성되며
 *       최소 8자 이상이어야 한다.
 * 작성자: 한종민
 * 작성일: 2025.10.10
 * 버전: v1.1
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // 함수 원형 선언
void assignment14(void);
int isValidID(const char* id);
void removeNewline(char* str);

/*
 * 함수명: main()
 * 기능: assignment14 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment14();
    return 0;
}

/*
 * 함수명: assignment14()
 * 기능: 사용자로부터 아이디를 입력받아 유효성 검사 후 결과를 출력한다.
 */
void assignment14(void)
{
    char id[100];
    int valid;

    printf("ID? ");
    fgets(id, sizeof(id), stdin);
    removeNewline(id);

    valid = isValidID(id);

    if (valid)
        printf("'%s'은(는) ID로 사용할 수 있습니다.\n", id);
}

/*
 * 함수명: isValidID()
 * 기능: 입력된 문자열이 아이디 조건(영문 시작, 영문/숫자 구성, 8자 이상)을 만족하는지 검사한다.
 * 매개변수: const char* id - 검사할 아이디 문자열
 * 반환값: 조건을 만족하면 1, 그렇지 않으면 0
 */
int isValidID(const char* id)
{
    int i, len = 0;

    // 첫 글자가 영문자가 아니면 실패
    if (!((*id >= 'A' && *id <= 'Z') || (*id >= 'a' && *id <= 'z')))
    {
        printf("ID는 영문자로 시작해야 합니다.\n");
        return 0;
    }

    // 각 문자 확인
    for (i = 0; id[i] != '\0'; i++)
    {
        char c = id[i];
        if (!((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')))
        {
            printf("ID는 영문자와 숫자로만 구성되어야 합니다.\n");
            return 0;
        }
        len++;
    }

    // 길이가 8자 미만이면 실패
    if (len < 8)
    {
        printf("ID는 8자 이상이어야 합니다.\n");
        return 0;
    }

    return 1; // 모든 조건을 통과하면 유효
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
