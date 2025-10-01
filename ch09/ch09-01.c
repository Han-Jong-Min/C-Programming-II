/*
	�̸�: ������
	�й�: 202111604
	���α׷���: ch09-01.c
	��¥: 2025-09-24

	����: Ű����κ��� ���� ���ڵ带 �� �� �Է¹޾� �ʵ鸦
	�����Ͽ� ����ü �迭�� ������ �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���ڵ� ����: �̸�, �й�, �а�, �г�(����)
	�Է� ���� ����: "exit" �Է�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define BUFFER_SIZE 128

struct Student {
	char name[24];
	char id[16];
	char major[32];
	int year;
};
typedef struct Student Student;

int inputStudents(Student students[], int max);
void printStudents(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = inputStudents(students, MAX_STUDENTS);
    printStudents(students, studentCount);
    return 0;
}

// �л� ���� �Է� �Լ� (�Է¹��� �л� �� ��ȯ)
int inputStudents(Student students[], int max) {
    int count = 0;
    char input[BUFFER_SIZE];

    printf("�л� ������ �Է��ϼ��� (����: �̸�,�й�,�а�,�г�). �����Ϸ��� 'exit' �Է�:\n");

    while (count < max) {
        printf("�Է� %d > ", count + 1);
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        // ���� ���� ����
        input[strcspn(input, "\n")] = 0;

        // ���� ����
        if (strcmp(input, "exit") == 0) {
            break;
        }

        char* token = strtok(input, ",");
        if (token == NULL) continue;
        strncpy(students[count].name, token, sizeof(students[count].name) - 1);
        students[count].name[sizeof(students[count].name) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(students[count].id, token, sizeof(students[count].id) - 1);
        students[count].id[sizeof(students[count].id) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(students[count].major, token, sizeof(students[count].major) - 1);
        students[count].major[sizeof(students[count].major) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[count].year = atoi(token);

        count++;
    }
    return count;
}

// �л� ���� ��� �Լ�
void printStudents(Student students[], int count) {
    printf("\n�Էµ� �л� ����:\n");
    for (int i = 0; i < count; i++) {
        printf("�л� %d: �̸�: %s, �й�: %s, �а�: %s, �г�: %d\n",
            i + 1, students[i].name, students[i].id,
            students[i].major, students[i].year);
    }
}