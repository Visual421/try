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
	struct Contact con;//con����ͨѶ¼���������dataָ���size��capacity
	InitContact(&con);//��ʼ��ͨѶ¼
	int input;
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳�ͨѶ¼\n");
			SaveContact(&con);
			DestoryContact(&con);//����ͨѶ¼
			break;
		default:
			printf("û�и�ָ�����������:\n>");
			break;
		}
	} while (input);
	return 0;
}