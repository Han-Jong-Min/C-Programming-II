/* ���ϸ�: PA9.05.c
 * ����: ��ҹ��ڸ� �������� �ʰ� ���ڿ��� ���ϴ� strcmp_ic �Լ��� �ۼ��Ͻÿ�. strcmp_ic(lhs, rhs) �Լ��� ���ϰ��� strcmp�� ����������
         lhs�� rhs���� ũ�� 0���� ū ��, �� ���ڿ��� ������ 0, lhs�� rhs���� ������ 0���� ���� ���� �����Ѵ�. strcmp_ic �Լ��� �̿��ؼ� 
         �Է¹��� �� ���ڿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 * �ۼ���: ������
 * �ۼ���: 2025.10.10
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // �Լ� ���� ����
void assignment05(void);
int strcmp_ic(const char* lhs, const char* rhs);
void removeNewline(char* str);

/*
 * �Լ���: main()
 * ���: assignment05 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment05();
    return 0;
}

/*
 * �Լ���: assignment05()
 * ���: ���ڿ��� �Է¹ް� strcmp_ic �Լ��� �̿��Ͽ� �� ���ڿ��� ���Ѵ�.
 */
void assignment05(void)
{
    char str1[100], str2[100];
    int result;

    printf("ù ��° ���ڿ�: ");
    fgets(str1, sizeof(str1), stdin);
    printf("�� ��° ���ڿ�: ");
    fgets(str2, sizeof(str2), stdin);

    // fgets�� �Էµ� ���ڿ��� ���� ���� ����
    removeNewline(str1);
    removeNewline(str2);

    // ��ҹ��� ���� ���� ���ڿ� ��
    result = strcmp_ic(str1, str2);

    if (result == 0)
        printf("\"%s\"�� \"%s\"�� �����ϴ�.\n", str1, str2);
    else if (result > 0)
        printf("\"%s\" > \"%s\"\n", str1, str2);
    else
        printf("\"%s\" < \"%s\"\n", str1, str2);
}

/*
 * �Լ���: strcmp_ic()
 * ���: �� ���ڿ��� ��ҹ��� ���� ���� ���Ѵ�.
 * �Ű�����: const char* lhs - ù ��° ���ڿ�
 *           const char* rhs - �� ��° ���ڿ�
 * ��ȯ��: lhs > rhs �� ���, lhs == rhs �� 0, lhs < rhs �� ����
 */
int strcmp_ic(const char* lhs, const char* rhs)
{
    while (*lhs && *rhs)
    {
        char c1 = *lhs;
        char c2 = *rhs;

        // �ҹ��ڸ� �빮�ڷ� ��ȯ (ctype.h ������� ����)
        if (c1 >= 'a' && c1 <= 'z')
            c1 = c1 - 'a' + 'A';
        if (c2 >= 'a' && c2 <= 'z')
            c2 = c2 - 'a' + 'A';

        if (c1 != c2)
            return (unsigned char)c1 - (unsigned char)c2;

        lhs++;
        rhs++;
    }

    // ���ڿ��� ���̰� �ٸ� ��� ���� ��ȯ
    return (unsigned char)*lhs - (unsigned char)*rhs;
}

/*
 * �Լ���: removeNewline()
 * ���: fgets�� �Է¹��� ���ڿ��� ���� ���� ���� ���ڸ� �����Ѵ�.
 * �Ű�����: char* str - ó���� ���ڿ�
 * ��ȯ��: ����
 */
void removeNewline(char* str)
{
    int i;
    for (i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
