/* 파일명: PA7.04.c

  * 내용: 특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값을 가진 원소와
          최솟값을 가진 원소를 찾아서 인덱스와 값을 함께 출력하는 프로그램을 작성하시오.
          배열의 초기값은 마음대로 정하시오.

  * 작성자: 한종민

  * 날짜: 2025.09.16.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int assignment04(void);
void printArray(int arr[], int size);
void findMinMax(int arr[], int size, int* minIndex, int* maxIndex);

int main()
{
    return assignment04();
}

#define ARR_SIZE 10

int assignment04(void)
{
    // 배열 초기화 (원하는 값으로)
    int data[ARR_SIZE] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };

    int minIdx = 0;
    int maxIdx = 0;

    // 배열 출력
    printArray(data, ARR_SIZE);

    // 최솟값과 최댓값 인덱스 찾기
    findMinMax(data, ARR_SIZE, &minIdx, &maxIdx);

    // 결과 출력
    printf("최댓값: 인덱스 = %d, 값 = %d\n", maxIdx, data[maxIdx]);
    printf("최솟값: 인덱스 = %d, 값 = %d\n", minIdx, data[minIdx]);

    return 0;
}

/*
  * 함수명: printArray()
  * 기능: 주어진 배열의 요소를 출력한다.
  * 매개변수: int arr[] - 출력할 배열, int size - 배열 크기
  * 반환값: 없음
*/
void printArray(int arr[], int size)
{
    printf("배열: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
  * 함수명: findMinMax()
  * 기능: 배열 내 최솟값과 최댓값을 찾아 그 인덱스를 반환한다.
  * 매개변수:
  *    int arr[] - 대상 배열
  *    int size - 배열 크기
  *    int* minIndex - 최솟값의 인덱스를 저장할 포인터
  *    int* maxIndex - 최댓값의 인덱스를 저장할 포인터
  * 반환값: 없음
*/
void findMinMax(int arr[], int size, int* minIndex, int* maxIndex)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[*minIndex])
            *minIndex = i;
        if (arr[i] > arr[*maxIndex])
            *maxIndex = i;
    }
}