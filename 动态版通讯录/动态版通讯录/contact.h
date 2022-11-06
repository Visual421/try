#define _CRT_SECURE_NO_WARNINGS
//#define MAX 1000//存的人数
#define MAX_NAME 20//名字
#define MAX_SEX 5//性别
#define MAX_TELE 12//电话
#define MAX_ADDR 30//住址
#define DEFAULT_SZ 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum Option//增加可读性
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
struct PeoInfo//用户信息
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
struct Contact
{
	struct PeoInfo *data;//存放1000个信息
	int size;//记录当前已有的元素个数
	int capacity;//当前通讯录的最大容量
};
//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(const struct Contact* ps);
void SortContact(const struct Contact* ps);
DestoryContact(&con);