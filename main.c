#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
void menu()
{
	printf(">>>>>><<<<<<\n");
	printf(">>>������<<<\n");
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
	if (num2 == 1) printf("���Ӯ");
	else if (num3 == 1) printf("����Ӯ");
	else printf("ƽ��");
}	
	

void test()
{
	srand((unsigned int) time NULL);
	int num1=0;
	do {
		menu();
		printf("�����루1Ϊ��ʼ��0Ϊ������:>");
		scanf("%d", &num1);
		switch (num1) 
		{
			case 1:
				printf("��ʼ\n");
				game();
				break;
			case 0:
				printf("�˳�");
				break;
			default:
				printf("��������������");
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