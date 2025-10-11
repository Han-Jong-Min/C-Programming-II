/* ���ϸ�: PA10.06.c
 * ����: DATE ����ü�� is_same_date �Լ��� �̿��Ͽ� �Է� ��¥�� ���������� �˻��ϴ� ���α׷�.
 * �ۼ���: ������
 * �ۼ���: 2025.10.11
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
} DATE;

// �Լ� ���� ����
void assignment06(void);
int is_same_date(DATE d1, DATE d2);
void print_date(DATE date);

/*
 * �Լ���: main()
 * ���: assignment06 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment06();
    return 0;
}

/*
 * �Լ���: assignment06()
 * ���: �Է¹��� ��¥�� ���������� �˻�
 */
void assignment06(void)
{
    // ������ �迭 �ʱ�ȭ
    DATE holidays[] = {
        {2025, 1, 1},   // ����
        {2025, 3, 1},   // ������
        {2025, 5, 5},   // ��̳�
        {2025, 6, 6},   // ������
        {2025, 8, 15},  // ������
        {2025, 10, 3},  // ��õ��
        {2025, 12, 25}  // ��ź��
    };
    int holidayCount = sizeof(holidays) / sizeof(holidays[0]);

    DATE input;

    while (1)
    {
        // ����� �Է�
        printf("��¥ �Է� (�� �� ��, ����: 0 0 0): ");
        scanf("%d %d %d", &input.year, &input.month, &input.day);

        if (input.year == 0 && input.month == 0 && input.day == 0)
        {
            printf("���α׷� ����.\n");
            break;
        }

        int isHoliday = 0;
        for (int i = 0; i < holidayCount; i++)
        {
            if (is_same_date(input, holidays[i]))
            {
                isHoliday = 1;
                break;
            }
        }

        if (isHoliday)
        {
            print_date(input);
            printf("�� �������Դϴ�.\n");
        }
        else
        {
            print_date(input);
            printf("�� �������� �ƴմϴ�.\n");
        }
    }
}

/*
 * �Լ���: is_same_date()
 * ���: �� DATE ����ü�� ���� ��¥���� ��
 * ��ȯ��: ������ 1, �ٸ��� 0
 */
int is_same_date(DATE d1, DATE d2)
{
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}

/*
 * �Լ���: print_date()
 * ���: DATE ����ü�� "YYYY/M/D" �������� ���
 */
void print_date(DATE date)
{
    printf("%d/%d/%d", date.year, date.month, date.day);
}
