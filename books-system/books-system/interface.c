#include"system.h"
//主菜单
void mainMenu() {
	system("color 7");
	system("cls");
	printf("+--------------------------------+\n");
	printf("|      欢迎来到图书管理系统      |\n");
	printf("|  (输入相应编号可执行相应功能)	 |\n");
	printf("|            主菜单	         |\n");
	printf("|        1.图书信息录入		 |\n");
	printf("|        2.图书信息删除		 |\n");
	printf("|        3.图书信息查询		 |\n");
	printf("|        4.图书信息修改		 |\n");
	printf("|        5.图书信息保存		 |\n");
	printf("|        6.保存推出系统		 |\n");
	printf("+--------------------------------+\n");
}
//搜索菜单
void searchMenu() {
	system("color 7");
	system("cls");
	printf("+--------------------------------+\n");
	printf("|            搜  索	         |\n");
	printf("|        1.图书ISBN搜索		 |\n");
	printf("|        2.图书名字搜索		 |\n");
	printf("|        3.图书作者搜索		 |\n");
	printf("|        4.图书类别搜索		 |\n");
	printf("|        5.据出版社搜索		 |\n");
	printf("|        6.图书状态搜索		 |\n");
	printf("|        7.返回到主菜单		 |\n");
	printf("+--------------------------------+\n");
}