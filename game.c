#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
void Board(char board[row][col], int ROW, int COL)
{
	int i, j;
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j <= col; j++) 
		{
			board[i][j] = ' ';
		}
	}
}
void picture(char board[row][col], int ROW, int COL)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		} 
		printf("\n");
		if (i < col - 1) {
			for (j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void play(char board[row][col], int ROW, int COL)
{
	while (1)
	{
		printf("请输入坐标:");
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; 
			}
			else
			{
				printf("请重新输入:\n");
				continue;
			}
			break;
		}
		else
		{
			printf("请重新输入:\n");
			continue;
		}
		break;
	}
}
void computerplay(char board[row][col], int ROW, int COL)
{
	int x = rand()%row;
	int y = rand()%col;
	while (1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int ifwin(char board[row][col], int ROW, int COL)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 4; j++)
		{
			if (board[i][j] == board[i][j+1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4] && board[i][j] != ' ')
			{
				return 1;
			}
			if (i < row - 4)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j] != ' ')
				{
					return 1;
				}
			}
		}
	}//行及斜右下搜索
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row-4; i++)
		{
			if (board[i][j] == board[i+ 1][j ] && board[i + 1][j] == board[i + 2][j] && board[i+ 2][j ] == board[i + 3][j] && board[i+ 3][j ] == board[i + 4][j] && board[i][j] != ' ')
			{
				return 1;
			}
			if (j < col - 4)
			{
				if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3] && board[i - 3][j + 3] == board[i - 4][j + 4] && board[i][j] != ' ')
				{
					return 1;
				}
			}
		}
	}//列及斜左下判断
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 2;
			}
		}
	}
	return 3;//3为平局
}

