#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void memu()
{
	printf("******************************\n");
	printf("********  1.��ʼ��Ϸ  ********\n");
	printf("********  1.�˳���Ϸ  ********\n");
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
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//printf("ɨ��\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("�����������������룺\n");
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
		printf("���ĵ��Խ���2���Ӻ�رգ��뿪ʼ��Ϸͨ����ȡ��");
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("ɨ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������룺\n");
			break;
		}

	} while (input);

	return 0;
}
