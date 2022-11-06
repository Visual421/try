#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include<stdio.h>
#include<string.h>
static CheckCapacity(struct Contact* ps)
{
	if (ps->size ==ps->capacity)
	{
		//����
		struct PeoInfo* ptr=realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�");
		}
		else
		{
			printf("����ʧ��,ԭ��Ϊ��",strerror(errno));		
		}
	}
}
static int cmp_int(const void* e1, const void* e2)
{
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}
static int FindByName(const struct Contact* ps, char name[MAX_NAME])//staticʹ�øú���ֻ���ڸ��ļ��ļ���ʹ��
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}
//��ʼ��ʵ��
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}

void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);//��⵱ǰͨѶ¼����
	if(CheckCapacity)
	/*if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else*/
	//{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	//}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼������\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t %-4s\t %-5s\t %-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t %-4d\t %-5s\t %-12s\t %-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	//����Ҫɾ������λ��
	scanf("%s", name);
	int pos = FindByName(ps, name);//�ҵ������±��Ҳ�������-1
	//ɾ��
	//����ǰ����
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ��ѯ����");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("�Ҳ�������");
	}
	else
	{
		printf("%-20s\t %-4s\t %-5s\t %-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t %-4d\t %-5s\t %-12s\t %-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}
void ModifyContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸��˵���Ϣ������");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ�\n");
}
}
void SortContact(const struct Contact* ps)
{
	int i;
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_int);
	printf("%-20s\t %-4s\t %-5s\t %-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t %-4d\t %-5s\t %-12s\t %-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}
