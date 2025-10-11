/* 파일명: PA8.13.c

  * 내용: 크기가 같은 2개의 정수형 배열을 매개변수로 전달받아 두 배열의 원소들의 값을 맞바꾸는
		  swap_array 함수를 작성하시오. swap_array 함수를 이용해서 크기가 10인 두 배열의 값을 맞바꾸는
		  프로그램을 작성하시오. 배열의 초기값은 마음대로 지정해서 사용한다.

  * 작성자: 한종민

  * 날짜: 2025.9.23.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10  // 배열 크기 상수 정의

  // 함수 원형 선언
void assignment13(void);
void initializeArray(int arr[], int size, int startValue);
void printArray(int arr[], int size);
void swap_array(int arr1[], int arr2[], int size);

/*
 * 함수명: main()
 * 기능: 프로그램의 시작점. assignment() 함수를 호출한다.
 */
int main(void)
{
    assignment13();
    return 0;
}

/*
 * 함수명: assignment13()
 * 기능: 두 배열을 생성하고 초기화, 교환 전/후 출력, swap_array() 호출을 담당한다.
 */
void assignment13(void)
{
    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];

    // 1. 배열 초기화 (서로 다른 값으로 설정)
    initializeArray(arr1, ARRAY_SIZE, 1);   // 1, 2, 3, ...
    initializeArray(arr2, ARRAY_SIZE, 100); // 100, 101, 102, ...

    // 2. 교환 전 배열 출력
    printf("교환 전 배열 상태:\n");
    printf("a: ");
    printArray(arr1, ARRAY_SIZE);
    printf("b: ");
    printArray(arr2, ARRAY_SIZE);

    // 3. 배열 교환
    swap_array(arr1, arr2, ARRAY_SIZE);

    // 4. 교환 후 배열 출력
    printf("\n교환 후 배열 상태:\n");
    printf("a: ");
    printArray(arr1, ARRAY_SIZE);
    printf("b: ");
    printArray(arr2, ARRAY_SIZE);
}

/*
 * 함수명: initializeArray()
 * 기능: 배열을 시작값부터 1씩 증가하는 값으로 초기화한다.
 * 매개변수: int arr[] - 초기화할 배열
 *           int size - 배열 크기
 *           int startValue - 초기 시작값
 * 반환값: 없음
 */
void initializeArray(int arr[], int size, int startValue)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = startValue + i;
    }
}

/*
 * 함수명: printArray()
 * 기능: 포인터를 이용해 배열의 모든 원소를 출력한다.
 * 매개변수: int arr[] - 출력할 배열
 *           int size - 배열 크기
 * 반환값: 없음
 */
void printArray(int arr[], int size)
{
    int* p = arr;           // 배열의 첫 번째 원소를 가리키는 포인터
    int* end = arr + size;  // 배열의 끝 주소

    while (p < end)
    {
        printf("%d  ", *p);
        p++;
    }
    printf("\n");
}

/*
 * 함수명: swap_array()
 * 기능: 두 배열의 원소 값을 맞바꾼다.
 * 매개변수: int arr1[] - 첫 번째 배열
 *           int arr2[] - 두 번째 배열
 *           int size - 배열 크기
 * 반환값: 없음
 */
void swap_array(int arr1[], int arr2[], int size)
{
    int* p1 = arr1;          // 첫 번째 배열 포인터
    int* p2 = arr2;          // 두 번째 배열 포인터
    int* end = arr1 + size;  // 배열의 끝 주소
    int temp;

    while (p1 < end)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;

        p1++;  // 다음 원소로 이동
        p2++;
    }
}

