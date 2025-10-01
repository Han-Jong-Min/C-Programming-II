/* 파일명: PA7.09.c

  * 내용: 1~12월의 핸드폰 요금을 배열에 저장하고 화면에 막대 그래프로 출력하는 프로그램을
          작성하시오. 12개월의 핸드폰 요금이 들어있는 배열을 특정 값으로 초기화해서 사용하고,
          핸드폰 요금 2000원 당 '*'를 하나씩 막대 그래프로 출력한다.

  * 작성자: 한종민

  * 날짜: 2025.09.16.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define UNIT 2000  // 2000원 당 '*' 하나

int assignment09(void);
void initFees(int fees[], int size);
void printBarGraph(int fees[], int size);

int main() {
    return assignment09();
}

int assignment09(void) {
    int fees[MONTHS];

    // 요금 배열 초기화
    initFees(fees, MONTHS);

    // 막대 그래프 출력
    printf("===== 1~12월 핸드폰 요금 막대 그래프 =====\n");
    printBarGraph(fees, MONTHS);

    return 0;
}

/*
 * 함수명: initFees()
 * 기능: 요금 배열을 특정 값으로 초기화한다.
 */
void initFees(int fees[], int size) {
    int temp[MONTHS] = {
        25000, 30000, 28000, 35000, 40000, 32000,
        27000, 31000, 33000, 29000, 36000, 34000
    };

    for (int i = 0; i < size; i++) {
        fees[i] = temp[i];
    }
}

/*
 * 함수명: printBarGraph()
 * 기능: 요금을 기준으로 '*' 막대 그래프를 출력한다.
 */
void printBarGraph(int fees[], int size) {
    for (int i = 0; i < size; i++) {
        int stars = fees[i] / UNIT;  // '*' 개수 계산
        printf("%2d월 (%5d원): ", i + 1, fees[i]);
        for (int j = 0; j < stars; j++) {
            printf("*");
        }
        printf("\n");
    }
}