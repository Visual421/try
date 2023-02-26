#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#define ERROR 0
#define MAX_INIT_BOOKS 3
//设置主菜单功能枚举
enum Function {
	INSERT = 1,
	DELETED = 2,
	SEARCH = 3,
	MODIFY = 4,
	SAVE = 5,
	EXIT = 6
};

//设置状态枚举
enum Status {
	LETED = 0,		//被借出
	NOT_LETED = 1	//没被借出
};

//模拟boolean
enum Bool {
	WARRING = 0,
	RIGHT = 1
};

//搜索功能枚举
enum Select {
	searchByISBNNumber = 1,
	searchByBookName = 2,
	selectByAuthor = 3,
	selectByCategory = 4,
	selectByPress = 5,
	selectByStatus = 6,
	returnToMainMenu = 7
};

//结构体封装图书信息
struct Book {
	char isbnNumber[15];
	char bookName[20];
	char author[20];
	char category[20];
	char press[20];
	char date[13];
	enum Status ifLeted;
};
//结构体仿存图书信息的集合
struct List {
	struct Book* books; //存放图书
	int number;			//图书数量
	int capacity;		//容量,用于检测shi否需要扩容
};
// 选择处理
int selectBetter();

//声明菜单函数
void mainMenu();
void searchMenu();

//选择声明
void mainSelect(struct List* list);

//声明错误函数
void notSuchSelect();

//声明功能函数
void insert(struct List* list);

//模拟集合函数
void initList(struct List* list);


//信息载入
void initInfo(struct List* list);

//功能声明
//添加
void insert(struct List* list);
//保存
void saveBooksInfo(struct List* list);
//搜索
//ISBN搜索
void searchByISBN(struct List* list);