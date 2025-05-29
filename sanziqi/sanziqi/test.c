#define _CRT_SECURE_NO_WARNINGS


#include "game.h"

void memu()
{
	printf("**************************\n");
	printf("*****   1.开始游戏   *****\n");
	printf("*****   0.退出游戏   *****\n");
	printf("**************************\n");
}

void game()
{
	
	char ret = 0;
	char board[ROW][COL] = { 0 };
	int backG[ROW][COL] = { 0 };
	char forseek[(DP + 1)*2][2] = { 0 };
	//重置步数
	ReNums();
	SaveComM(0, 0);
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//初始化权盘
	InitBackG(backG, ROW, COL);
	//显示棋盘
	DisplayBoard(board, ROW, COL);

	DisplayBackG(backG, ROW, COL);
	while(1)
	{ 
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断
		ret = IsWin(board, backG, ROW, COL ,NUM);
		DisplayBackG(backG, ROW, COL);

		if (ret != C)
			break;
		printf("%d", ret);
		ComputerMove(board, backG, forseek, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断
		
		ret = IsWin(board, backG, ROW, COL ,NUM);
		DisplayBackG(backG, ROW, COL);

		if (ret != C)
			break;
		printf("%d",ret);


	}
	if (ret == QP)
		printf("玩家赢！\n");
	else if (ret == QC)
		printf("电脑赢！\n");
	else if (ret == Q)
		printf("平局！\n");

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		memu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);
	return 0;
}