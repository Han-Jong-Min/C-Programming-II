/* ���ϸ�: PA8.13.c

  * ����: ũ�Ⱑ ���� 2���� ������ �迭�� �Ű������� ���޹޾� �� �迭�� ���ҵ��� ���� �¹ٲٴ�
		  swap_array �Լ��� �ۼ��Ͻÿ�. swap_array �Լ��� �̿��ؼ� ũ�Ⱑ 10�� �� �迭�� ���� �¹ٲٴ�
		  ���α׷��� �ۼ��Ͻÿ�. �迭�� �ʱⰪ�� ������� �����ؼ� ����Ѵ�.

  * �ۼ���: ������

  * ��¥: 2025.9.23.

  * ����: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10  // �迭 ũ�� ��� ����

  // �Լ� ���� ����
void assignment13(void);
void initializeArray(int arr[], int size, int startValue);
void printArray(int arr[], int size);
void swap_array(int arr1[], int arr2[], int size);

/*
 * �Լ���: main()
 * ���: ���α׷��� ������. assignment() �Լ��� ȣ���Ѵ�.
 */
int main(void)
{
    assignment13();
    return 0;
}

/*
 * �Լ���: assignment13()
 * ���: �� �迭�� �����ϰ� �ʱ�ȭ, ��ȯ ��/�� ���, swap_array() ȣ���� ����Ѵ�.
 */
void assignment13(void)
{
    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];

    // 1. �迭 �ʱ�ȭ (���� �ٸ� ������ ����)
    initializeArray(arr1, ARRAY_SIZE, 1);   // 1, 2, 3, ...
    initializeArray(arr2, ARRAY_SIZE, 100); // 100, 101, 102, ...

    // 2. ��ȯ �� �迭 ���
    printf("��ȯ �� �迭 ����:\n");
    printf("a: ");
    printArray(arr1, ARRAY_SIZE);
    printf("b: ");
    printArray(arr2, ARRAY_SIZE);

    // 3. �迭 ��ȯ
    swap_array(arr1, arr2, ARRAY_SIZE);

    // 4. ��ȯ �� �迭 ���
    printf("\n��ȯ �� �迭 ����:\n");
    printf("a: ");
    printArray(arr1, ARRAY_SIZE);
    printf("b: ");
    printArray(arr2, ARRAY_SIZE);
}

/*
 * �Լ���: initializeArray()
 * ���: �迭�� ���۰����� 1�� �����ϴ� ������ �ʱ�ȭ�Ѵ�.
 * �Ű�����: int arr[] - �ʱ�ȭ�� �迭
 *           int size - �迭 ũ��
 *           int startValue - �ʱ� ���۰�
 * ��ȯ��: ����
 */
void initializeArray(int arr[], int size, int startValue)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = startValue + i;
    }
}

/*
 * �Լ���: printArray()
 * ���: �����͸� �̿��� �迭�� ��� ���Ҹ� ����Ѵ�.
 * �Ű�����: int arr[] - ����� �迭
 *           int size - �迭 ũ��
 * ��ȯ��: ����
 */
void printArray(int arr[], int size)
{
    int* p = arr;           // �迭�� ù ��° ���Ҹ� ����Ű�� ������
    int* end = arr + size;  // �迭�� �� �ּ�

    while (p < end)
    {
        printf("%d  ", *p);
        p++;
    }
    printf("\n");
}

/*
 * �Լ���: swap_array()
 * ���: �� �迭�� ���� ���� �¹ٲ۴�.
 * �Ű�����: int arr1[] - ù ��° �迭
 *           int arr2[] - �� ��° �迭
 *           int size - �迭 ũ��
 * ��ȯ��: ����
 */
void swap_array(int arr1[], int arr2[], int size)
{
    int* p1 = arr1;          // ù ��° �迭 ������
    int* p2 = arr2;          // �� ��° �迭 ������
    int* end = arr1 + size;  // �迭�� �� �ּ�
    int temp;

    while (p1 < end)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;

        p1++;  // ���� ���ҷ� �̵�
        p2++;
    }
}

