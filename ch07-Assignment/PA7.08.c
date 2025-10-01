/* 파일명: PA7.08.c

  * 내용: 상품 가격이 저장된 정수형 배열에 대하여 할인율을 입력받아 할인된 가격을
          계산해서 출력하는 프로그램을 작성하시오. 상품 가격이 저장된 배열의 크기는 5이고,
          상품 가격은 입력받아서 사용한다. 할인된 가격은 별도의 배열에 저장해야 한다.

  * 작성자: 한종민

  * 날짜: 2025.09.16.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int assignment08(void);
void inputPrices(int arr[], int size);
void calcDiscount(int arr[], int discounted[], int size, int rate);
void printResult(int arr[], int discounted[], int size);

int main() {
    return assignment08();
}

int assignment08(void) {
    int prices[SIZE];          // 원래 가격 배열
    int discounted[SIZE];      // 할인된 가격 배열
    int rate;                  // 할인율 (정수, % 단위)

    // 상품 가격 입력
    printf("상품가 %d개를 입력하세요:\n", SIZE);
    inputPrices(prices, SIZE);

    // 할인율 입력
    printf("할인율(%)? ");
    scanf("%d", &rate);

    // 할인된 가격 계산
    calcDiscount(prices, discounted, SIZE, rate);

    // 결과 출력
    printf("\n===== 결과 =====\n");
    printResult(prices, discounted, SIZE);

    return 0;
}

/*
 * 함수명: inputPrices()
 * 기능: 상품 가격들을 입력받아 배열에 저장한다.
 */
void inputPrices(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

/*
 * 함수명: calcDiscount()
 * 기능: 상품 가격 배열을 바탕으로 할인된 가격을 계산한다.
 */
void calcDiscount(int arr[], int discounted[], int size, int rate) {
    for (int i = 0; i < size; i++) {
        discounted[i] = arr[i] * (100 - rate) / 100;  // 정수 계산
    }
}

/*
 * 함수명: printResult()
 * 기능: 원래 가격과 할인된 가격을 나란히 출력한다.
 */
void printResult(int arr[], int discounted[], int size) {
    for (int i = 0; i < size; i++) {
        printf("가격: %d    -->    할인가: %d\n", arr[i], discounted[i]);
    }
}