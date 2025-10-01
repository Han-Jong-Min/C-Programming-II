/* 파일명: PA7.16.c
  * 내용: 정수형 배열과 키 값을 매개변수로 전달받아 배열에서 키 값을 찾아 인덱스를 리턴하는
          find_array 함수를 작성하시오. 키 값을 찾을 수 없으면 -1을 리턴한다.
  * 작성자: 한종민
  * 날짜: 2025.09.17.
  * 버전: v1.1
*/

#include <stdio.h>

int assignment16(void);
int find_array(int arr[], int size, int key);
void printArray(int arr[], int size);  // 배열 출력 함수

int main() {
    return assignment16();
}

int assignment16(void) {
    int arr[] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, index;

    printf("배열: ");
    printArray(arr, size);  // 배열 먼저 출력

    printf("찾을 값? ");
    scanf("%d", &key);

    index = find_array(arr, size, key);

    if (index != -1) {
        printf("%d는 %d번째 원소입니다.\n", key, index);
    }
    else {
        printf("키 %d를 배열에서 찾을 수 없습니다.\n", key);
    }

    return 0;
}

/*
 * 함수명: find_array()
 * 기능: 정수형 배열에서 키 값을 찾아 인덱스를 리턴
 * 매개변수: int arr[] - 검색할 배열, int size - 배열 크기, int key - 찾을 값
 * 반환값: 키 값의 인덱스, 없으면 -1
 */
int find_array(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // 키를 찾지 못했을 경우
}

/*
 * 함수명: printArray()
 * 기능: 배열의 원소들을 공백으로 구분해 출력
 * 매개변수: int arr[] - 출력할 배열, int size - 배열 크기
 * 반환값: 없음
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}