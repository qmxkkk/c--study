#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


int PlayerNums = 0;
int ComputerNums = 0;
int CpI = 0, ExCpI = 0;
int CpJ = 0, ExCpJ = 0;

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}

}

void InitBackG(char backG[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			backG[i][j] = 0;
		}
	}

}

void LoadToBackG(char board[ROW][COL], char backG[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == '*')
				backG[i][j] = QP;
			else if(board[i][j] == '#')
				backG[i][j] = QC;
			else if (board[i][j] == ' ')
				backG[i][j] = 0;
		}
	}
}

//第一版
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0;i < row;i++)
//	{
//		//打印表格
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if(i<row-1)
//			printf("---|---|---\n");
//	}
//
//}

//第二版
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//打印表格
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (int j = 0;j < col;j++)
		{
			
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		//打印分割
		//if(i<row-1)
		//	printf("---|---|---\n");
		if (i < row - 1)
		{
			int j = 0;
			for (int j = 0;j < col;j++)
			{

				printf("---");
				if (j < col - 1)
					printf("|");

			}
			printf("\n");
		}
	}
	printf("\n");

}

void DisplayBackG(char backG[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//打印表格
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (int j = 0;j < col;j++)
		{

			printf(" %+d ", backG[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		//打印分割
		//if(i<row-1)
		//	printf("---|---|---\n");
		if (i < row - 1)
		{
			int j = 0;
			for (int j = 0;j < col;j++)
			{

				printf("----");
				if (j < col - 1)
					printf("|");

			}
			printf("\n");
		}
	}
	printf("\n");

}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)
	{
		printf("玩家请输入坐标：\n");
		scanf("%d %d", &y, &x);
		if (x>=1 && x<=col && y>=1 && y<=row)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				++PlayerNums;
				break;
			}
			else
			{
				printf("该位置已被下过，请输入其他坐标\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}

}

//void ComputerMove(char board[ROW][COL], char backG[ROW][COL], int row, int col)
//{
//	printf("电脑下棋\n\n");
//
//
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int isret = 0;
//
//	while (1)
//	{
//		x = rand() % col;
//		y = rand() % row;
//
//
//		if (board[y][x] == ' ' && PlayerNums + ComputerNums <= 2)
//		{
//			board[y][x] = '#';
//			SaveComM(y, x);
//			++ComputerNums;
//			break;
//		}
//		else if (PlayerNums + ComputerNums <= NUM * 2 - 5)
//		{
//
//			ret = ComNear(board, ROW, COL);
//			if (ret == 1)
//				break;
//			else if (board[y][x] == ' ')
//			{
//				board[y][x] = '#';
//				SaveComM(y, x);
//				++ComputerNums;
//				break;
//			}
//
//		}
//		else
//		{
//			ret = IsWinCp(board, backG, ROW, COL, NUM, '#');
//			if (ret == 1)
//			{
//				isret = IsWin(board, ROW, COL, NUM);
//				if (isret == '#')
//					break;
//				else
//				{
//					board[CpI][CpJ] = ' ';
//					CpI = ExCpI;
//					CpJ = ExCpJ;
//					--ComputerNums;
//				}
//			}
//			ret = IsWinCp(board, backG, ROW, COL, NUM, '*');
//			if (ret == 1)
//				break;
//			else if (ret == 0)
//				ret = IsWinCp(board, backG, ROW, COL, NUM, '#');
//			if (ret == 1)
//				break;
//			else if (ret == 0)
//			{
//				ComNear(board, ROW, COL);
//				break;
//			}
//			
//		}
//	}
//
//}

void ComputerMove(char board[ROW][COL], char backG[ROW][COL], char forseek[ROW][COL], int row, int col)
{
	printf("电脑下棋\n\n");

	int max_ret0 = 0, max_ret1 = 0, k = 1;
	int min_ret0 = 0, min_ret1 = 0;
	int max_ret = 0, min_ret = 0;
	char ret = 0;
	int mi = 0, mj = 0;
	int pmi = 0, pmj = 0;
	int mini = 0, minj = 0;
	int pmini = 0, pminj = 0;
	//预测最大值，且保存第二大
	IsWinCp(board, backG, forseek, ROW, COL, 0, '#', k);
	//填入第一大
	board[ forseek[k - 1][0] ][ forseek[k - 1][1] ] = '#';
	mi = forseek[k - 1][0];
	mj = forseek[k - 1][1];
	pmi = forseek[k][0];
	pmj = forseek[k][1];
	pmini = forseek[k + 1][0];
	pminj = forseek[k + 1][1];
	mini = forseek[k + 2][0];
	minj = forseek[k + 2][1];

	ret = IsWin(board, backG, ROW, COL, NUM);
	//获得最大值，计算第一大
	max_ret0 = IsWinCp(board, backG, forseek, ROW, COL, 0, '#', k);
	//复原
	board[mi][mj] = ' ';
	//填入第二大
	board[pmi][pmj] = '#';
	ret = IsWin(board, backG, ROW, COL, NUM);
	max_ret1 = IsWinCp(board, backG, forseek, ROW, COL, 0, '#', k);
	//复原
	board[pmi][pmj] = ' ';
	//填入第一小
	board[mini][minj] = '#';
	ret = IsWin(board, backG, ROW, COL, NUM);
	//获得最小值
	min_ret0 = IsWinCp(board, backG, forseek, ROW, COL, 1, '#', k);
	//复原
	board[mini][minj] = ' ';
	//填入第二大
	board[pmini][pminj] = '#';
	ret = IsWin(board, backG, ROW, COL, NUM);
	min_ret1 = IsWinCp(board, backG, forseek, ROW, COL, 1, '#', k);
	//复原
	board[pmini][pminj] = ' ';
	
	min_ret = min_ret0 <= min_ret1 ? min_ret0 : min_ret1;

	if (max_ret0 <= max_ret1)
	{
		board[mi][mj] = '#';
		max_ret = max_ret0;
		if (min_ret <= -max_ret)
		{
			board[mi][mj] = ' ';
			board[mini][minj] = '#';
		}
	}
	else
	{
		board[pmi][pmj] = '#';
		max_ret = max_ret0;
		if (min_ret <= -max_ret)
		{
			board[pmi][pmj] = ' ';
			board[mini][minj] = '#';
		}
	}
	
	
	

}


//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	printf("电脑下棋\n\n");
//
//
//	int x = 0;
//	int y = 0;
//
//	while (1)
//	{
//		x = rand() % col;
//		y = rand() % row;
//
//		if (board[y][x] == ' ')
//		{
//			board[y][x] = '#';
//			SaveComM(y, x);
//			++ComputerNums;
//			break;
//		}
//
//	}
//
//}

void SaveComM(int x,int y)
{
	ExCpI = CpI;
	ExCpJ = CpJ;
	CpI = x;
	CpJ = y;

}

int ComNear(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % COL - 1;
		y = rand() % ROW - 1;

		if (board[CpI+x][CpJ+y] = ' ' && CpI + x<=ROW-1 && CpI + x>=0 && CpJ + y>=0 && CpJ + y<=COL-1)
		{
			board[CpI + x][CpJ + y] = '#';
			++ComputerNums;
			SaveComM(CpI + x, CpJ + y);
			return 1;
		}
	}
}

//char IsWin(char board[ROW][COL], int row, int col,int num)
//{
//	int i = 0;
//	int j = 0;
//	int sameN = 0;
//
//	if (PlayerNums + ComputerNums >= NUM * 2 - 1)
//	{
//		//行
//		for (i = 0;i < row;i++)
//		{
//			sameN = 0;
//			for (j = 0;j < col - 1;j++)
//			{
//				if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
//					++sameN;
//				else
//					sameN = 0;
//				if (sameN >= NUM-1)
//					return board[i][j];
//			}
//			sameN = 0;
//
//		}
//		//列
//		for (i = 0;i < col;i++)
//		{
//			sameN = 0;
//			for (j = 0;j < row - 1;j++)
//			{
//				if (board[j][i] == board[j + 1][i] && board[j][i] != ' ')
//					++sameN;
//				else
//					sameN = 0;
//				if (sameN >= NUM-1)
//					return board[j][i];
//			}
//			sameN = 0;
//
//		}
//
//		//右下斜角
//		for (i = 0;i <= row - NUM ;i++)
//		{
//			int ti = i;
//			sameN = 0;
//			for (j = 0;j < col - 1;i++, j++)
//			{
//				if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
//					++sameN;
//				else
//					sameN = 0;
//				if (sameN >= NUM - 1)
//					return board[i][j];
//
//			}
//			sameN = 0;
//			i = ti;
//		}
//
//		for (j = 0;j <= col - NUM ;j++)
//		{
//			int tj = j;
//			sameN = 0;
//			for (i = 0;i < row - 1;i++, j++)
//			{
//				if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
//					++sameN;
//				else
//					sameN = 0;
//				if (sameN >= NUM - 1)
//					return board[i][j];
//
//			}
//			sameN = 0;
//			j = tj;
//		}
//
//		//左下斜角
//		for (i = 0;i <= row - NUM ;i++)
//		{
//			int ti = i;
//			sameN = 0;
//			for (j = col;i < row - 1 ;i++, j--)
//			{
//				if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
//					++sameN;
//				else
//					sameN = 0;
//				if (sameN >= NUM - 1)
//					return board[i][j];
//
//			}
//			sameN = 0;
//			i = ti;
//		}
//
//		for (j = col -1;j >= col - NUM ;j--)
//		{
//			int tj = j;
//			sameN = 0;
//			for (i = 0 ; j >= 1 ;i++, j--)
//			{
//				if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
//					++sameN;
//				else
//					sameN = 0;
//				if (sameN >= NUM - 1)
//					return board[i][j];
//
//			}
//			sameN = 0;
//			j = tj;
//		}
//
//		//平局
//		if (PlayerNums + ComputerNums == row * col)
//			return 'Q';
//
//		//继续
//		return 'C';
//	}
//	else
//		return 'C';
//}

int WriteBackG(char board[ROW][COL], char backG[ROW][COL], int row, int col, int dest)
{
	if (row<0 || row >= ROW || col<0 || col >= COL)
	{
		return 0;
	}
	else
	{
		if(board[row][col]==' ')
			return backG[row][col] += dest;
	}
}

char IsWin(char board[ROW][COL], char backG[ROW][COL], int row, int col, int num)
{
	LoadToBackG(board, backG, ROW, COL);
	int i = 0;
	int j = 0;
	int sameN = 0;
	int nub = 0;

	if (PlayerNums + ComputerNums >= 1)
	{
		//行
		for (i = 0;i < row;i++)
		{
			nub = 0;
			sameN = 0;
			for (j = 0;j < col - 1;j++)
			{
				if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
				{
					++sameN;
					if (j == COL - 2)
					{
						WriteBackG(board, backG, i, j - sameN, (sameN + 1) * ((backG[i][j] == QC) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					}
					if (j != 0 && board[i][j - 1] != board[i][j] && board[i][j - 1] != ' ')
					{
						nub = 1;
					}
					else if (j == 0)
					{
						nub = 0;
					}
				}
				if (board[i][j] != board[i][j + 1] && board[i][j] != ' ')
				{

					WriteBackG(board, backG, i, j - (sameN + 1), ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					WriteBackG(board, backG, i, j + 1, ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));

					sameN = 0;
					nub = 0;
				}
				if (board[i][j] != board[i][j + 1] && board[i][j + 1] != ' ' && j == COL - 2)
				{
					WriteBackG(board, backG, i, j, (sameN + 1) * ((backG[i][j + 1] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (sameN >= NUM - 1)
					return backG[i][j];
			}
			sameN = 0;

		}
		//列
		for (i = 0;i < col;i++)
		{
			nub = 0;
			sameN = 0;
			for (j = 0;j < row - 1;j++)
			{
				
				if (board[j][i] == board[j + 1][i] && board[j][i] != ' ')
				{
					++sameN;
					if (j == ROW - 2)
					{
						WriteBackG(board, backG, j - sameN, i, (sameN + 1) * ((backG[j][i] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					}
					if (i != 0 && board[j][i - 1] != board[j][i] && board[j][i - 1] != ' ')
					{
						nub = 1;
					}
					else if(i == 0)
					{
						nub = 0;
					}
				}
				if (board[j][i] != board[j + 1][i] && board[j][i] != ' ')
				{

					WriteBackG(board, backG, j - (sameN + 1), i, ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[j][i] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					WriteBackG(board, backG, j + 1, i, ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[j][i] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (board[j][i] != board[j + 1][i] && board[j + 1][i] != ' ' && j == ROW - 2)
				{
					WriteBackG(board, backG, j, i, (sameN + 1) * ((backG[j + 1][i] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (sameN >= NUM - 1)
					return backG[j][i];
			}
			sameN = 0;

		}

		//右下斜角
		for (i = 0;i < ROW - 1;i++)
		{
			int ti = i;
			sameN = 0;

			for (j = 0;(j < COL - 1) && (i < ROW - 1);i++, j++)
			{
				
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
				{
					++sameN;
					if (i == ROW - 2)
					{
						WriteBackG(board, backG, i - sameN, j - sameN, (sameN + 1) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					}
					if (i != 0 && j != 0 &&board[i - 1][j - 1] != board[i][j] && board[i - 1][j - 1] != ' ')
					{
						nub = 1;
					}
					else if (i == 0 || j == 0)
					{
						nub = 0;
					}
				}
				if (board[i][j] != board[i + 1][j + 1] && board[i][j] != ' ')
				{
					WriteBackG(board, backG, i - (sameN + 1), j - (sameN + 1), ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					WriteBackG(board, backG, i + 1, j + 1, ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (board[i][j] != board[i + 1][j + 1] && board[i + 1][j + 1] != ' ' && ((j == COL - 2) || (i == ROW - 2)))
				{
					WriteBackG(board, backG, i , j , (sameN + 1) * ((backG[i + 1][j + 1] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (sameN >= NUM - 1)
					return backG[i][j];

			}
			sameN = 0;
			i = ti;
		}

		for (j = 1;j < COL - 1;j++)
		{
			int tj = j;
			sameN = 0;
			for (i = 0;(j < COL - 1) && (i < ROW - 1);i++, j++)
			{
				nub = backG[i][j];
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
				{
					++sameN;
					if (i == ROW - 2)
					{
						WriteBackG(board, backG, i - sameN, j - sameN, (sameN + 1)* ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					}
					if (i != 0 && j != 0 && board[i - 1][j - 1] != board[i][j] && board[i - 1][j - 1] != ' ')
					{
						nub = 1;
					}
					else if (i == 0 || j == 0)
					{
						nub = 0;
					}
				}
				if (board[i][j] != board[i + 1][j + 1] && board[i][j] != ' ')
				{
					WriteBackG(board, backG, i - (sameN + 1), j - (sameN + 1), ((nub != 1 ? 1 : 0) + (sameN + 1))* ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					WriteBackG(board, backG, i + 1, j + 1, ((nub != 1 ? 1 : 0) + (sameN + 1))* ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (board[i][j] != board[i + 1][j + 1] && board[i + 1][j + 1] != ' ' && ((j == COL - 2) || (i == ROW - 2)))
				{
					WriteBackG(board, backG, i, j, (sameN + 1) * ((backG[i + 1][j + 1] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (sameN >= NUM - 1)
					return backG[i][j];

			}
			sameN = 0;
			j = tj;
		}

		//左下斜角
		for (i = 0;i < ROW - 1;i++)
		{
			int ti = i;
			sameN = 0;
			for (j = COL - 1;(i < ROW - 1) && (j >= 1);i++, j--)
			{
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
				{
					++sameN;
					if (i == ROW - 2)
					{
						WriteBackG(board, backG, i - sameN, j + sameN, (sameN + 1) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					}
					if (i != 0 && j != COL - 1 && board[i - 1][j + 1] != board[i][j] && board[i - 1][j + 1] != ' ')
					{
						nub = 1;
					}
					else if (i == 0 || j == COL - 1)
					{
						nub = 0;
					}
				}
				if (board[i][j] != board[i + 1][j - 1] && board[i][j] != ' ')
				{
					WriteBackG(board, backG, i - (sameN + 1), j + (sameN + 1), ((nub != 1 ? 1 : 0) + (sameN + 1))* ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					WriteBackG(board, backG, i + 1, j - 1, ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (board[i][j] != board[i + 1][j - 1] && board[i + 1][j - 1] != ' ' && ((j == 1) || (i == ROW - 2)))
				{
					WriteBackG(board, backG, i, j, (sameN + 1) * ((backG[i + 1][j - 1] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (sameN >= NUM - 1)
					return backG[i][j];

			}
			sameN = 0;
			i = ti;
		}

		
		for (j = COL - 2;j >= 1;j--)
		{
			int tj = j;
			sameN = 0;
			for (i = 0 ;(i < ROW - 1) && (j >= 1);i++, j--)
			{
				nub = backG[i][j];
				if (backG[i][j] == backG[i + 1][j - 1] && board[i][j] != ' ')
				{
					++sameN;
					if (i == ROW - 2)
					{
						WriteBackG(board, backG, i - sameN, j + sameN, (sameN + 1) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					}
					if (i != 0 && j != COL - 1 && board[i - 1][j + 1] != board[i][j] && board[i - 1][j + 1] != ' ')
					{
						nub = 1;
					}
					else if (i == 0 || j == COL - 1)
					{
						nub = 0;
					}
				}
				if (backG[i][j] != backG[i + 1][j - 1] && board[i][j] != ' ')
				{
					WriteBackG(board, backG, i - (sameN + 1), j + (sameN + 1), ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					WriteBackG(board, backG, i + 1, j - 1, ((nub != 1 ? 1 : 0) + (sameN + 1)) * ((backG[i][j] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (board[i][j] != board[i + 1][j - 1] && board[i + 1][j - 1] != ' ' && ((j == 1) || (i == ROW - 2)))
				{
					WriteBackG(board, backG, i, j, (sameN + 1) * ((backG[i + 1][j - 1] == -1) ? ((sameN == 0) ? WC : WC + 1) : ((sameN == 0) ? WP : WP + 1)));
					sameN = 0;
					nub = 0;
				}
				if (sameN >= NUM - 1)
					return backG[i][j];

			}
			sameN = 0;
			j = tj;
		}

		//平局
		if (PlayerNums + ComputerNums == row * col)
			return Q;

		//继续
		return C;
	}
	else
		return C;
}

//int IsWinCp(char board[ROW][COL], int row, int col, int num, char b)
//{
//	int i = 0;
//	int j = 0;
//	int sameN = 0;
//
//
//		//行
//	for (i = 0;i < row;i++)
//	{
//		sameN = 0;
//		for (j = 0;j < col - 1;j++)
//		{
//			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
//				++sameN;
//			else
//				sameN = 0;
//			if (board[i][j] == b)
//			{
//				if (sameN >= NUM - 2 && board[i][j + 2] == ' ' && i < ROW && j + 2 < COL)
//				{
//					board[i][j + 2] = '#';
//					SaveComM(i, j + 2);
//					++ComputerNums;
//					return 1;
//				}
//				else if (sameN >= NUM - 3 && board[i][j + 3] == ' ' && i < ROW && j + 3 < COL)
//				{
//					board[i][j + 3] = '#';
//					SaveComM(i, j + 3);
//					++ComputerNums;
//					return 1;
//				}
//			}
//			
//
//		}
//		sameN = 0;
//
//	}
//	//列
//	for (i = 0;i < col;i++)
//	{
//		sameN = 0;
//		for (j = 0;j < row - 1;j++)
//		{
//			if (board[j][i] == board[j + 1][i] && board[j][i] != ' ')
//				++sameN;
//			else
//				sameN = 0;
//			if (board[i][j] == b)
//			{
//				if (sameN >= NUM - 2 && board[j + 2][i] == ' ' && j + 2 < ROW && i < COL)
//				{
//					board[j + 2][i] = '#';
//					SaveComM(j + 2, i);
//					++ComputerNums;
//					return 1;
//				}
//				else if (sameN >= NUM - 3 && board[j + 3][i] == ' ' && j + 3 < ROW && i < COL)
//				{
//					board[j + 3][i] = '#';
//					SaveComM(j + 3, i);
//					++ComputerNums;
//					return 1;
//				}
//			}
//			
//		}
//		sameN = 0;
//
//	}
//
//	//右下斜角
//	for (i = 0;i < row - NUM + 1;i++)
//	{
//		int ti = i;
//		sameN = 0;
//		for (j = 0;j < col - 1;i++, j++)
//		{
//			if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
//				++sameN;
//			else
//				sameN = 0;
//			if (board[i][j] == b)
//			{
//				if (sameN >= NUM - 2 && board[i + 2][j + 2] == ' ' && i + 2 < ROW && j + 2 < COL)
//				{
//					board[i + 2][j + 2] = '#';
//					SaveComM(i + 2 ,j + 2);
//					++ComputerNums;
//					return 1;
//				}
//				else if (sameN >= NUM - 3 && board[i + 3][j + 3] == ' ' && i + 3 < ROW && j + 3 < COL)
//				{
//					board[i + 3][j + 3] = '#';
//					SaveComM(i + 3, j + 3);
//					++ComputerNums;
//					return 1;
//				}
//			}
//
//		}
//		sameN = 0;
//		i = ti;
//	}
//
//	for (j = 0;j < col - NUM + 1;j++)
//	{
//		int tj = j;
//		sameN = 0;
//		for (i = 0;i < row - 1;i++, j++)
//		{
//			if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
//				++sameN;
//			else
//				sameN = 0;
//			if (board[i][j] == b)
//			{
//				if (sameN >= NUM - 2 && board[i + 2][j + 2] == ' ' && i + 2 < ROW && j + 2 < COL)
//				{
//					board[i + 2][j + 2] = '#';
//					SaveComM(i + 2, j + 2);
//					++ComputerNums;
//					return 1;
//				}
//				else if (sameN >= NUM - 3 && board[i + 3][j + 3] == ' ' && i + 3 < ROW && j + 3 < COL)
//				{
//					board[i + 3][j + 3] = '#';
//					SaveComM(i + 3, j + 3);
//					++ComputerNums;
//					return 1;
//				}
//			}
//			
//
//		}
//		sameN = 0;
//		j = tj;
//	}
//
//	//左下斜角
//	for (i = 0;i < row - NUM + 1;i++)
//	{
//		int ti = i;
//		sameN = 0;
//		for (j = col;i < row - 1;i++, j--)
//		{
//			if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
//				++sameN;
//			else
//				sameN = 0;
//			if (board[i][j] == b)
//			{
//				if (sameN >= NUM - 2 && board[i + 2][j - 2] == ' ' && i + 2 < ROW && j - 2 < COL)
//				{
//					board[i + 2][j - 2] = '#';
//					SaveComM(i + 2, j - 2);
//					++ComputerNums;
//					return 1;
//				}
//				else if (sameN >= NUM - 3 && board[i + 3][j - 3] == ' ' && i + 3 < ROW && j - 3 < COL)
//				{
//					board[i + 3][j - 3] = '#';
//					SaveComM(i + 3, j - 3);
//					++ComputerNums;
//					return 1;
//				}
//			}
//			
//
//		}
//		sameN = 0;
//		i = ti;
//	}
//
//	for (j = col - 1;j >= col - NUM;j--)
//	{
//		int tj = j;
//		sameN = 0;
//		for (i = 0; j >= 1;i++, j--)
//		{
//			if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
//				++sameN;
//			else
//				sameN = 0;
//			if (board[i][j] == b)
//			{
//				if (sameN >= NUM - 2 && board[i + 2][j - 2] == ' ' && i + 2 < ROW && j - 2 < COL)
//				{
//					board[i + 2][j - 2] = '#';
//					SaveComM(i + 2, j - 2);
//					++ComputerNums;
//					return 1;
//				}
//				else if (sameN >= NUM - 3 && board[i + 3][j - 3] == ' ' && i + 3 < ROW && j - 3 < COL)
//				{
//					board[i + 3][j - 3] = '#';
//					SaveComM(i + 3, j - 3);
//					++ComputerNums;
//					return 1;
//				}
//
//			}
//			
//		}
//		sameN = 0;
//		j = tj;
//	}
//	return 0;
//
//
//}

//mom 0大 1小
int IsWinCp(char board[ROW][COL], char backG[ROW][COL], char forseek[ROW][COL], int row, int col, int mom, char b, char lay)
{
	int max = 0, pmax = 0, tmax = 0;
	int max_i = 0, pmax_i = 0, tmax_i = 0;
	int max_j = 0, pmax_j = 0, tmax_j = 0;
	int min = 4, pmin = 4, tmin = 4;
	int min_i = 0, pmin_i = 0, tmin_i = 0;
	int min_j = 0, pmin_j = 0, tmin_j = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (backG[i][j] > pmax)
			{
				pmax_i = i;
				pmax_j = j;

				pmax = backG[i][j];

				forseek[lay][0] = pmax_i;
				forseek[lay][1] = pmax_j;
			}
			if (pmax > max)
			{
				tmax = max;
				max = pmax;
				pmax = tmax;

				tmax_i = max_i;
				max_i = pmax_i;
				pmax_i = tmax_i;

				tmax_j = max_j;
				max_j = pmax_j;
				pmax_j = tmax_j;

				forseek[lay][0] = pmax_i;
				forseek[lay][1] = pmax_j;

				forseek[lay - 1][0] = max_i;
				forseek[lay - 1][1] = max_j;

			}
			if (backG[i][j] < pmin && backG[i][j] != -1 && backG[i][j] != -2)
			{
				pmin_i = i;
				pmin_j = j;

				pmin = backG[i][j];

				forseek[lay + 1][0] = pmin_i;
				forseek[lay + 1][1] = pmin_j;
			}
			if (pmin < min)
			{
				tmin = min;
				min = pmin;
				pmin = tmin;

				tmin_i = min_i;
				min_i = pmin_i;
				pmin_i = tmin_i;

				tmin_j = min_j;
				min_j = pmin_j;
				pmin_j = tmin_j;

				forseek[lay + 1][0] = pmin_i;
				forseek[lay + 1][1] = pmin_j;

				forseek[lay + 2][0] = min_i;
				forseek[lay + 2][1] = min_j;

			}
		}


	}

	return (mom==0?max:min);
}

void ReNums()
{
	PlayerNums = 0;
	ComputerNums = 0;
}