/* ���ϸ�: PA8.15.c

  * ����: 7���� ���� ���� �ڵ带 �̿��ؼ� ������ �迭�� �����ϴ� sort_array �Լ��� �����Ͻÿ�.
		  ũ�Ⱑ 10�� int �迭�� 0~99������ ������ ������ ä�� ���� sort_array �Լ��� ������ �����
		  ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  * �ۼ���: ������

  * ��¥: 2025.9.23.

  * ����: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   // rand(), srand() �Լ� ���
#include <time.h>     // time() �Լ� ���

#define ARRAY_SIZE 10 // �迭 ũ�� ��� ����

  // �Լ� ���� ����
void assignment15(void);
void initializeArray(int arr[], int size);
void printArray(int arr[], int size);
void sort_array(int arr[], int size);

int main()
{
    assignment15();
    return 0;
}

/*
 * �Լ���: assignment15()
 * ���: ��ü ���α׷��� �帧 ����
 */
void assignment15(void)
{
    int numbers[ARRAY_SIZE];

    // 1. �迭 �ʱ�ȭ (0~99 ������ ������)
    initializeArray(numbers, ARRAY_SIZE);

    // 2. ���� �� �迭 ���
    printf("���� �� �迭: ");
    printArray(numbers, ARRAY_SIZE);

    // 3. ���� ���ķ� �迭 ����
    sort_array(numbers, ARRAY_SIZE);

    // 4. ���� �� �迭 ���
    printf("���� �� �迭: ");
    printArray(numbers, ARRAY_SIZE);
}

/*
 * �Լ���: initializeArray()
 * ���: �迭�� 0~99 ������ ������ ������ �ʱ�ȭ
 */
void initializeArray(int arr[], int size)
{
    int i;
    srand((unsigned int)time(NULL)); // ���� �õ� ����

    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % 100; // 0~99 ������ ��
    }
}

/*
 * �Լ���: printArray()
 * ���: �迭�� ��� ���Ҹ� ���
 */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * �Լ���: sort_array()
 * ���: ���� ����(Selection Sort) �˰������� �迭�� �������� ����
 */
void sort_array(int arr[], int size)
{
    int i, j, min_index, temp;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // �� ���� ��ȯ
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
