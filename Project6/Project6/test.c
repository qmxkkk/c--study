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
    // ���ƶ����߿�
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

    // �������̺͵ײ��߿�
    for (int i = BOARD_SIZE - 1; i >= 0; --i) {
        // ���ƶ���������
        if (i < BOARD_SIZE - 1) {
            putchar('|');
        }

        // ����������
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '\0') {
                putchar(' ');
            }
            else {
                putchar(board[i][j]);
            }
        }

        // ����������һ�У����Ƶײ������ߺͻ��з�
        if (i > 0) {
            putchar('|');
            printf("\n");
        }
        else {
            printf("\n\n");
        }
    }

    // ���Ƶײ��߿�
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
    // ���ˮƽ����
    if (board[x][y] != '\0' && board[x][y - 4] == board[x][y] &&
        board[x][y - 3] == board[x][y] && board[x][y - 2] == board[x][y] &&
        board[x][y - 1] == board[x][y]) {
        return;
    }

    // ��鴹ֱ����
    if (board[x][y] != '\0' && board[x - 4][y] == board[x][y] &&
        board[x - 3][y] == board[x][y] && board[x - 2][y] == board[x][y] &&
        board[x - 1][y] == board[x][y]) {
        return;
    }

    // ���Խ��߷������ϵ����£�
    if (board[x][y] != '\0' && board[x - 4][y - 4] == board[x][y] &&
        board[x - 3][y - 3] == board[x][y] && board[x - 2][y - 2] == board[x][y] &&
        board[x - 1][y - 1] == board[x][y]) {
        return;
    }

    // ���Խ��߷������ϵ����£�
    if (board[x][y] != '\0' && board[x - 4][y + 4] == board[x][y] &&
        board[x - 3][y + 3] == board[x][y] && board[x - 2][y + 2] == board[x][y] &&
        board[x - 1][y + 1] == board[x][y]) {
        return;
    }

    // ���û�������壬�򷵻�false
    printf("û���˻�ʤ��\n");
}

void computerMove() {
    // �ҵ���һ�����е�λ�ò���������
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
    // ��ʼ������
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

        printf("��� %c ��������Ҫ�������ӵ����꣨���磺A1��:");
        scanf("%s", &x);

        // ת������Ϊ��������
        if (x == "a") {
            x = 0;
        }
        else if (x == "b") {
            x = 1;
        }

        y = atoi(x) - 1;

        if (y < 0 || y >= BOARD_SIZE || board[x][y] != '\0') {
            printf("��Ч���ƶ������������롣\n");
            continue;
        }

        // ��������
        board[x][y] = players[currentPlayer];

        currentPlayer++;

        // ����Ƿ����˻�ʤ
        checkWin(x, y);
    }
}