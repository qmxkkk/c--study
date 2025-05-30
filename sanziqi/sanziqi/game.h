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


//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ʼ��Ȩ��
void InitBackG(char backG[ROW][COL], int row, int col);
//��ʾ����
void DisplayBoard(char board[ROW][COL], int row, int col);
//��ʾȨ��
void DisplayBackG(char backG[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], char backG[ROW][COL], char forseek[ROW][COL], int row, int col);
//�ж���Ӯ ���Ӯ��*������Ӯ��#��ƽ�֣�Q��������C
char IsWin(char board[ROW][COL], char backG[ROW][COL], int row, int col, int num);
//�������̵�Ȩ��
void LoadToBackG(char board[ROW][COL], char backG[ROW][COL], int row, int col);
//д��Ȩ��
int WriteBackG(char board[ROW][COL], char backG[ROW][COL], int row, int col, int dest);

void ReNums();

int IsWinCp(char board[ROW][COL], char backG[ROW][COL], char forseek[ROW][COL], int row, int col, int num, char b, char lay);

void SaveComM(int x, int y);

int ComNear(char board[ROW][COL], int row, int col);






