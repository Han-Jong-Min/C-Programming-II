/* ���ϸ�: PA9.12.c
 * ����: �Է¹��� ���ڿ��� ���� �̵��� ���� ���� �Է¹޾�
 *       ���� �Ǵ� ���������� ȸ��(rotate)�� ����� ����ϴ� ���α׷�.
 *       �̵��� ���� ���� ������ ����, ����� ���������� �̵�.
 *       �̵��� ���� ���� 0�̸� ���α׷� ����.
 * �ۼ���: ������
 * �ۼ���: 2025.10.10
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

 // �Լ� ���� ����
void assignment12(void);
void rotateString(char* str, int n);
void removeNewline(char* str);

/*
 * �Լ���: main()
 * ���: assignment12 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment12();
    return 0;
}

/*
 * �Լ���: assignment12()
 * ���: ���ڿ��� �̵� ���� ���� �Է¹޾� ȸ�� ����� ����Ѵ�.
 */
void assignment12(void)
{
    char str[100];
    int move;

    while (1)
    {
        printf("\n���ڿ�? ");
        fgets(str, sizeof(str), stdin);
        removeNewline(str);

        printf("�̵��� ���� ��? (0 �Է� �� ����) ");
        scanf("%d", &move);
        getchar(); // ���� ���� ���� ����

        if (move == 0)
        {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        rotateString(str, move);
        printf("%s\n", str);
    }
}

/*
 * �Լ���: rotateString()
 * ���: ���ڿ� str�� n���ڸ�ŭ ȸ���Ѵ�.
 *       n > 0 �� ������, n < 0 �� ����
 * �Ű�����: char* str - ȸ���� ���ڿ�
 *           int n - �̵��� ���� ��
 */
void rotateString(char* str, int n)
{
    int len = strlen(str);
    if (len == 0) return; // �� ���ڿ� ó��

    // �̵� ���� ���� ���ڿ� ���̷� ����
    n = n % len;
    if (n < 0) n = n + len; // ������ ���� ȸ���� ������ ȸ������ ��ȯ

    char temp[100];
    int i;

    // ȸ���� ���ڿ� ����
    for (i = 0; i < len; i++)
        temp[i] = str[(i - n + len) % len];
    temp[len] = '\0';

    // ���� ���ڿ��� ����
    strcpy(str, temp);
}

/*
 * �Լ���: removeNewline()
 * ���: fgets�� �Է¹��� ���ڿ� ���� ���� ���� ����
 */
void removeNewline(char* str)
{
    int i;
    for (i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
