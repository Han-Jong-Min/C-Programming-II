/* 파일명: PA8.18.c

  * 내용: 수학에서 집합은 다중집합과 다르게 원소의 중복을 허용하지 않는다. 정수형 배열과 배열의 크기
		  현재 들어있는 원소의 개수를 매개변수로 전달해서 원소를 추가하는 add_to_set 함수를 작성하시오.
		  add_to_set이 호출되고 나면 현재 들어있는 원소의 개수가 증가되어야 한다. 원소는 최대 배열의 
		  크기만큼만 추가할 수 있다. 더 이상 원소를 추가할 수 없거나 이미 같은 값의 원소가 있으면 0을
		  리턴하고, 원소를 추가하는 경우에는 1을 리턴한다. add_to_set 함수를 이용해서 입력받은 정수를
		  집합의 원소를 추가하고, 그 때마다 집합의 원소들을 출력하는 프로그램을 작성하시오.

  * 작성자: 한종민

  * 날짜: 2025.9.23.

  * 버전: v1.0

  */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 10 // 배열의 최대 크기

// 함수 원형 선언
void assignment15(void);
int add_to_set(int set[], int* count, int size, int value);
void print_set(int set[], int count);

int main()
{
    assignment15();
    return 0;
}

/*
 * 함수명: assignment15()
 * 기능: 집합 원소를 입력받아 추가하고, 매번 결과를 출력한다.
 */
void assignment15(void)
{
    int set[MAX_SIZE]; // 집합 배열
    int count = 0;     // 현재 원소 개수
    int value;         // 추가할 값
    int result;        // add_to_set 결과 저장용

    printf("음수를 입력하면 프로그램을 종료합니다.\n\n");

    while (1)
    {
        printf("배열에 추가할 원소? ");
        scanf("%d", &value);

        // 음수 입력 시 종료
        if (value < 0)
            break;

        // add_to_set 호출
        result = add_to_set(set, &count, MAX_SIZE, value);

        if (result == 1)
        {
            printf("\n");
        }
        else if (result == 0)
        {
            printf("해당 원소가 이미 존재합니다.\n");
        }

        // 현재 집합 출력
        print_set(set, count);
        printf("\n");
    }
}

/*
 * 함수명: add_to_set()
 * 기능: 정수형 배열에 중복되지 않은 값을 추가한다.
 * 매개변수:
 *   - int set[] : 집합 배열
 *   - int* count : 현재 원소 개수를 가리키는 포인터
 *   - int size : 배열의 최대 크기
 *   - int value : 추가할 값
 * 반환값:
 *   - 1 : 원소가 정상적으로 추가됨
 *   - 0 : 중복된 값이거나 배열이 가득 참
 */
int add_to_set(int set[], int* count, int size, int value)
{
    int i;

    // 1. 이미 존재하는 값인지 확인
    for (i = 0; i < *count; i++)
    {
        if (set[i] == value)
        {
            return 0; // 중복값
        }
    }

    // 2. 배열이 가득 찼는지 확인
    if (*count >= size)
    {
        return 0; // 공간 부족
    }

    // 3. 새 원소 추가
    set[*count] = value;
    (*count)++; // 원소 개수 증가

    return 1; // 성공
}

/*
 * 함수명: print_set()
 * 기능: 현재 집합의 원소들을 출력한다.
 */
void print_set(int set[], int count)
{
    int i;
    printf("현재 집합: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\n");
}