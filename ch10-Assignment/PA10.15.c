/* ���ϸ�: PA10.15.c
 * ����: POINT ����ü �迭�� x��ǥ �������� ���� �����ϴ� ���α׷�.
 *       swap_point �Լ��� �̿��Ͽ� �� ���� ��ǥ�� �¹ٲ�.
 * �ۼ���: ������
 * �ۼ���: 2025.10.11
 * ����: v1.0
 */

#include <stdio.h>

#define POINT_COUNT 10

 // POINT ����ü ����
typedef struct
{
    int x;
    int y;
} POINT;

// �Լ� ���� ����
void assignment15(void);
void swap_point(POINT* p1, POINT* p2);
void print_points(POINT arr[], int size);

/*
 * �Լ���: main()
 * ���: assignment15 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment15();
    return 0;
}

/*
 * �Լ���: assignment15()
 * ���: POINT ����ü �迭 �ʱ�ȭ �� x��ǥ �������� ���� �����ϰ� ���
 */
void assignment15(void)
{
    // POINT �迭 �ʱ�ȭ (���� ��)
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

    printf("<<���� ��>>\n");
    print_points(points, POINT_COUNT);

    // x��ǥ ���� ���� ����
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

    printf("\n<<���� ��>>\n");
    print_points(points, POINT_COUNT);
}

/*
 * �Լ���: swap_point()
 * ���: �� POINT ����ü�� ��ǥ�� �¹ٲ�
 */
void swap_point(POINT* p1, POINT* p2)
{
    POINT temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/*
 * �Լ���: print_points()
 * ���: POINT �迭�� ��ǥ�� ���
 */
void print_points(POINT arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("(%d, %d)  ", arr[i].x, arr[i].y);
    }
    printf("\n");
}
