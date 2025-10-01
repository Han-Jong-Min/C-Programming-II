/* 파일명: PA7.12.c

  * 내용: 기차표 예매 프로그램을 작성하려고 한다. 간단한 구현을 위해 좌석은 모두
          10개라고 하자. 예매할 좌석수를 입력받아 빈 자리를 할당한다. 예매할 때마다 각 좌석의 상태를 출력한다.
          O이면 예매 가능, X는 예매 불가를 의미한다. 더 이상 예매할 수 없으면 프로그램을 종료한다.

  * 작성자: 한종민

  * 날짜: 2025.09.17.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int assignment12(void);
void printSeats(char seats[], int size);
int reserveSeats(char seats[], int size, int count, int reservedIndex[]);
int countAvailable(char seats[], int size);

int main()
{
    return assignment12();
}

#define SEAT_COUNT 10

int assignment12(void)
{
    char seats[SEAT_COUNT] = { 'O','O','O','O','O','O','O','O','O','O' };
    int num;

    while (1)
    {
        // 현재 좌석 상태 출력
        printSeats(seats, SEAT_COUNT);

        // 남은 좌석이 없으면 종료
        if (countAvailable(seats, SEAT_COUNT) == 0)
        {
            printf("더 이상 예매할 수 없습니다. 프로그램을 종료합니다.\n");
            break;
        }

        printf("예매할 좌석 수? ");
        scanf("%d", &num);

        if (num <= 0)
        {
            printf("잘못된 입력입니다. 1 이상의 숫자를 입력하세요.\n");
            continue;
        }

        int reservedIndex[SEAT_COUNT] = { 0 };  // 예매된 좌석 번호 저장
        if (reserveSeats(seats, SEAT_COUNT, num, reservedIndex))
        {
            printf("다음 좌석이 예매되었습니다: ");
            for (int i = 0; i < num; i++)
            {
                printf("%d ", reservedIndex[i] + 1); // 좌석 번호는 1부터 출력
            }
            printf("\n");
        }
        else
        {
            printf("좌석이 부족하여 %d개를 예매할 수 없습니다.\n", num);
        }
    }

    return 0;
}

/*
  * 함수명: printSeats()
  * 기능: 좌석 상태를 출력한다.
  * 매개변수: char seats[] - 좌석 배열, int size - 좌석 개수
  * 반환값: 없음
*/
void printSeats(char seats[], int size)
{
    printf("현재 좌석: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", seats[i]);
    }
    printf("\n");
}

/*
  * 함수명: reserveSeats()
  * 기능: 좌석을 예매하고 예매된 좌석 인덱스를 reservedIndex[]에 저장
  * 매개변수:
  *   - seats[]: 좌석 배열
  *   - size: 좌석 개수
  *   - count: 예매할 좌석 수
  *   - reservedIndex[]: 예매된 좌석 번호 저장용 배열
  * 반환값: 성공 시 1, 실패 시 0
*/
int reserveSeats(char seats[], int size, int count, int reservedIndex[])
{
    int reserved = 0;

    for (int i = 0; i < size && reserved < count; i++)
    {
        if (seats[i] == 'O')
        {
            seats[i] = 'X';
            reservedIndex[reserved] = i;
            reserved++;
        }
    }

    return (reserved == count) ? 1 : 0;
}

/*
  * 함수명: countAvailable()
  * 기능: 예약 가능한 좌석 수를 센다.
  * 반환값: 예약 가능한 좌석 수
*/
int countAvailable(char seats[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (seats[i] == 'O')
            count++;
    }
    return count;
}