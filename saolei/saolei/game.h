#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 9
#define COL 9
#define EASY_COUNT 10


#define ROWS ROW+2
#define COLS COL+2



void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROW][COL], int row, int col);
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_count(char board[ROWS][COLS], int x, int y);
int unfordMap(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int lastcot);
