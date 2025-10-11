/* ���ϸ�: PA10.02.c
 * ����: 1�� ���α׷��� ���̵�� �н����带 �׻� �ҹ��ڷ� �����Ϸ��� �Ѵ�. LOGIN ����ü�� �Ű������� ���޹޾� 
        ����ü�� ����� ���̵�� �н����带 ��� �ҹ��ڷ� ����� make_lower �Լ��� ���̵�� �н����带 ����ϴ� 
        print_login �Լ��� �����Ͻÿ�
 * �ۼ���: ������
 * �ۼ���: 2025.10.11
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN 20

 // LOGIN ����ü ����
typedef struct
{
    char id[MAX_LEN + 1];
    char password[MAX_LEN + 1];
} LOGIN;

// �Լ� ���� ����
void assignment02(void);
void removeNewline(char* str);
void make_lower(LOGIN* user);
void print_login(const LOGIN* user);

/*
 * �Լ���: main()
 * ���: assignment02 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment02();
    return 0;
}

/*
 * �Լ���: assignment02()
 * ���: LOGIN ����ü ������ ���̵�� �н����带 �Է¹޾� �ҹ��ڷ� ��ȯ �� ���
 */
void assignment02(void)
{
    LOGIN user;

    // ���̵� �Է�
    printf("���̵� �Է�: ");
    fgets(user.id, sizeof(user.id), stdin);
    removeNewline(user.id);

    // �н����� �Է�
    printf("�н����� �Է�: ");
    fgets(user.password, sizeof(user.password), stdin);
    removeNewline(user.password);

    // �ҹ��ڷ� ��ȯ
    make_lower(&user);

    // ���
    print_login(&user);
}

/*
 * �Լ���: make_lower()
 * ���: LOGIN ����ü ������ ����� ���̵�� �н����带 ��� �ҹ��ڷ� ��ȯ
 */
void make_lower(LOGIN* user)
{
    for (int i = 0; user->id[i] != '\0'; i++)
    {
        if (user->id[i] >= 'A' && user->id[i] <= 'Z')
            user->id[i] += 'a' - 'A';
    }

    for (int i = 0; user->password[i] != '\0'; i++)
    {
        if (user->password[i] >= 'A' && user->password[i] <= 'Z')
            user->password[i] += 'a' - 'A';
    }
}

/*
 * �Լ���: print_login()
 * ���: ���̵�� �н����带 ���, �н������ '*'�� ǥ��
 */
void print_login(const LOGIN* user)
{
    printf("\n");
    printf("���̵�: %s\n", user->id);
    printf("�н�����: ");
    for (int i = 0; user->password[i] != '\0'; i++)
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
