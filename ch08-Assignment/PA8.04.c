/* 파일명: PA8.04.c

  * 내용: 배열 원소를 가리키는 포인터를 이용해서 실수형 배열의 평균을 구하는 프로그램을 작성하시오
		  실수형 배열은 크기가 10이고 값은 마음대로 초기화해서 사용한다.

  * 작성자: 한종민

  * 날짜: 2025.9.23.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10  // 배열 크기를 상수로 정의

  // 함수 원형 선언
void assignment04(void);
void initializeArray(double arr[], int size);
void printArray(double arr[], int size);
double calculateAverage(double arr[], int size);

/*
 * 함수명: main()
 * 기능: 프로그램의 시작점. assignment04() 함수를 호출한다.
 */
int main(void)
{
    assignment04();
    return 0;
}

/*
 * 함수명: assignment04()
 * 기능: 배열을 생성하고 초기화, 출력 및 평균 계산을 수행한다.
 */
void assignment04(void)
{
    double numbers[ARRAY_SIZE];
    double avg;

    // 1. 배열 초기화
    initializeArray(numbers, ARRAY_SIZE);

    // 2. 배열 출력
    printArray(numbers, ARRAY_SIZE);

    // 3. 평균 계산
    avg = calculateAverage(numbers, ARRAY_SIZE);

    // 4. 결과 출력
    printf("\n평균: %.2f\n", avg);
}

/*
 * 함수명: initializeArray()
 * 기능: 배열을 임의의 실수값으로 초기화한다.
 * 매개변수: double arr[] - 초기화할 배열
 *           int size - 배열 크기
 * 반환값: 없음
 */
void initializeArray(double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 1.3; // 예: 1.3, 2.6, 3.9, ..., 13.0
    }
}

/*
 * 함수명: printArray()
 * 기능: 포인터를 이용하여 배열의 모든 원소를 출력한다.
 * 매개변수: double arr[] - 출력할 배열
 *           int size - 배열 크기
 * 반환값: 없음
 */
void printArray(double arr[], int size)
{
    double* p = arr;          // 배열의 첫 번째 원소를 가리키는 포인터
    double* end = arr + size; // 배열 끝(마지막 원소 다음)을 가리키는 포인터

    printf("배열:\n");
    while (p < end)
    {
        printf("%.2f  ", *p); // 포인터 역참조로 값 출력
        p++;                  // 다음 원소로 이동
    }
    printf("\n");
}

/*
 * 함수명: calculateAverage()
 * 기능: 포인터를 이용하여 배열의 모든 원소의 평균을 계산한다.
 * 매개변수: double arr[] - 평균을 구할 배열
 *           int size - 배열 크기
 * 반환값: double - 배열 원소들의 평균
 */
double calculateAverage(double arr[], int size)
{
    double* p = arr;          // 배열의 첫 번째 원소를 가리키는 포인터
    double* end = arr + size; // 배열의 끝 주소
    double sum = 0.0;

    while (p < end)
    {
        sum += *p; // 포인터가 가리키는 값을 더함
        p++;       // 다음 원소로 이동
    }

    return sum / size; // 평균 계산
}