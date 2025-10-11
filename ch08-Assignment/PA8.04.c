/* ���ϸ�: PA8.04.c

  * ����: �迭 ���Ҹ� ����Ű�� �����͸� �̿��ؼ� �Ǽ��� �迭�� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�
		  �Ǽ��� �迭�� ũ�Ⱑ 10�̰� ���� ������� �ʱ�ȭ�ؼ� ����Ѵ�.

  * �ۼ���: ������

  * ��¥: 2025.9.23.

  * ����: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10  // �迭 ũ�⸦ ����� ����

  // �Լ� ���� ����
void assignment04(void);
void initializeArray(double arr[], int size);
void printArray(double arr[], int size);
double calculateAverage(double arr[], int size);

/*
 * �Լ���: main()
 * ���: ���α׷��� ������. assignment04() �Լ��� ȣ���Ѵ�.
 */
int main(void)
{
    assignment04();
    return 0;
}

/*
 * �Լ���: assignment04()
 * ���: �迭�� �����ϰ� �ʱ�ȭ, ��� �� ��� ����� �����Ѵ�.
 */
void assignment04(void)
{
    double numbers[ARRAY_SIZE];
    double avg;

    // 1. �迭 �ʱ�ȭ
    initializeArray(numbers, ARRAY_SIZE);

    // 2. �迭 ���
    printArray(numbers, ARRAY_SIZE);

    // 3. ��� ���
    avg = calculateAverage(numbers, ARRAY_SIZE);

    // 4. ��� ���
    printf("\n���: %.2f\n", avg);
}

/*
 * �Լ���: initializeArray()
 * ���: �迭�� ������ �Ǽ������� �ʱ�ȭ�Ѵ�.
 * �Ű�����: double arr[] - �ʱ�ȭ�� �迭
 *           int size - �迭 ũ��
 * ��ȯ��: ����
 */
void initializeArray(double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 1.3; // ��: 1.3, 2.6, 3.9, ..., 13.0
    }
}

/*
 * �Լ���: printArray()
 * ���: �����͸� �̿��Ͽ� �迭�� ��� ���Ҹ� ����Ѵ�.
 * �Ű�����: double arr[] - ����� �迭
 *           int size - �迭 ũ��
 * ��ȯ��: ����
 */
void printArray(double arr[], int size)
{
    double* p = arr;          // �迭�� ù ��° ���Ҹ� ����Ű�� ������
    double* end = arr + size; // �迭 ��(������ ���� ����)�� ����Ű�� ������

    printf("�迭:\n");
    while (p < end)
    {
        printf("%.2f  ", *p); // ������ �������� �� ���
        p++;                  // ���� ���ҷ� �̵�
    }
    printf("\n");
}

/*
 * �Լ���: calculateAverage()
 * ���: �����͸� �̿��Ͽ� �迭�� ��� ������ ����� ����Ѵ�.
 * �Ű�����: double arr[] - ����� ���� �迭
 *           int size - �迭 ũ��
 * ��ȯ��: double - �迭 ���ҵ��� ���
 */
double calculateAverage(double arr[], int size)
{
    double* p = arr;          // �迭�� ù ��° ���Ҹ� ����Ű�� ������
    double* end = arr + size; // �迭�� �� �ּ�
    double sum = 0.0;

    while (p < end)
    {
        sum += *p; // �����Ͱ� ����Ű�� ���� ����
        p++;       // ���� ���ҷ� �̵�
    }

    return sum / size; // ��� ���
}