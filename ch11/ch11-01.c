/*
	이름: 한종민
	학번: 202111604
	프로그램명: ch11-01.c        main.c
	날짜: 2025-10-14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

// extern int get_id(void);
// extern int last_id = 1000;

int main(int argc, char* argv[])
{
	printf("추석 잘 보냈어요?\n");

	printf("회원 1의 id = %d\n", get_id()); //1001
	printf("회원 2의 id = %d\n", get_id()); //1002
	printf("회원 3의 id = %d\n", get_id()); //1003

	//printf("last_id = %d\n", last_id++);
}