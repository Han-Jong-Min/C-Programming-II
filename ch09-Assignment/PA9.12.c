/* 파일명: PA9.12.c
 * 내용: 입력받은 문자열에 대해 이동할 글자 수를 입력받아
 *       왼쪽 또는 오른쪽으로 회전(rotate)한 결과를 출력하는 프로그램.
 *       이동할 글자 수가 음수면 왼쪽, 양수면 오른쪽으로 이동.
 *       이동할 글자 수가 0이면 프로그램 종료.
 * 작성자: 한종민
 * 작성일: 2025.10.10
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

 // 함수 원형 선언
void assignment12(void);
void rotateString(char* str, int n);
void removeNewline(char* str);

/*
 * 함수명: main()
 * 기능: assignment12 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment12();
    return 0;
}

/*
 * 함수명: assignment12()
 * 기능: 문자열과 이동 글자 수를 입력받아 회전 결과를 출력한다.
 */
void assignment12(void)
{
    char str[100];
    int move;

    while (1)
    {
        printf("\n문자열? ");
        fgets(str, sizeof(str), stdin);
        removeNewline(str);

        printf("이동할 글자 수? (0 입력 시 종료) ");
        scanf("%d", &move);
        getchar(); // 남은 개행 문자 제거

        if (move == 0)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        rotateString(str, move);
        printf("%s\n", str);
    }
}

/*
 * 함수명: rotateString()
 * 기능: 문자열 str을 n글자만큼 회전한다.
 *       n > 0 → 오른쪽, n < 0 → 왼쪽
 * 매개변수: char* str - 회전할 문자열
 *           int n - 이동할 글자 수
 */
void rotateString(char* str, int n)
{
    int len = strlen(str);
    if (len == 0) return; // 빈 문자열 처리

    // 이동 글자 수를 문자열 길이로 맞춤
    n = n % len;
    if (n < 0) n = n + len; // 음수면 왼쪽 회전을 오른쪽 회전으로 변환

    char temp[100];
    int i;

    // 회전된 문자열 생성
    for (i = 0; i < len; i++)
        temp[i] = str[(i - n + len) % len];
    temp[len] = '\0';

    // 원래 문자열에 복사
    strcpy(str, temp);
}

/*
 * 함수명: removeNewline()
 * 기능: fgets로 입력받은 문자열 끝의 개행 문자 제거
 */
void removeNewline(char* str)
{
    int i;
    for (i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
