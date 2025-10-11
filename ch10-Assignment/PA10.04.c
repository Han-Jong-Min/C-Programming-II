/* ���ϸ�: PA10.04.c
 * ����: DATE ����ü�� print_date �Լ��� �̿��Ͽ� ��¥�� ����ϴ� ���α׷�.
 * �ۼ���: ������
 * �ۼ���: 2025.10.11
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // DATE ����ü ����
typedef struct
{
    int year;
    int month;
    int day;
} DATE;

// �Լ� ���� ����
void assignment04(void);
void print_date(DATE date);

/*
 * �Լ���: main()
 * ���: assignment04 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment04();
    return 0;
}

/*
 * �Լ���: assignment04()
 * ���: ����ڷκ��� ��¥ �Է��� �ް� DATE ����ü�� ���� �� ���
 */
void assignment04(void)
{
    DATE today;

    // ��¥ �Է�
    printf("��: ");
    scanf("%d", &today.year);
    printf("��: ");
    scanf("%d", &today.month);
    printf("��: ");
    scanf("%d", &today.day);

    // ���
    print_date(today);
}

/*
 * �Լ���: print_date()
 * ���: DATE ����ü�� �޾� "YYYY/M/D" �������� ���
 */
void print_date(DATE date)
{
    printf("%d/%d/%d\n", date.year, date.month, date.day);
}
