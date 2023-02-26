#include"system.h"

//选择错误
void notSuchSelect(){
	system("cls");
	system("color 4");
	printf("操作失败，请检查是否为信息错误或者无该选项,并于3秒后重新选择！\n");
	Sleep(3000);
}

//ISBN重复错误
static void repeatISBN() {
	system("cls");
	system("color 4");
	printf("ISBN重复，请于3秒后输入重新输入\n");
	Sleep(3000);
}

//找不到信息错误
static void notSuchInfo() {
	system("cls");
	system("color 4");
	printf("信息错误，请于3秒后输入重新输入或者使用其他方式操作!\n");
	Sleep(3000);
}

//打印图书信息目录
static void printTotal() {
	printf("+---------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("---");
	printf("------");//空格
	printf("------+\n");
	printf("|%-15s %-20s %-20s %-20s %-20s %-3s %-6s|\n", "ISBN编码","书名","作者","类别","出版社","出版日期","是否被借出");
	printf("+---------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("---");
	printf("------");//空格
	printf("------+\n");
}

//根据下标打印图书信息
void printInfo(struct List* list,int index) {
	printf("|%-15s %-20s %-20s %-20s %-20s %-3s ", list->books[index], list->books[index].bookName, list->books[index].author, list->books[index].category, list->books[index].press, list->books[index].date);
	if (list->books[index].ifLeted) {
		printf("未借出|\n");
	}
	else {
		printf("借出|\n");
	}
	printf("+---------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("--------------------");
	printf("---");
	printf("------");//空格
	printf("------+\n");
}

//集合增容
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

//根据ISBN查询下标
int isbnSearch(struct List* list, char isbnNumber[]) {
	for (int i = 0; i < list->number; i++) {
		if ((strcmp(isbnNumber, list->books[i].isbnNumber)) == 0) {
			return i;//找到对应的ISBN
		}
	}
	return -1;
}

//ISBN搜索
void searchByISBN(struct List* list) {
	system("cls");
	char isbn[15];
	int result;
	while (1) {
		printf("请输入图书的ISBN编码：");
		scanf("%s", isbn);
		result = isbnSearch(list, isbn);
		if (result == -1) {
			notSuchInfo();
		star:
			system("cls");
			printf("是否继续[是(1)/否(0)]\n");
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

//判断是否已经满了
enum Bool ifFull(struct List* list) {
	if (list->capacity == list->number) {
		enum Bool full = listAmplification(list);
		if (!full) {
			//内存满，扩容失败
			printf("内存已满\n");
			return RIGHT;
		}
	}
	//扩容成功或者未满
	return WARRING; 
}

//搜索
//1.初始化信息
void initInfo(struct List* list) {
	struct Book book = { 0 };
	FILE* fileRead = fopen("booksInfo.dat", "rb");
	if (fileRead == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	//读取文件中的图书信息
	while (fread(&book, sizeof(struct Book), 1, fileRead)) {
		enum Bool bool = ifFull(list);
		if (bool == RIGHT) {
			printf("内存满了，无法录入！");
			return;
		}
		list->books[list->number] = book;
		list->number++;
	}
	fclose(fileRead);
	fileRead = NULL;
}

//模拟集合存放图书
void initList(struct List* list) {
	list->books = (struct Book*)malloc(MAX_INIT_BOOKS * sizeof(struct Book));
	if (list->books == NULL) {
		return;
	}
	list->number = 0;
	list->capacity = MAX_INIT_BOOKS;
	initInfo(list);
}

//信息录入
void insert(struct List* list) {
	system("cls");
	char isbnNumber[15];
	char bookName[20];
	char author[20];
	char category[20];
	char press[20];
	char date[13];
	enum Status ifLeted;
	//检验空间是否已经满了
	enum Bool bool = ifFull(list);
	if (bool) {
		//空间满了
		printf("无法录入!\n");
		return;
	}
	//添加
	while (1) {
		printf("请输入图书的ISBN编号：");
		scanf("%s", isbnNumber);
		int index = isbnSearch(list, isbnNumber);
		if (index == -1) {
			 //没找到输入的ISBN，不重复
			break;
		}
		repeatISBN();
	}
	printf("请输入图书的书名：");
	scanf("%s", bookName);
	printf("请输入图书的作者：");
	scanf("%s", author);
	printf("请输入图书的类别：");
	scanf("%s", category);
	printf("请输入图书的出版社：");
	scanf("%s", press);
	printf("请输入图书的出版日期：");
	scanf("%s", date);
	strcpy(list->books[list->number].isbnNumber, isbnNumber);
	strcpy(list->books[list->number].bookName, bookName);
	strcpy(list->books[list->number].author, author);
	strcpy(list->books[list->number].category, category);
	strcpy(list->books[list->number].press, press);
	strcpy(list->books[list->number].date, date);
	list->books[list->number].ifLeted = WARRING;
	list->number++;
	printf("图书信息添加成功！\n");
	printf("3秒后返回主页面");
	Sleep(3000);
}

//图书信息保存
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