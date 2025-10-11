/* 파일명: PA9.17.c
 * 내용: 최대 20개의 노래 제목을 관리하는 프로그램.
 *       간단한 메뉴로 노래 제목 추가, 수정, 목록 출력 기능 제공.
 *       0을 입력하면 프로그램 종료.
 * 작성자: 한종민
 * 작성일: 2025.10.10
 * 버전: v1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 20
#define MAX_TITLE 40

 // 함수 원형 선언
void assignment17(void);
void addSong(char songs[][MAX_TITLE + 1], int* count);
void editSong(char songs[][MAX_TITLE + 1], int count);
void printSongs(char songs[][MAX_TITLE + 1], int count);
void removeNewline(char* str);

/*
 * 함수명: main()
 * 기능: assignment17 함수를 호출하여 프로그램 실행
 */
int main(void)
{
    assignment17();
    return 0;
}

/*
 * 함수명: assignment17()
 * 기능: 간단한 메뉴로 노래 제목을 추가, 수정, 출력하는 기능 제공
 */
void assignment17(void)
{
    char songs[MAX_SONGS][MAX_TITLE + 1]; // 노래 제목 저장
    int songCount = 0; // 현재 저장된 노래 수
    int choice;

    while (1)
    {
        printf("\n===== 노래 관리 프로그램 =====\n");
        printf("1. 추가\n");
        printf("2. 수정\n");
        printf("3. 목록\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar(); // 남은 개행 제거

        if (choice == 0)
        {
            printf("프로그램을 종료합니다.\n");
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
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }
}

/*
 * 함수명: addSong()
 * 기능: 노래 제목을 추가
 * 매개변수: songs - 노래 배열, count - 현재 노래 수 포인터
 */
void addSong(char songs[][MAX_TITLE + 1], int* count)
{
    if (*count >= MAX_SONGS)
    {
        printf("더 이상 노래를 추가할 수 없습니다.\n");
        return;
    }

    printf("추가할 노래 제목 입력: ");
    fgets(songs[*count], MAX_TITLE + 1, stdin);
    removeNewline(songs[*count]);

    (*count)++;
    printf("노래가 추가되었습니다.\n");
}

/*
 * 함수명: editSong()
 * 기능: 특정 노래 제목을 수정
 * 매개변수: songs - 노래 배열, count - 현재 노래 수
 */
void editSong(char songs[][MAX_TITLE + 1], int count)
{
    if (count == 0)
    {
        printf("등록된 노래가 없습니다.\n");
        return;
    }

    int index;
    printSongs(songs, count);
    printf("수정할 노래 번호 입력: ");
    scanf("%d", &index);
    getchar(); // 남은 개행 제거

    if (index < 1 || index > count)
    {
        printf("잘못된 번호입니다.\n");
        return;
    }

    printf("새 노래 제목 입력: ");
    fgets(songs[index - 1], MAX_TITLE + 1, stdin);
    removeNewline(songs[index - 1]);

    printf("노래가 수정되었습니다.\n");
}

/*
 * 함수명: printSongs()
 * 기능: 현재 저장된 모든 노래 제목 출력
 * 매개변수: songs - 노래 배열, count - 현재 노래 수
 */
void printSongs(char songs[][MAX_TITLE + 1], int count)
{
    if (count == 0)
    {
        printf("등록된 노래가 없습니다.\n");
        return;
    }

    printf("\n===== 노래 목록 =====\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, songs[i]);
    }
}

/*
 * 함수명: removeNewline()
 * 기능: fgets로 입력받은 문자열 끝의 개행 문자 제거
 */
void removeNewline(char* str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
