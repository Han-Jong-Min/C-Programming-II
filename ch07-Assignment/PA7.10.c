/* 파일명: PA7.10.c

  * 내용: 3X3 행렬의 합을 구하는 프로그램을 작성하시오. 행렬로 사용될 2차원 배열은
         마음대로 초기화해도 된다.
  * 작성자: 한종민

  * 날짜: 2025.09.17.

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int assignment10(void);
void printMatrix(int matrix[3][3]);
void addMatrix(int x[3][3], int y[3][3], int result[3][3]);

int main()
{
    return assignment10();
}

int assignment10(void)
{
    // 두 행렬 초기화
    int x[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int y[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int sum[3][3] = { 0 };

    // 행렬 덧셈 수행
    addMatrix(x, y, sum);

    // 출력
    printf("x 행렬:\n");
    printMatrix(x);

    printf("\ny 행렬:\n");
    printMatrix(y);

    printf("\nx+y 행렬:\n");
    printMatrix(sum);

    return 0;
}

/*
  * 함수명: printMatrix()
  * 기능: 3x3 행렬을 보기 좋게 출력한다.
  * 매개변수: int matrix[3][3] - 출력할 행렬
  * 반환값: 없음
*/
void printMatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
  * 함수명: addMatrix()
  * 기능: 두 행렬의 합을 계산하여 result에 저장한다.
  * 매개변수:
  *    int x[3][3] - 첫 번째 행렬
  *    int y[3][3] - 두 번째 행렬
  *    int result[3][3] - 결과 행렬 저장용
  * 반환값: 없음
*/
void addMatrix(int x[3][3], int y[3][3], int result[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = x[i][j] + y[i][j];
        }
    }
}