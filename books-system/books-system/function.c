#include"system.h"

//ѡ�����
void notSuchSelect(){
	system("cls");
	system("color 4");
	printf("����ʧ�ܣ������Ƿ�Ϊ��Ϣ��������޸�ѡ��,����3�������ѡ��\n");
	Sleep(3000);
}

//ISBN�ظ�����
static void repeatISBN() {
	system("cls");
	system("color 4");
	printf("ISBN�ظ�������3���������������\n");
	Sleep(3000);
}

//�Ҳ�����Ϣ����
static void notSuchInfo() {
	system("cls");
	system("color 4");
	printf("��Ϣ��������3������������������ʹ��������ʽ����!\n");
	Sleep(3000);
}

//��ӡͼ����ϢĿ¼
static void printTotal() {
	printf("+---------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("---");
	printf("------");//�ո�
	printf("------+\n");
	printf("|%-15s %-20s %-20s %-20s %-20s %-3s %-6s|\n", "ISBN����","����","����","���","������","��������","�Ƿ񱻽��");
	printf("+---------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("---");
	printf("------");//�ո�
	printf("------+\n");
}

//�����±��ӡͼ����Ϣ
void printInfo(struct List* list,int index) {
	printf("|%-15s %-20s %-20s %-20s %-20s %-3s ", list->books[index], list->books[index].bookName, list->books[index].author, list->books[index].category, list->books[index].press, list->books[index].date);
	if (list->books[index].ifLeted) {
		printf("δ���|\n");
	}
	else {
		printf("���|\n");
	}
	printf("+---------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("---");
	printf("------");//�ո�
	printf("------+\n");
}

//��������
static enum Bool listAmplification(struct List* list) {
	struct Book* ptr = realloc(list->books, (list->capacity + 4) * sizeof(struct Book));
	if (ptr != NULL) {
		list->books = ptr;
		list->capacity += 4;
		return RIGHT;
	}
	else {
		return WARRING;
	}
}

//����ISBN��ѯ�±�
int isbnSearch(struct List* list, char isbnNumber[]) {
	for (int i = 0; i < list->number; i++) {
		if ((strcmp(isbnNumber, list->books[i].isbnNumber)) == 0) {
			return i;//�ҵ���Ӧ��ISBN
		}
	}
	return -1;
}

//ISBN����
void searchByISBN(struct List* list) {
	system("cls");
	char isbn[15];
	int result;
	while (1) {
		printf("������ͼ���ISBN���룺");
		scanf("%s", isbn);
		result = isbnSearch(list, isbn);
		if (result == -1) {
			notSuchInfo();
		star:
			system("cls");
			printf("�Ƿ����[��(1)/��(0)]\n");
			int select = selectBetter();
			if (select == 0) {
				return;
			}
			else if (select == 1) {
				continue;
			}
			else {
				notSuchSelect();
				goto star;
			}
		}
		break;
	}
	printTotal();
	printInfo(list, result);
}

//�ж��Ƿ��Ѿ�����
enum Bool ifFull(struct List* list) {
	if (list->capacity == list->number) {
		enum Bool full = listAmplification(list);
		if (!full) {
			//�ڴ���������ʧ��
			printf("�ڴ�����\n");
			return RIGHT;
		}
	}
	//���ݳɹ�����δ��
	return WARRING; 
}

//����
//1.��ʼ����Ϣ
void initInfo(struct List* list) {
	struct Book book = { 0 };
	FILE* fileRead = fopen("booksInfo.dat", "rb");
	if (fileRead == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	//��ȡ�ļ��е�ͼ����Ϣ
	while (fread(&book, sizeof(struct Book), 1, fileRead)) {
		enum Bool bool = ifFull(list);
		if (bool == RIGHT) {
			printf("�ڴ����ˣ��޷�¼�룡");
			return;
		}
		list->books[list->number] = book;
		list->number++;
	}
	fclose(fileRead);
	fileRead = NULL;
}

//ģ�⼯�ϴ��ͼ��
void initList(struct List* list) {
	list->books = (struct Book*)malloc(MAX_INIT_BOOKS * sizeof(struct Book));
	if (list->books == NULL) {
		return;
	}
	list->number = 0;
	list->capacity = MAX_INIT_BOOKS;
	initInfo(list);
}

//��Ϣ¼��
void insert(struct List* list) {
	system("cls");
	char isbnNumber[15];
	char bookName[20];
	char author[20];
	char category[20];
	char press[20];
	char date[13];
	enum Status ifLeted;
	//����ռ��Ƿ��Ѿ�����
	enum Bool bool = ifFull(list);
	if (bool) {
		//�ռ�����
		printf("�޷�¼��!\n");
		return;
	}
	//���
	while (1) {
		printf("������ͼ���ISBN��ţ�");
		scanf("%s", isbnNumber);
		int index = isbnSearch(list, isbnNumber);
		if (index == -1) {
			 //û�ҵ������ISBN�����ظ�
			break;
		}
		repeatISBN();
	}
	printf("������ͼ���������");
	scanf("%s", bookName);
	printf("������ͼ������ߣ�");
	scanf("%s", author);
	printf("������ͼ������");
	scanf("%s", category);
	printf("������ͼ��ĳ����磺");
	scanf("%s", press);
	printf("������ͼ��ĳ������ڣ�");
	scanf("%s", date);
	strcpy(list->books[list->number].isbnNumber, isbnNumber);
	strcpy(list->books[list->number].bookName, bookName);
	strcpy(list->books[list->number].author, author);
	strcpy(list->books[list->number].category, category);
	strcpy(list->books[list->number].press, press);
	strcpy(list->books[list->number].date, date);
	list->books[list->number].ifLeted = WARRING;
	list->number++;
	printf("ͼ����Ϣ��ӳɹ���\n");
	printf("3��󷵻���ҳ��");
	Sleep(3000);
}

//ͼ����Ϣ����
void saveBooksInfo(struct List* list) {
	FILE* fileWrite = fopen("booksInfo.dat", "wb");
	if (fileWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	int i;
	for (i = 0; i < list->number; i++)
	{
		fwrite(&(list->books[i]), sizeof(struct Book), 1, fileWrite);
	}
	fclose(fileWrite);
	fileWrite = NULL;
}