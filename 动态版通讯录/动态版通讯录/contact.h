#define _CRT_SECURE_NO_WARNINGS
//#define MAX 1000//�������
#define MAX_NAME 20//����
#define MAX_SEX 5//�Ա�
#define MAX_TELE 12//�绰
#define MAX_ADDR 30//סַ
#define DEFAULT_SZ 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum Option//���ӿɶ���
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
struct PeoInfo//�û���Ϣ
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//ͨѶ¼����
struct Contact
{
	struct PeoInfo *data;//���1000����Ϣ
	int size;//��¼��ǰ���е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼���������
};
//��������
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(const struct Contact* ps);
void SortContact(const struct Contact* ps);
DestoryContact(&con);