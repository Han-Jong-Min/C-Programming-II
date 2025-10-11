/* 파일명: PA8.02.c

  * 내용: 배열 원소를 가리키는 포인터와 포인터 연산을 이용해서 실수형 배열의 모든 원소를 출력하는 
		  프로그램을 작성하시오. 실수형 배열은 크기가 10이고 값은 마음대로 지정해서 사용한다.

  * 작성자: 한종민

  * 날짜: 2025.9.23.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10 // 배열 크기를 상수로 정의하여 관리 용이

  // 함수 원형 선언
void assignment02(void); 
void initializeDoubleArray(double arr[], int size);
void printArrayWithPointer(double arr[], int size);

int main()
{
	assignment02(); 
	return 0;
}

/*
 * 함수명: assignment02()
 * 기능: 프로그램의 전체 흐름을 제어하고, 배열을 만들고 함수들을 호출한다.
 */
void assignment02(void)
{
	// 1. 크기가 10인 실수형 배열 선언
	double numbers[ARRAY_SIZE];

	// 2. 배열의 값을 임의로 지정
	initializeDoubleArray(numbers, ARRAY_SIZE);

	// 3. 포인터와 포인터 연산을 이용해 배열 원소 출력 
	printArrayWithPointer(numbers, ARRAY_SIZE);
}

/*
 * 함수명: initializeDoubleArray()
 * 기능: 주어진 실수형 배열을 임의의 값으로 채운다.
 * 매개변수: double arr[] - 초기화할 배열
 * int size - 배열 크기
 * 반환값: 없음
 */
void initializeDoubleArray(double arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		// 임의의 실수 값으로 초기화 
		arr[i] = (i + 1) * 1.1;
	}
}

/*
 * 함수명: printArrayWithPointer()
 * 기능: 포인터와 포인터 연산을 이용하여 실수형 배열의 모든 원소를 출력한다.
 * 매개변수: double arr[] - 출력할 배열
 * int size - 배열 크기
 * 반환값: 없음
 */
void printArrayWithPointer(double arr[], int size)
{
	// 포인터 ptr이 배열의 첫 번째 원소를 가리키도록 초기화
	double* ptr = arr;
	// 포인터가 배열의 마지막 원소 다음을 가리킬 때까지 루프를 돌기 위한 끝 주소
	double* end = arr + size;

	// ptr이 end 포인터에 도달하기 전까지 루프를 반복
	for (; ptr < end; ptr++)
	{
		printf("%.2f  ", *ptr);
	}
	printf("\n"); 
}
