/*
	이름: 한종민 
	학번: 202111604
	프로그램명: ch07-02.c
	날짜: 2025-09
*/

#include <stdio.h>

void* swapDouble(double* pa, double* pb); // 전방선언
int test_print_array();
int test_swapDouble();

int main()
{

    //test_swapDouble();
    test_print_array();

    return 0;
}

int test_swapDouble()
{
    double a = 3.14;
    double b = 5.12;

    double* presult = (double*)swapDouble(&a, &b);
    if (presult == NULL)
    {
        printf("뭔가 잘못되었어!!\n");
    }
    else
    {
        printf("a = %f, b = %f\n", a, b);
    }

    presult = (double*)swapDouble((double*)NULL, &b);
    if (presult == NULL)
    {
        printf("뭔가 잘못되었어!!\n");
    }
    else
    {
        printf("a = %f, b = %f\n", a, b);
    }
}
void* swapDouble(double* pa, double* pb)
{
    // 1. 입력 값 정상인지 체크 : NULL이 아니어야 함 !!
    if (pa == NULL || pb == NULL)
    {
        return NULL;
    }

    // 2. swap two values
    double tmp = *pa;
    *pa = *pb;
    *pb = tmp;

    return pa;
}

void print_array_double(double arr[], int sz);
void printArrayDouble(double* arr, int sz);

int test_print_array()
{
    double da[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    int size = sizeof(da) / sizeof(da[0]);

    print_array_double(da, size);

    printArrayDouble(&da[0], size);
    return 0;
}



// 기능: 1차원 실수 배열을 입력 받아 콘솔에 출력한다.
// 함수명: printf_array_double
// 입력: double 타입 1차원 배열 주소
// 출력: 터미널에 배열의 내용을 예쁘게 출력
// 반환: X

void print_array_double(double arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%lf", arr[i]);
    }
    printf("\n");
}

void printArrayDouble(double* arr, int sz)
{
    for (int i = 0; i < sz; i++, arr++)
    {
        printf("%lf", *arr);
    }
    printf("\n");
}