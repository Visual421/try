#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
void menu()
{
	printf(">>>>>><<<<<<\n");
	printf(">>>五子棋<<<\n");
	printf(">>>>>><<<<<<\n");
}
void game()
{
	int num2 = 0, num3 = 0;
	char board[row][col] = { 0 };
	Board(board, row, col);
	picture(board, row, col);
	while (1)
	{
		play(board, row, col);
		picture(board, row, col);
		num2 = ifwin(board, row, col);
		if (num2 != 2)
		{
			break;
		}
		system("cls");
		computerplay(board, row, col);
		picture(board, row, col);
		num3=ifwin(board, row, col);
		if (num3 != 2)
		{
			break;
		}
	}
	if (num2 == 1) printf("玩家赢");
	else if (num3 == 1) printf("电脑赢");
	else printf("平局");
}	
	

void test()
{
	srand((unsigned int) time NULL);
	int num1=0;
	do {
		menu();
		printf("请输入（1为开始，0为结束）:>");
		scanf("%d", &num1);
		switch (num1) 
		{
			case 1:
				printf("开始\n");
				game();
				break;
			case 0:
				printf("退出");
				break;
			default:
				printf("出错，请重新输入");
				break;
		
		}
			
	   }
	while (num1==1);
}
int main() 
{
	system("color F4");
	test();
	return 0;
}