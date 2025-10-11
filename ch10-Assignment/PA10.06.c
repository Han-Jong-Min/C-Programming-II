/* 파일명: PA10.06.c
 * 내용: DATE 구조체와 is_same_date 함수를 이용하여 입력 날짜가 공휴일인지 검사하는 프로그램.
 * 작성자: 한종민
 * 작성일: 2025.10.11
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
} DATE;

// 함수 원형 선언
void assignment06(void);
int is_same_date(DATE d1, DATE d2);
void print_date(DATE date);

/*
 * 함수명: main()
 * 기능: assignment06 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment06();
    return 0;
}

/*
 * 함수명: assignment06()
 * 기능: 입력받은 날짜가 공휴일인지 검사
 */
void assignment06(void)
{
    // 공휴일 배열 초기화
    DATE holidays[] = {
        {2025, 1, 1},   // 새해
        {2025, 3, 1},   // 삼일절
        {2025, 5, 5},   // 어린이날
        {2025, 6, 6},   // 현충일
        {2025, 8, 15},  // 광복절
        {2025, 10, 3},  // 개천절
        {2025, 12, 25}  // 성탄절
    };
    int holidayCount = sizeof(holidays) / sizeof(holidays[0]);

    DATE input;

    while (1)
    {
        // 사용자 입력
        printf("날짜 입력 (연 월 일, 종료: 0 0 0): ");
        scanf("%d %d %d", &input.year, &input.month, &input.day);

        if (input.year == 0 && input.month == 0 && input.day == 0)
        {
            printf("프로그램 종료.\n");
            break;
        }

        int isHoliday = 0;
        for (int i = 0; i < holidayCount; i++)
        {
            if (is_same_date(input, holidays[i]))
            {
                isHoliday = 1;
                break;
            }
        }

        if (isHoliday)
        {
            print_date(input);
            printf("는 공휴일입니다.\n");
        }
        else
        {
            print_date(input);
            printf("는 공휴일이 아닙니다.\n");
        }
    }
}

/*
 * 함수명: is_same_date()
 * 기능: 두 DATE 구조체가 같은 날짜인지 비교
 * 반환값: 같으면 1, 다르면 0
 */
int is_same_date(DATE d1, DATE d2)
{
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}

/*
 * 함수명: print_date()
 * 기능: DATE 구조체를 "YYYY/M/D" 형식으로 출력
 */
void print_date(DATE date)
{
    printf("%d/%d/%d", date.year, date.month, date.day);
}
