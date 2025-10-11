/* 파일명: PA8.15.c

  * 내용: 7장의 선택 정렬 코드를 이용해서 정수형 배열을 정렬하는 sort_array 함수를 정의하시오.
		  크기가 10인 int 배열에 0~99사이의 임의의 정수를 채운 다음 sort_array 함수로 정렬한 결과를
		  출력하는 프로그램을 작성하시오.

  * 작성자: 한종민

  * 날짜: 2025.9.23.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   // rand(), srand() 함수 사용
#include <time.h>     // time() 함수 사용

#define ARRAY_SIZE 10 // 배열 크기 상수 정의

  // 함수 원형 선언
void assignment15(void);
void initializeArray(int arr[], int size);
void printArray(int arr[], int size);
void sort_array(int arr[], int size);

int main()
{
    assignment15();
    return 0;
}

/*
 * 함수명: assignment15()
 * 기능: 전체 프로그램의 흐름 제어
 */
void assignment15(void)
{
    int numbers[ARRAY_SIZE];

    // 1. 배열 초기화 (0~99 사이의 난수로)
    initializeArray(numbers, ARRAY_SIZE);

    // 2. 정렬 전 배열 출력
    printf("정렬 전 배열: ");
    printArray(numbers, ARRAY_SIZE);

    // 3. 선택 정렬로 배열 정렬
    sort_array(numbers, ARRAY_SIZE);

    // 4. 정렬 후 배열 출력
    printf("정렬 후 배열: ");
    printArray(numbers, ARRAY_SIZE);
}

/*
 * 함수명: initializeArray()
 * 기능: 배열을 0~99 사이의 임의의 정수로 초기화
 */
void initializeArray(int arr[], int size)
{
    int i;
    srand((unsigned int)time(NULL)); // 난수 시드 설정

    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % 100; // 0~99 사이의 값
    }
}

/*
 * 함수명: printArray()
 * 기능: 배열의 모든 원소를 출력
 */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * 함수명: sort_array()
 * 기능: 선택 정렬(Selection Sort) 알고리즘으로 배열을 오름차순 정렬
 */
void sort_array(int arr[], int size)
{
    int i, j, min_index, temp;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // 두 원소 교환
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
