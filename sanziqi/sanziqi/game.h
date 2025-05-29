#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
#define NUM 3
#define Q -3
#define C -4
#define QP -2
#define QC -1
#define WC -2
#define WP 3
#define DP 1


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//初始化权盘
void InitBackG(char backG[ROW][COL], int row, int col);
//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//显示权盘
void DisplayBackG(char backG[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], char backG[ROW][COL], char forseek[ROW][COL], int row, int col);
//判断输赢 玩家赢：*，电脑赢：#，平局：Q，继续：C
char IsWin(char board[ROW][COL], char backG[ROW][COL], int row, int col, int num);
//加载棋盘到权盘
void LoadToBackG(char board[ROW][COL], char backG[ROW][COL], int row, int col);
//写入权重
int WriteBackG(char board[ROW][COL], char backG[ROW][COL], int row, int col, int dest);

void ReNums();

int IsWinCp(char board[ROW][COL], char backG[ROW][COL], char forseek[ROW][COL], int row, int col, int num, char b, char lay);

void SaveComM(int x, int y);

int ComNear(char board[ROW][COL], int row, int col);






