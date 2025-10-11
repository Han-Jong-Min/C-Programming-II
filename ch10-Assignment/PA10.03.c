/* ���ϸ�: PA10.03.c
 * ����: LOGIN ����ü �迭�� �̿��Ͽ� �α��� ������ ó���ϴ� ���α׷�.
 *       ���̵� �Է¹޾� ��ϵ� LOGIN �迭���� �˻��ϰ�,
 *       �н����尡 ��ġ�ϸ� �α��� ���� ���.
 * �ۼ���: ������
 * �ۼ���: 2025.10.11
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define USER_COUNT 5

 // LOGIN ����ü ����
typedef struct
{
    char id[MAX_LEN + 1];
    char password[MAX_LEN + 1];
} LOGIN;

// �Լ� ���� ����
void assignment03(void);
void removeNewline(char* str);

/*
 * �Լ���: main()
 * ���: assignment03 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment03();
    return 0;
}

/*
 * �Լ���: assignment03()
 * ���: LOGIN �迭���� ���̵�/�н����带 Ȯ���Ͽ� �α��� ���� ���� ���
 */
void assignment03(void)
{
    // LOGIN ����ü �迭 �ʱ�ȭ
    LOGIN users[USER_COUNT] = {
        {"aaaaaa", "abcd123"},
        {"bbbbbb", "abcd456"},
        {"cccccc", "abcd789"},
        {"dddddd", "abcd321"},
        {"eeeeee", "abcd654"}
    };

    char inputId[MAX_LEN + 1];
    char inputPw[MAX_LEN + 1];
    int i;
    int found = 0;

    // ���̵� �Է�
    printf("ID? ");
    fgets(inputId, sizeof(inputId), stdin);
    removeNewline(inputId);

    // �迭���� ���̵� �˻�
    for (i = 0; i < USER_COUNT; i++)
    {
        if (strcmp(users[i].id, inputId) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("�α��� ����: ���̵� �������� �ʽ��ϴ�.\n");
        return;
    }

    // �н����� �Է�
    printf("PW? ");
    fgets(inputPw, sizeof(inputPw), stdin);
    removeNewline(inputPw);

    if (strcmp(users[i].password, inputPw) == 0)
        printf("�α��� ����\n");
    else
        printf("�α��� ����\n");
}

/*
 * �Լ���: removeNewline()
 * ���: fgets�� �Է¹��� ���ڿ� ���� ���� ���� ����
 */
void removeNewline(char* str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
