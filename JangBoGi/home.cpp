﻿#include "home.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4


void title()
{
	printf("\n\n\n\n");
	printf("		      ##    ###    ##    ##  ######   ########   #######   ######   #### \n");
	printf("		      ##   ## ##   ###   ## ##    ##  ##     ## ##     ## ##    ##   ##  \n");
	printf("		      ##  ##   ##  ####  ## ##        ##     ## ##     ## ##         ##  \n");
	printf("		      ## ##     ## ## ## ## ##   #### ########  ##     ## ##   ####  ##  \n");
	printf("		##    ## ######### ##  #### ##    ##  ##     ## ##     ## ##    ##   ##  \n");
	printf("		##    ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##    ##   ##  \n");
	printf("		 ######  ##     ## ##    ##  ######   ########   #######   ######   #### \n");
	printf("\n");
	gotoxy(8, 22);
	printf("선택: 엔터");
	gotoxy(33, 22);
	printf("이동: 방향키");
	gotoxy(63, 22);
	printf("뒤로가기: X");
	gotoxy(90, 22);
	printf("삭제: D");
}

int menudraw()
{
	int x = 50;
	int y = 12;
	gotoxy(x - 2, y);
	printf("> 현 황");
	gotoxy(x, y + 1);
	printf("재 료");
	gotoxy(x, y + 2);
	printf("추 가");
	gotoxy(x, y + 3);
	printf("종 료");
	while (1)
	{	
		int n = keyControl();
		switch (n)
		{
		case UP:
			if (y > 12)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		case DOWN:
			if (y < 15)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		case SUBMIT: 
			return y - 12;
		}
	}
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandel = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandel, pos);
}

int keyControl()
{
	int key = _getch();
	if (key == 13)
		return SUBMIT;

	if (key == 224)
	{
		key = _getch();
		if (key == 72)
			return UP;
		else if (key == 75)
			return LEFT;
		else if (key == 77)
			return RIGHT;
		else if (key == 80)
			return DOWN;
	}
}

void init()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}