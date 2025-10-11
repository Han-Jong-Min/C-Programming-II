/* ���ϸ�: PA9.14.c
 * ����: ���ͳ� ����Ʈ�� ȸ�� ������ �Ϸ��� ����ڷκ��� ���̵� �Է¹޾�
 *       ��ȿ�� ���̵����� �˻��ϴ� ���α׷��� �ۼ��Ѵ�.
 *       ���̵�� �����ڷ� �����ؾ� �ϰ�, �����ڿ� ���ڷθ� �����Ǹ�
 *       �ּ� 8�� �̻��̾�� �Ѵ�.
 * �ۼ���: ������
 * �ۼ���: 2025.10.10
 * ����: v1.1
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // �Լ� ���� ����
void assignment14(void);
int isValidID(const char* id);
void removeNewline(char* str);

/*
 * �Լ���: main()
 * ���: assignment14 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment14();
    return 0;
}

/*
 * �Լ���: assignment14()
 * ���: ����ڷκ��� ���̵� �Է¹޾� ��ȿ�� �˻� �� ����� ����Ѵ�.
 */
void assignment14(void)
{
    char id[100];
    int valid;

    printf("ID? ");
    fgets(id, sizeof(id), stdin);
    removeNewline(id);

    valid = isValidID(id);

    if (valid)
        printf("'%s'��(��) ID�� ����� �� �ֽ��ϴ�.\n", id);
}

/*
 * �Լ���: isValidID()
 * ���: �Էµ� ���ڿ��� ���̵� ����(���� ����, ����/���� ����, 8�� �̻�)�� �����ϴ��� �˻��Ѵ�.
 * �Ű�����: const char* id - �˻��� ���̵� ���ڿ�
 * ��ȯ��: ������ �����ϸ� 1, �׷��� ������ 0
 */
int isValidID(const char* id)
{
    int i, len = 0;

    // ù ���ڰ� �����ڰ� �ƴϸ� ����
    if (!((*id >= 'A' && *id <= 'Z') || (*id >= 'a' && *id <= 'z')))
    {
        printf("ID�� �����ڷ� �����ؾ� �մϴ�.\n");
        return 0;
    }

    // �� ���� Ȯ��
    for (i = 0; id[i] != '\0'; i++)
    {
        char c = id[i];
        if (!((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')))
        {
            printf("ID�� �����ڿ� ���ڷθ� �����Ǿ�� �մϴ�.\n");
            return 0;
        }
        len++;
    }

    // ���̰� 8�� �̸��̸� ����
    if (len < 8)
    {
        printf("ID�� 8�� �̻��̾�� �մϴ�.\n");
        return 0;
    }

    return 1; // ��� ������ ����ϸ� ��ȿ
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
