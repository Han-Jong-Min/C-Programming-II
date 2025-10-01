/* 파일명: PA7.13.c

  * 내용: 비트 OR 연산자를 이용하면 두 이미지를 합칠 수 있다. 크기가 같은 2개의 unsigned char 배열을
         비트 OR 연산한 결과를 출력하는 프로그램을 작성하시오. unsigned char 배열 2개는 크기가 16인
         배열로 선언하고 임의의 데이터(0~255)를 채우고, 비트 OR 연산 결과를 저장할 배열을 따로 선언해서
         사용하시오.

  * 작성자: 한종민

  * 날짜: 2025.09.17.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

int assignment13(void);
void fillArray(unsigned char arr[], int size);
void bitwiseOr(unsigned char arr1[], unsigned char arr2[], unsigned char result[], int size);
void printArray(const char* label, unsigned char arr[], int size);

int main() {
    return assignment13();
}

int assignment13(void) {
    unsigned char arr1[SIZE], arr2[SIZE], result[SIZE];

    srand(time(NULL)); // 랜덤 시드 설정

    fillArray(arr1, SIZE);
    fillArray(arr2, SIZE);
    bitwiseOr(arr1, arr2, result, SIZE);

    printArray("image1", arr1, SIZE);
    printArray("image2", arr2, SIZE);
    printArray("result", result, SIZE);

    return 0;
}

/*
 * 함수명: fillArray()
 * 기능: 배열에 0~255 범위의 랜덤 값 채움
 * 매개변수: unsigned char arr[] - 대상 배열, int size - 배열 크기
 * 반환값: 없음
 */
void fillArray(unsigned char arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 256;
    }
}

/*
 * 함수명: bitwiseOr()
 * 기능: 두 배열의 같은 위치 원소를 비트 OR 연산
 * 매개변수: unsigned char arr1[], arr2[], result[] - 대상 배열들, int size - 배열 크기
 * 반환값: 없음
 */

void bitwiseOr(unsigned char arr1[], unsigned char arr2[], unsigned char result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] | arr2[i];
    }
}

/*
 * 함수명: printArray()
 * 기능: 배열 값을 16진수(대문자)로 출력
 * 매개변수: const char *label - 배열 이름, unsigned char arr[] - 출력할 배열, int size - 배열 크기
 * 반환값: 없음
 */
void printArray(const char* label, unsigned char arr[], int size) {
    printf("%s: ", label);
    for (int i = 0; i < size; i++) {
        printf("%02X ", arr[i]);
    }
    printf("\n");
}