/* 파일명: PA10.04.c
 * 내용: DATE 구조체와 print_date 함수를 이용하여 날짜를 출력하는 프로그램.
 * 작성자: 한종민
 * 작성일: 2025.10.11
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // DATE 구조체 정의
typedef struct
{
    int year;
    int month;
    int day;
} DATE;

// 함수 원형 선언
void assignment04(void);
void print_date(DATE date);

/*
 * 함수명: main()
 * 기능: assignment04 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment04();
    return 0;
}

/*
 * 함수명: assignment04()
 * 기능: 사용자로부터 날짜 입력을 받고 DATE 구조체에 저장 후 출력
 */
void assignment04(void)
{
    DATE today;

    // 날짜 입력
    printf("연: ");
    scanf("%d", &today.year);
    printf("월: ");
    scanf("%d", &today.month);
    printf("일: ");
    scanf("%d", &today.day);

    // 출력
    print_date(today);
}

/*
 * 함수명: print_date()
 * 기능: DATE 구조체를 받아 "YYYY/M/D" 형식으로 출력
 */
void print_date(DATE date)
{
    printf("%d/%d/%d\n", date.year, date.month, date.day);
}
