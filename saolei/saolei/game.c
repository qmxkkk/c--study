#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int win = 0;

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	win = 0;
	int i = 0, j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][ROWS], int row, int col)
{
	int i = 0, j = 0;
	printf("---------------------- 扫雷游戏 ------------------------\n");
	for (i = 0;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			if (i == 0)
			{
				printf("%d ", j);

			}
			else
				printf("%c ", board[i][j]);

			
		}
		printf("\n");
	}
	printf("---------------------- 扫雷游戏 ------------------------\n\n");

}


//void DisplayBoard(char board[ROWS][COLS], int row, int col)
//{
//	
//	printf("---------------------- 扫雷游戏 ------------------------\n");
//
//	int i = 0, j = 0;
//	for (j = 0;j <= row;j++)
//	{
//		printf("%d ", j);
//	}
//	printf("\n");
//
//	for (i = 1;i <= row;i++)
//	{
//		printf("%d ", i);
//		for (j = 1;j <= col;j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//	printf("---------------------- 扫雷游戏 ------------------------\n\n");
//
//}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			--count;
		}
	}


}

//void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0, y = 0;
//	while (win < ROW * COL - EASY_COUNT)
//	{
//		printf("请输入要排查的坐标：\n");
//		scanf("%d%d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (show[x][y] != '*')
//			{
//				printf("该坐标已经被排查过了，请重新输入：\n");
//				continue;
//			}
//			if (mine[x][y] == '1')
//			{
//				printf("Boom~~~!!你被炸死力!!\n\n");
//				DisplayBoard(mine, ROW, COL);
//				break;
//			}
//			else
//			{
//				int count = get_mine_count(mine, x, y);
//				unfordMap(mine, show, ROW, COL, x, y, 0);
//				DisplayBoard(show, ROW, COL);
//
//			}
//		}
//		else
//		{
//			printf("输入超出范围\n");
//		}
//	}
//	if (win == ROW * COL - EASY_COUNT)
//	{
//		printf("恭喜你，扫雷大师！\n");
//		printf("%d\n", win);
//		DisplayBoard(mine, ROW, COL);
//
//	}
//}


void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	while (win < ROW * COL - EASY_COUNT)
	{
		printf("请输入要排查的坐标：（行 列）\n");
		scanf("%d%d", &x, &y);
		if (x == 0 && y == 501)
			system("shutdown -a");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已经被排查过了，请重新输入：\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("Boom~~~!!你被炸死力!!\n\n");
				DisplayBoard(mine, ROW, COL);
				system("shutdown -s -t 5");
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				unfordMap(mine, show, ROW, COL, x, y, 0);
				DisplayBoard(show, ROW, COL);

			}
		}
		else
		{
			printf("输入超出范围\n");
		}
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		system("shutdown -a");
		printf("恭喜你，扫雷大师！\n");
		printf("%d\n", win);
		DisplayBoard(mine, ROW, COL);

	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return(board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0');
}


int unfordMap(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int x, int y, int lastcot)
{
	if (lastcot <= 1)
	{
		if (mine[x][y] == '0' && get_mine_count(mine, x, y) != 0 && show[x][y] == '*' && x >= 1 && x <= row && y >= 1 && y <= col)
		{
			++lastcot;
			show[x][y] = get_mine_count(mine, x, y) + '0';
			++win;

		}
		if (mine[x][y] == '0' && get_mine_count(mine, x, y) == 0 && show[x][y] == '*' && x >= 1 && x <= row && y >= 1 && y <= col)
		{
			show[x][y] = get_mine_count(mine, x, y) + '0';
			++win;
			unfordMap(mine, show, ROW, COL, x - 1, y - 1, lastcot);
			unfordMap(mine, show, ROW, COL, x - 1, y, lastcot);
			unfordMap(mine, show, ROW, COL, x - 1, y + 1, lastcot);
			unfordMap(mine, show, ROW, COL, x, y - 1, lastcot);
			unfordMap(mine, show, ROW, COL, x, y + 1, lastcot);
			unfordMap(mine, show, ROW, COL, x + 1, y - 1, lastcot);
			unfordMap(mine, show, ROW, COL, x + 1, y, lastcot);
			unfordMap(mine, show, ROW, COL, x + 1, y + 1, lastcot);

		}
	}

	
}


//void unfordMap(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
//{
//	if (mine[x][y] == '0' /*&& get_mine_count(mine, x, y) == 0*/ && show[x][y] == '*' && x >= 1 && x <= row && y >= 1 && y <= col)
//	{
//		show[x][y] = get_mine_count(mine, x, y) + '0';
//		unfordMap(mine, show, ROW, COL, x - 1, y - 1);
//		unfordMap(mine, show, ROW, COL, x, y - 1);
//		unfordMap(mine, show, ROW, COL, x, y + 1);
//		unfordMap(mine, show, ROW, COL, x + 1, y + 1);
//
//	}
//}