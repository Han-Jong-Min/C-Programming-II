/* ���ϸ�: PA10.01.c
 * ����: ���ͳ� ����Ʈ �α��� ������ �����ϴ� LOGIN ����ü�� �����ϰ�
 *       ���̵�� �н����带 �Է¹޾� ����ϴ� ���α׷�.
 *       �н������ ���� ����ŭ '*'�� ǥ��.
 * �ۼ���: ������
 * �ۼ���: 2025.10.11
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

 // LOGIN ����ü ����
typedef struct
{
    char id[MAX_LEN + 1];
    char password[MAX_LEN + 1];
} LOGIN;

// �Լ� ���� ����
void assignment01(void);
void removeNewline(char* str);

/*
 * �Լ���: main()
 * ���: assignment01 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment01();
    return 0;
}

/*
 * �Լ���: assignment01()
 * ���: LOGIN ����ü ������ ���̵�� �н����带 �Է¹޾� �����ϰ� ���
 */
void assignment01(void)
{
    LOGIN user;

    // ���̵� �Է�
    printf("ID? ");
    fgets(user.id, sizeof(user.id), stdin);
    removeNewline(user.id);

    // �н����� �Է�
    printf("PW? ");
    fgets(user.password, sizeof(user.password), stdin);
    removeNewline(user.password);

    // ���
    printf("\n");
    printf("ID: %s\n", user.id);
    printf("PW: ");
    for (int i = 0; user.password[i] != '\0'; i++)
        printf("*");
    printf("\n");
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
