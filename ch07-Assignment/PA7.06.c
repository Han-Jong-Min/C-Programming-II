/* 파일명: PA7.06.c

  * 내용: 크기가 10인 실수형 배열에 대해서 원소들을 역순으로 만드는 프로그램을 작성하시오.
          실수형 배열의 초기값은 마음대로 정하시오.

  * 작성자: 한종민

  * 날짜: 2025.09.16.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int assignment06(void);
void printArray(double arr[], int size);
void reverseArray(double arr[], int size);

int main()
{
    return assignment06();
}

#define ARR_SIZE 10

int assignment06(void)
{
    // 초기값은 임의로 설정
    double data[ARR_SIZE] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };

    printf("배열: ");
    printArray(data, ARR_SIZE);

    reverseArray(data, ARR_SIZE);

    printf("역순: ");
    printArray(data, ARR_SIZE);

    return 0;
}

/*
  * 함수명: printArray()
  * 기능: 배열의 실수 값을 출력한다.
  * 매개변수: double arr[] - 출력할 배열, int size - 배열 크기
  * 반환값: 없음
*/
void printArray(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

/*
  * 함수명: reverseArray()
  * 기능: 배열의 원소들을 역순으로 바꾼다.
  * 매개변수: double arr[] - 대상 배열, int size - 배열 크기
  * 반환값: 없음
*/
void reverseArray(double arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        double temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}