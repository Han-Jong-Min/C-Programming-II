/* 파일명: PA7.01.c

  * 내용: 등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.
		  크기가 10인 정수형 배열에 대하여 등차수열로 값을 채우려고 한다. 첫 번째 항의
		  값과 공차(common difference)를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오.

  * 작성자: 한종민

  * 날짜: 2025.09.16.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int assignment01(void);
void printArray(int arr[], int size);
void fillCD(int arr[], int size, int start, int diff);

int main()
{

	return assignment01();
}

#define ARR_SIZE 10

int assignment01(void)
{
	int result[10] = { 0 };

	int start = 0;
	int diff = 0;

	//입력
	printf("초기값 등차 입력하세요: ");
	scanf("%d %d", &start, &diff);
	//계산
	fillCD(result, 10, start, diff);
	//출력
	printArray(result, 10);

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
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*
  * 함수명: fillCD()
  * 기능: 첫 항과 공차를 이용하여 등차수열을 배열에 채운다.
  * 매개변수: int arr[] - 수열을 저장할 배열
			 int size - 배열 크기
			 int start - 등차수열의 첫 항
			 int diff - 공차
  * 반환값: 없음
*/
void fillCD(int arr[], int size, int start, int diff)
{
	int i;

	arr[0] = start;

	for (i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + diff;
	}

}