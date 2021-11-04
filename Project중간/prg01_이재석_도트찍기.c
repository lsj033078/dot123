#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // 콘솔창의 핸들정보 받기      


void gotoxy(int x, int y); // (x,y)의 좌표이다.
void Board(); // 도트판
void dot(int[][30]);
int final= 0; // 완료와 관련된 flag 변수이다. 완료하는 순간 1이 된다.

int main(int argc, char* argv[])
{
	int board[20][20] = {"0"};
	Board(); //보드
	while (1) // 무한루프
	{
		if (final != 1) // 완료버튼 클릭
		{
			dot(board);
		}
	
	}
	Sleep(3000);
	return 0;
}


void gotoxy(int x, int y) { // x,y 좌표를 사용한다.
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Board() 
{
	printf("================도트 그림판=================\n");
	printf("  1 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  2 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  3 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  4 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  5 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  6 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  7 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  8 □□□□□□□□□□□□□□□□□□□□\n");
	printf("  9 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 10 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 11 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 12 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 13 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 14 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 16 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 17 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 18 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 19 □□□□□□□□□□□□□□□□□□□□\n");
	printf(" 20 □□□□□□□□□□□□□□□□□□□□\n");
	printf("    1 2 3 4 5 6 7 8 9 1011121314151617181920");
}



void dot(int board[][21])
{
	int x, y;
	gotoxy(40, 23);
	printf("위치 선택(예 : 6 14)");
	while (1)
	{
		gotoxy(10, 23);
		printf("       ");
		gotoxy(10, 23);
		scanf_s("%d %d", &x, &y );
		if (x < 1 || x > 20 || y < 1 || y > 20) // 이상한 곳에 두는 것을 방지
		{
			printf("\a"); // 경고음 출력
			continue;
		}
		if (board[y][x] != 0) // 이미 있는 곳에 두는 것을 방지
		{
			printf("\a"); // 경고음 출력
			continue;
		}
		else
		{
			board[y][x] = 1;
			y++;
			break;
		}
	}

	gotoxy(y * 2 ,x);
	printf("■");
}