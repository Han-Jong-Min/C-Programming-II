/* ���ϸ�: PA8.18.c

  * ����: ���п��� ������ �������հ� �ٸ��� ������ �ߺ��� ������� �ʴ´�. ������ �迭�� �迭�� ũ��
		  ���� ����ִ� ������ ������ �Ű������� �����ؼ� ���Ҹ� �߰��ϴ� add_to_set �Լ��� �ۼ��Ͻÿ�.
		  add_to_set�� ȣ��ǰ� ���� ���� ����ִ� ������ ������ �����Ǿ�� �Ѵ�. ���Ҵ� �ִ� �迭�� 
		  ũ�⸸ŭ�� �߰��� �� �ִ�. �� �̻� ���Ҹ� �߰��� �� ���ų� �̹� ���� ���� ���Ұ� ������ 0��
		  �����ϰ�, ���Ҹ� �߰��ϴ� ��쿡�� 1�� �����Ѵ�. add_to_set �Լ��� �̿��ؼ� �Է¹��� ������
		  ������ ���Ҹ� �߰��ϰ�, �� ������ ������ ���ҵ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  * �ۼ���: ������

  * ��¥: 2025.9.23.

  * ����: v1.0

  */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 10 // �迭�� �ִ� ũ��

// �Լ� ���� ����
void assignment15(void);
int add_to_set(int set[], int* count, int size, int value);
void print_set(int set[], int count);

int main()
{
    assignment15();
    return 0;
}

/*
 * �Լ���: assignment15()
 * ���: ���� ���Ҹ� �Է¹޾� �߰��ϰ�, �Ź� ����� ����Ѵ�.
 */
void assignment15(void)
{
    int set[MAX_SIZE]; // ���� �迭
    int count = 0;     // ���� ���� ����
    int value;         // �߰��� ��
    int result;        // add_to_set ��� �����

    printf("������ �Է��ϸ� ���α׷��� �����մϴ�.\n\n");

    while (1)
    {
        printf("�迭�� �߰��� ����? ");
        scanf("%d", &value);

        // ���� �Է� �� ����
        if (value < 0)
            break;

        // add_to_set ȣ��
        result = add_to_set(set, &count, MAX_SIZE, value);

        if (result == 1)
        {
            printf("\n");
        }
        else if (result == 0)
        {
            printf("�ش� ���Ұ� �̹� �����մϴ�.\n");
        }

        // ���� ���� ���
        print_set(set, count);
        printf("\n");
    }
}

/*
 * �Լ���: add_to_set()
 * ���: ������ �迭�� �ߺ����� ���� ���� �߰��Ѵ�.
 * �Ű�����:
 *   - int set[] : ���� �迭
 *   - int* count : ���� ���� ������ ����Ű�� ������
 *   - int size : �迭�� �ִ� ũ��
 *   - int value : �߰��� ��
 * ��ȯ��:
 *   - 1 : ���Ұ� ���������� �߰���
 *   - 0 : �ߺ��� ���̰ų� �迭�� ���� ��
 */
int add_to_set(int set[], int* count, int size, int value)
{
    int i;

    // 1. �̹� �����ϴ� ������ Ȯ��
    for (i = 0; i < *count; i++)
    {
        if (set[i] == value)
        {
            return 0; // �ߺ���
        }
    }

    // 2. �迭�� ���� á���� Ȯ��
    if (*count >= size)
    {
        return 0; // ���� ����
    }

    // 3. �� ���� �߰�
    set[*count] = value;
    (*count)++; // ���� ���� ����

    return 1; // ����
}

/*
 * �Լ���: print_set()
 * ���: ���� ������ ���ҵ��� ����Ѵ�.
 */
void print_set(int set[], int count)
{
    int i;
    printf("���� ����: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\n");
}