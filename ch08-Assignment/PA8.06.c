/* ���ϸ�: PA8.06.c

  * ����: ������ �迭�� ���Ͽ� �迭�� ���� �� �ִ񰪰� �ּڰ��� ã�� get_min_max �Լ��� �����Ͻÿ�.
		  ũ�Ⱑ 10�� int �迭�� ���ؼ� ���ϴ� ������ �ʱⰪ�� ä�� ���� get_min_max �Լ��� �ִ񰪰�
		  �ּڰ��� ã�Ƽ� ����Ͻÿ�.

  * �ۼ���: ������

  * ��¥: 2025.9.23.

  * ����: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10  // �迭 ũ�⸦ ����� ����

  // �Լ� ���� ����
void assignment06(void);
void initializeArray(int arr[], int size);
void printArray(int arr[], int size);
void get_min_max(int arr[], int size, int* min, int* max);

/*
 * �Լ���: main()
 * ���: ���α׷��� ������. assignment() �Լ��� ȣ���Ѵ�.
 */
int main(void)
{
    assignment06();
    return 0;
}

/*
 * �Լ���: assignment06()
 * ���: �迭�� �����ϰ� �ʱ�ȭ, ��� �� get_min_max �Լ��� ȣ���Ͽ�
 *       �ִ񰪰� �ּڰ��� ����ϰ� ����� ����Ѵ�.
 */
void assignment06(void)
{
    int numbers[ARRAY_SIZE];
    int min, max;

    // 1. �迭 �ʱ�ȭ
    initializeArray(numbers, ARRAY_SIZE);

    // 2. �迭 ���
    printArray(numbers, ARRAY_SIZE);

    // 3. �ִ񰪰� �ּڰ� ���
    get_min_max(numbers, ARRAY_SIZE, &min, &max);

    // 4. ��� ���
    printf("\n�ּڰ�: %d\n", min);
    printf("�ִ�: %d\n", max);
}

/*
 * �Լ���: initializeArray()
 * ���: �迭�� ������ ���������� �ʱ�ȭ�Ѵ�.
 * �Ű�����: int arr[] - �ʱ�ȭ�� �迭
 *           int size - �迭 ũ��
 * ��ȯ��: ����
 */
void initializeArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 3; // ��: 3, 6, 9, 12, ..., 30
    }
}

/*
 * �Լ���: printArray()
 * ���: �迭�� ��� ���Ҹ� ����Ѵ�.
 * �Ű�����: int arr[] - ����� �迭
 *           int size - �迭 ũ��
 * ��ȯ��: ����
 */
void printArray(int arr[], int size)
{
    int* p = arr;           // �迭�� ù ��° ���Ҹ� ����Ű�� ������
    int* end = arr + size;  // �迭 �� �ּ�

    printf("�迭�� ��� ���� ���:\n");
    while (p < end)
    {
        printf("%d  ", *p);
        p++;
    }
    printf("\n");
}

/*
 * �Լ���: get_min_max()
 * ���: �����͸� �̿��Ͽ� �迭�� �ּڰ��� �ִ��� ã�´�.
 * �Ű�����: int arr[] - Ž���� �迭
 *           int size - �迭 ũ��
 *           int* min - �ּڰ��� ������ ������ �ּ�
 *           int* max - �ִ��� ������ ������ �ּ�
 * ��ȯ��: ����
 */
void get_min_max(int arr[], int size, int* min, int* max)
{
    int* p = arr;          // �迭�� ù ��° ���Ҹ� ����Ű�� ������
    int* end = arr + size; // �迭�� �� �ּ�

    *min = *p; // ù ��° ���ҷ� �ʱ�ȭ
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