#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BOARD_SIZE 15

char board[BOARD_SIZE][BOARD_SIZE];
int currentPlayer = 0;
const char players[] = { 'X', 'O' };

void drawBoard() {
    printf("\n");
    // 绘制顶部边框
    for (int i = 0; i < BOARD_SIZE * 2 + 1; ++i) {
        if (i == 0 || i == BOARD_SIZE * 2) {
            putchar('-');
        }
        else if (i % 2 == 1) {
            putchar(' ');
        }
        else {
            putchar('|');
        }
    }
    printf("\n");

    // 绘制棋盘和底部边框
    for (int i = BOARD_SIZE - 1; i >= 0; --i) {
        // 绘制顶部网格线
        if (i < BOARD_SIZE - 1) {
            putchar('|');
        }

        // 绘制棋盘行
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '\0') {
                putchar(' ');
            }
            else {
                putchar(board[i][j]);
            }
        }

        // 如果不是最后一行，绘制底部网格线和换行符
        if (i > 0) {
            putchar('|');
            printf("\n");
        }
        else {
            printf("\n\n");
        }
    }

    // 绘制底部边框
    for (int i = 0; i < BOARD_SIZE * 2 + 1; ++i) {
        if (i == 0 || i == BOARD_SIZE * 2) {
            putchar('-');
        }
        else if (i % 2 == 1) {
            putchar(' ');
        }
        else {
            putchar('|');
        }
    }
}

void checkWin(int x, int y) {
    // 检查水平方向
    if (board[x][y] != '\0' && board[x][y - 4] == board[x][y] &&
        board[x][y - 3] == board[x][y] && board[x][y - 2] == board[x][y] &&
        board[x][y - 1] == board[x][y]) {
        return;
    }

    // 检查垂直方向
    if (board[x][y] != '\0' && board[x - 4][y] == board[x][y] &&
        board[x - 3][y] == board[x][y] && board[x - 2][y] == board[x][y] &&
        board[x - 1][y] == board[x][y]) {
        return;
    }

    // 检查对角线方向（左上到右下）
    if (board[x][y] != '\0' && board[x - 4][y - 4] == board[x][y] &&
        board[x - 3][y - 3] == board[x][y] && board[x - 2][y - 2] == board[x][y] &&
        board[x - 1][y - 1] == board[x][y]) {
        return;
    }

    // 检查对角线方向（右上到左下）
    if (board[x][y] != '\0' && board[x - 4][y + 4] == board[x][y] &&
        board[x - 3][y + 3] == board[x][y] && board[x - 2][y + 2] == board[x][y] &&
        board[x - 1][y + 1] == board[x][y]) {
        return;
    }

    // 如果没有五连棋，则返回false
    printf("没有人获胜！\n");
}

void computerMove() {
    // 找到第一个空闲的位置并放置棋子
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '\0') {
                board[i][j] = players[currentPlayer];
                return;
            }
        }
    }
}

void main() {
    // 初始化棋盘
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '\0';
        }
    }

    while (1) {
        drawBoard();

        if (currentPlayer == 1) {
            computerMove();
            currentPlayer--;
            continue;
        }

        int x, y;

        printf("玩家 %c 请输入您要放置棋子的坐标（例如：A1）:");
        scanf("%s", &x);

        // 转换输入为数组索引
        if (x == "a") {
            x = 0;
        }
        else if (x == "b") {
            x = 1;
        }

        y = atoi(x) - 1;

        if (y < 0 || y >= BOARD_SIZE || board[x][y] != '\0') {
            printf("无效的移动！请重新输入。\n");
            continue;
        }

        // 放置棋子
        board[x][y] = players[currentPlayer];

        currentPlayer++;

        // 检查是否有人获胜
        checkWin(x, y);
    }
}