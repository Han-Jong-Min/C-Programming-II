/* ���ϸ�: PA9.01.c
 * ����: �� ���� ���ڿ��� �Է¹޾Ƽ� ���� ����(' ', '\n', '\t', '\f', '\r', '\v')�� ������ ���� ���α׷�.
 *
 * �ۼ���: ������
 * ��¥: 2025.10.10
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // �Լ� ���� ����
void assignment01(void);
int count_whitespace(const char* str);

int main()
{
    assignment01();
    return 0;
}

/*
 * �Լ���: assignment01()
 * ���: ����ڷκ��� ���ڿ��� �Է¹ް�, ���� ������ ������ ���� ����Ѵ�.
 */
void assignment01(void)
{
    char str[200]; // �Է� ���ڿ� ����� (�ִ� 199�� + NULL)
    int count;

    printf("���ڿ�? ");
    fgets(str, sizeof(str), stdin); // ���� ���� �Է� �ޱ�

    // ���� ���� ���� ���
    count = count_whitespace(str);

    printf("���� ������ ����: %d\n", count);
}

/*
 * �Լ���: count_whitespace()
 * ���: �־��� ���ڿ� ���� ���� ����(' ', '\n', '\t', '\f', '\r', '\v') ������ ����.
 * �Ű�����: const char* str - �˻��� ���ڿ�
 * ��ȯ��: int - ���� ������ ����
 */
int count_whitespace(const char* str)
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case ' ':
        case '\n':
        case '\t':
        case '\f':
        case '\r':
        case '\v':
            count++;
            break;
        }
    }

    return count;
}
