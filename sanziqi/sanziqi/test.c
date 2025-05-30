#define _CRT_SECURE_NO_WARNINGS


#include "game.h"

void memu()
{
	printf("**************************\n");
	printf("*****   1.��ʼ��Ϸ   *****\n");
	printf("*****   0.�˳���Ϸ   *****\n");
	printf("**************************\n");
}

void game()
{
	
	char ret = 0;
	char board[ROW][COL] = { 0 };
	int backG[ROW][COL] = { 0 };
	char forseek[(DP + 1)*2][2] = { 0 };
	//���ò���
	ReNums();
	SaveComM(0, 0);
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ʼ��Ȩ��
	InitBackG(backG, ROW, COL);
	//��ʾ����
	DisplayBoard(board, ROW, COL);

	DisplayBackG(backG, ROW, COL);
	while(1)
	{ 
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�
		ret = IsWin(board, backG, ROW, COL ,NUM);
		DisplayBackG(backG, ROW, COL);

		if (ret != C)
			break;
		printf("%d", ret);
		ComputerMove(board, backG, forseek, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�
		
		ret = IsWin(board, backG, ROW, COL ,NUM);
		DisplayBackG(backG, ROW, COL);

		if (ret != C)
			break;
		printf("%d",ret);


	}
	if (ret == QP)
		printf("���Ӯ��\n");
	else if (ret == QC)
		printf("����Ӯ��\n");
	else if (ret == Q)
		printf("ƽ�֣�\n");

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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);
	return 0;
}