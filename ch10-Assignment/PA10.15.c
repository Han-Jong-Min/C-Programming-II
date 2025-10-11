/* 파일명: PA10.15.c
 * 내용: POINT 구조체 배열을 x좌표 기준으로 선택 정렬하는 프로그램.
 *       swap_point 함수를 이용하여 두 점의 좌표를 맞바꿈.
 * 작성자: 한종민
 * 작성일: 2025.10.11
 * 버전: v1.0
 */

#include <stdio.h>

#define POINT_COUNT 10

 // POINT 구조체 정의
typedef struct
{
    int x;
    int y;
} POINT;

// 함수 원형 선언
void assignment15(void);
void swap_point(POINT* p1, POINT* p2);
void print_points(POINT arr[], int size);

/*
 * 함수명: main()
 * 기능: assignment15 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment15();
    return 0;
}

/*
 * 함수명: assignment15()
 * 기능: POINT 구조체 배열 초기화 후 x좌표 기준으로 선택 정렬하고 출력
 */
void assignment15(void)
{
    // POINT 배열 초기화 (임의 값)
    POINT points[POINT_COUNT] = {
        {7, 4},
        {12, 93},
        {22, 31},
        {1, 20},
        {34, 53},
        {41, 2},
        {32, 9},
        {21, 31},
        {8, 2},
        {3, 5}
    };

    printf("<<정렬 전>>\n");
    print_points(points, POINT_COUNT);

    // x좌표 기준 선택 정렬
    for (int i = 0; i < POINT_COUNT - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < POINT_COUNT; j++)
        {
            if (points[j].x < points[min_idx].x)
                min_idx = j;
        }
        if (min_idx != i)
            swap_point(&points[i], &points[min_idx]);
    }

    printf("\n<<정렬 후>>\n");
    print_points(points, POINT_COUNT);
}

/*
 * 함수명: swap_point()
 * 기능: 두 POINT 구조체의 좌표를 맞바꿈
 */
void swap_point(POINT* p1, POINT* p2)
{
    POINT temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/*
 * 함수명: print_points()
 * 기능: POINT 배열의 좌표를 출력
 */
void print_points(POINT arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("(%d, %d)  ", arr[i].x, arr[i].y);
    }
    printf("\n");
}
