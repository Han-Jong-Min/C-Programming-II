/* ���ϸ�: PA9.03.c
 * ����: �Է¹��� ���ڿ��� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ��ȯ�ϴ� ���α׷�.
 *      
 * �ۼ���: ������
 * ��¥: 2025.10.10
 * ����: v1.1
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // �Լ� ���� ����
void assignment03(void);
void convert_case(char* str);

int main()
{
    assignment03();
    return 0;
}

/*
 * �Լ���: assignment03()
 * ���: ���ڿ��� �Է¹޾� ��ҹ��ڸ� ��ȯ�ϰ� ����� ����Ѵ�.
 */
void assignment03(void)
{
    char str[200];

    printf("���ڿ�? ");
    fgets(str, sizeof(str), stdin); // ���� ���� �Է� �ޱ�

    // ��ҹ��� ��ȯ
    convert_case(str);

    // ��� ���
    printf("��ȯ ��: %s", str);
}

/*
 * �Լ���: convert_case()
 * ���: �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ��ȯ�Ѵ�.
 */

void convert_case(char* str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        // 'A'(65) ~ 'Z'(90): �빮��
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A'); // 32 ���ϱ� �� �ҹ��� ��ȯ
        }
        // 'a'(97) ~ 'z'(122): �ҹ���
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A'); // 32 ���� �� �빮�� ��ȯ
        }
    }
}
