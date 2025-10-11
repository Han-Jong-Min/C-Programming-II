/* ���ϸ�: PA9.17.c
 * ����: �ִ� 20���� �뷡 ������ �����ϴ� ���α׷�.
 *       ������ �޴��� �뷡 ���� �߰�, ����, ��� ��� ��� ����.
 *       0�� �Է��ϸ� ���α׷� ����.
 * �ۼ���: ������
 * �ۼ���: 2025.10.10
 * ����: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 20
#define MAX_TITLE 40

 // �Լ� ���� ����
void assignment17(void);
void addSong(char songs[][MAX_TITLE + 1], int* count);
void editSong(char songs[][MAX_TITLE + 1], int count);
void printSongs(char songs[][MAX_TITLE + 1], int count);
void removeNewline(char* str);

/*
 * �Լ���: main()
 * ���: assignment17 �Լ��� ȣ���Ͽ� ���α׷� ����
 */
int main(void)
{
    assignment17();
    return 0;
}

/*
 * �Լ���: assignment17()
 * ���: ������ �޴��� �뷡 ������ �߰�, ����, ����ϴ� ��� ����
 */
void assignment17(void)
{
    char songs[MAX_SONGS][MAX_TITLE + 1]; // �뷡 ���� ����
    int songCount = 0; // ���� ����� �뷡 ��
    int choice;

    while (1)
    {
        printf("\n===== �뷡 ���� ���α׷� =====\n");
        printf("1. �߰�\n");
        printf("2. ����\n");
        printf("3. ���\n");
        printf("0. ����\n");
        printf("����: ");
        scanf("%d", &choice);
        getchar(); // ���� ���� ����

        if (choice == 0)
        {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        switch (choice)
        {
        case 1:
            addSong(songs, &songCount);
            break;
        case 2:
            editSong(songs, songCount);
            break;
        case 3:
            printSongs(songs, songCount);
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }
}

/*
 * �Լ���: addSong()
 * ���: �뷡 ������ �߰�
 * �Ű�����: songs - �뷡 �迭, count - ���� �뷡 �� ������
 */
void addSong(char songs[][MAX_TITLE + 1], int* count)
{
    if (*count >= MAX_SONGS)
    {
        printf("�� �̻� �뷡�� �߰��� �� �����ϴ�.\n");
        return;
    }

    printf("�߰��� �뷡 ���� �Է�: ");
    fgets(songs[*count], MAX_TITLE + 1, stdin);
    removeNewline(songs[*count]);

    (*count)++;
    printf("�뷡�� �߰��Ǿ����ϴ�.\n");
}

/*
 * �Լ���: editSong()
 * ���: Ư�� �뷡 ������ ����
 * �Ű�����: songs - �뷡 �迭, count - ���� �뷡 ��
 */
void editSong(char songs[][MAX_TITLE + 1], int count)
{
    if (count == 0)
    {
        printf("��ϵ� �뷡�� �����ϴ�.\n");
        return;
    }

    int index;
    printSongs(songs, count);
    printf("������ �뷡 ��ȣ �Է�: ");
    scanf("%d", &index);
    getchar(); // ���� ���� ����

    if (index < 1 || index > count)
    {
        printf("�߸��� ��ȣ�Դϴ�.\n");
        return;
    }

    printf("�� �뷡 ���� �Է�: ");
    fgets(songs[index - 1], MAX_TITLE + 1, stdin);
    removeNewline(songs[index - 1]);

    printf("�뷡�� �����Ǿ����ϴ�.\n");
}

/*
 * �Լ���: printSongs()
 * ���: ���� ����� ��� �뷡 ���� ���
 * �Ű�����: songs - �뷡 �迭, count - ���� �뷡 ��
 */
void printSongs(char songs[][MAX_TITLE + 1], int count)
{
    if (count == 0)
    {
        printf("��ϵ� �뷡�� �����ϴ�.\n");
        return;
    }

    printf("\n===== �뷡 ��� =====\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, songs[i]);
    }
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
