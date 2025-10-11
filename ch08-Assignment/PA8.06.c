/* 파일명: PA8.06.c

  * 내용: 정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾는 get_min_max 함수를 정의하시오.
		  크기가 10인 int 배열에 대해서 원하는 값으로 초기값을 채운 다음 get_min_max 함수로 최댓값과
		  최솟값을 찾아서 출력하시오.

  * 작성자: 한종민

  * 날짜: 2025.9.23.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10  // 배열 크기를 상수로 정의

  // 함수 원형 선언
void assignment06(void);
void initializeArray(int arr[], int size);
void printArray(int arr[], int size);
void get_min_max(int arr[], int size, int* min, int* max);

/*
 * 함수명: main()
 * 기능: 프로그램의 시작점. assignment() 함수를 호출한다.
 */
int main(void)
{
    assignment06();
    return 0;
}

/*
 * 함수명: assignment06()
 * 기능: 배열을 생성하고 초기화, 출력 후 get_min_max 함수를 호출하여
 *       최댓값과 최솟값을 계산하고 결과를 출력한다.
 */
void assignment06(void)
{
    int numbers[ARRAY_SIZE];
    int min, max;

    // 1. 배열 초기화
    initializeArray(numbers, ARRAY_SIZE);

    // 2. 배열 출력
    printArray(numbers, ARRAY_SIZE);

    // 3. 최댓값과 최솟값 계산
    get_min_max(numbers, ARRAY_SIZE, &min, &max);

    // 4. 결과 출력
    printf("\n최솟값: %d\n", min);
    printf("최댓값: %d\n", max);
}

/*
 * 함수명: initializeArray()
 * 기능: 배열을 임의의 정수값으로 초기화한다.
 * 매개변수: int arr[] - 초기화할 배열
 *           int size - 배열 크기
 * 반환값: 없음
 */
void initializeArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 3; // 예: 3, 6, 9, 12, ..., 30
    }
}

/*
 * 함수명: printArray()
 * 기능: 배열의 모든 원소를 출력한다.
 * 매개변수: int arr[] - 출력할 배열
 *           int size - 배열 크기
 * 반환값: 없음
 */
void printArray(int arr[], int size)
{
    int* p = arr;           // 배열의 첫 번째 원소를 가리키는 포인터
    int* end = arr + size;  // 배열 끝 주소

    printf("배열의 모든 원소 출력:\n");
    while (p < end)
    {
        printf("%d  ", *p);
        p++;
    }
    printf("\n");
}

/*
 * 함수명: get_min_max()
 * 기능: 포인터를 이용하여 배열의 최솟값과 최댓값을 찾는다.
 * 매개변수: int arr[] - 탐색할 배열
 *           int size - 배열 크기
 *           int* min - 최솟값을 저장할 변수의 주소
 *           int* max - 최댓값을 저장할 변수의 주소
 * 반환값: 없음
 */
void get_min_max(int arr[], int size, int* min, int* max)
{
    int* p = arr;          // 배열의 첫 번째 원소를 가리키는 포인터
    int* end = arr + size; // 배열의 끝 주소

    *min = *p; // 첫 번째 원소로 초기화
    *max = *p;

    while (p < end)
    {
        if (*p < *min)
            *min = *p;
        if (*p > *max)
            *max = *p;
        p++;
    }
}