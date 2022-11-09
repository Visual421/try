#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include<stdio.h>
#include<string.h>
void menu()
{
	printf("******************************************\n");
	printf("******1.add               2.del    *******\n");
	printf("******3.search            4.modify *******\n");
	printf("******5.show              6.sort   *******\n");
	printf("******7.save              0.exit   *******\n");
	printf("******************************************\n");
}
int main()
{
	struct Contact con;//con就是通讯录，里面包含data指针和size和capacity
	InitContact(&con);//初始化通讯录
	int input;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			SaveContact(&con);
			DestoryContact(&con);//销毁通讯录
			break;
		default:
			printf("没有该指令，请重新输入:\n>");
			break;
		}
	} while (input);
	return 0;
}