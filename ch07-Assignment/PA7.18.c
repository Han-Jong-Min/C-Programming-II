/* 파일명: PA7.18.c

  * 내용: 수학에서 집합은 다중집합과 다르게 원소의 중복을 허용하지 않는다. 최대 10개의
          정수형 원소를 저장할 수 있는 다중집합을 프로그램하시오. 정수를 입력받아 집합의
          원소를 추가하고, 그 때마다 집합의 원소들을 출력하시오.

  * 작성자: 한종민

  * 날짜: 2025.09.17.

  * 버전: v1.0

  */

#include <stdio.h>

#define MAX_SIZE 10

int assignment18(void);
int findElement(int arr[], int size, int element);
void printArray(int arr[], int size);

int main() {
    return assignment18();
}

int assignment18(void) {
    int arr[MAX_SIZE];
    int size = 0;  // 현재 원소 개수
    int element;

    printf("정수형 집합 프로그램 (최대 %d개)\n", MAX_SIZE);
    printf("종료하려면 -1 입력\n\n");

    while (size < MAX_SIZE) {
        printf("배열의 추가할 원소? ");
        scanf("%d", &element);

        if (element == -1) break; // 종료

        int idx = findElement(arr, size, element);
        if (idx != -1) {
            printf("해당 원소가 이미 [%d]에 존재합니다.\n", idx);
        }
        else {
            arr[size++] = element;
        }

        printArray(arr, size);
        printf("\n");
    }

    printf("최종 배열: ");
    printArray(arr, size);
    printf("\n");

    return 0;
}

/*
 * 함수명: findElement()
 * 기능: 배열에서 원소 검색, 있으면 인덱스 반환, 없으면 -1
 */
int findElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) return i;
    }
    return -1;
}

/*
 * 함수명: printArray()
 * 기능: 배열의 현재 원소 출력
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}