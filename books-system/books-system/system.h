#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#define ERROR 0
#define MAX_INIT_BOOKS 3
//�������˵�����ö��
enum Function {
	INSERT = 1,
	DELETED = 2,
	SEARCH = 3,
	MODIFY = 4,
	SAVE = 5,
	EXIT = 6
};

//����״̬ö��
enum Status {
	LETED = 0,		//�����
	NOT_LETED = 1	//û�����
};

//ģ��boolean
enum Bool {
	WARRING = 0,
	RIGHT = 1
};

//��������ö��
enum Select {
	searchByISBNNumber = 1,
	searchByBookName = 2,
	selectByAuthor = 3,
	selectByCategory = 4,
	selectByPress = 5,
	selectByStatus = 6,
	returnToMainMenu = 7
};

//�ṹ���װͼ����Ϣ
struct Book {
	char isbnNumber[15];
	char bookName[20];
	char author[20];
	char category[20];
	char press[20];
	char date[13];
	enum Status ifLeted;
};
//�ṹ��´�ͼ����Ϣ�ļ���
struct List {
	struct Book* books; //���ͼ��
	int number;			//ͼ������
	int capacity;		//����,���ڼ��shi����Ҫ����
};
// ѡ����
int selectBetter();

//�����˵�����
void mainMenu();
void searchMenu();

//ѡ������
void mainSelect(struct List* list);

//����������
void notSuchSelect();

//�������ܺ���
void insert(struct List* list);

//ģ�⼯�Ϻ���
void initList(struct List* list);


//��Ϣ����
void initInfo(struct List* list);

//��������
//���
void insert(struct List* list);
//����
void saveBooksInfo(struct List* list);
//����
//ISBN����
void searchByISBN(struct List* list);