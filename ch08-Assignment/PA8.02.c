/* ���ϸ�: PA8.02.c

  * ����: �迭 ���Ҹ� ����Ű�� �����Ϳ� ������ ������ �̿��ؼ� �Ǽ��� �迭�� ��� ���Ҹ� ����ϴ� 
		  ���α׷��� �ۼ��Ͻÿ�. �Ǽ��� �迭�� ũ�Ⱑ 10�̰� ���� ������� �����ؼ� ����Ѵ�.

  * �ۼ���: ������

  * ��¥: 2025.9.23.

  * ����: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10 // �迭 ũ�⸦ ����� �����Ͽ� ���� ����

  // �Լ� ���� ����
void assignment02(void); 
void initializeDoubleArray(double arr[], int size);
void printArrayWithPointer(double arr[], int size);

int main()
{
	assignment02(); 
	return 0;
}

/*
 * �Լ���: assignment02()
 * ���: ���α׷��� ��ü �帧�� �����ϰ�, �迭�� ����� �Լ����� ȣ���Ѵ�.
 */
void assignment02(void)
{
	// 1. ũ�Ⱑ 10�� �Ǽ��� �迭 ����
	double numbers[ARRAY_SIZE];

	// 2. �迭�� ���� ���Ƿ� ����
	initializeDoubleArray(numbers, ARRAY_SIZE);

	// 3. �����Ϳ� ������ ������ �̿��� �迭 ���� ��� 
	printArrayWithPointer(numbers, ARRAY_SIZE);
}

/*
 * �Լ���: initializeDoubleArray()
 * ���: �־��� �Ǽ��� �迭�� ������ ������ ä���.
 * �Ű�����: double arr[] - �ʱ�ȭ�� �迭
 * int size - �迭 ũ��
 * ��ȯ��: ����
 */
void initializeDoubleArray(double arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		// ������ �Ǽ� ������ �ʱ�ȭ 
		arr[i] = (i + 1) * 1.1;
	}
}

/*
 * �Լ���: printArrayWithPointer()
 * ���: �����Ϳ� ������ ������ �̿��Ͽ� �Ǽ��� �迭�� ��� ���Ҹ� ����Ѵ�.
 * �Ű�����: double arr[] - ����� �迭
 * int size - �迭 ũ��
 * ��ȯ��: ����
 */
void printArrayWithPointer(double arr[], int size)
{
	// ������ ptr�� �迭�� ù ��° ���Ҹ� ����Ű���� �ʱ�ȭ
	double* ptr = arr;
	// �����Ͱ� �迭�� ������ ���� ������ ����ų ������ ������ ���� ���� �� �ּ�
	double* end = arr + size;

	// ptr�� end �����Ϳ� �����ϱ� ������ ������ �ݺ�
	for (; ptr < end; ptr++)
	{
		printf("%.2f  ", *ptr);
	}
	printf("\n"); 
}
