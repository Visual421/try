#include"system.h"
//选择处理
int selectBetter() {
	char selectStr[100];
	int select;
	printf("请输入您的选择:\n");
	scanf("%s", selectStr);
	select = atoi(selectStr);
	return select;
}

//主菜单选择
void mainSelect(struct List* list) {
	enum Function function;
	while (1) {
		mainMenu();
		int select = selectBetter();
		switch (select) {
		case INSERT:
			insert(list);
			break;
		case DELETED:
			//deleted();
			break;
		case SEARCH:
			search(list);
			break;
		case MODIFY:
			//modify();
			break;
		case SAVE:
			saveBooksInfo(&list);
			printf("保存成功");
			break;
		case EXIT:
			printf("感谢您的使用，欢迎下次使用！");
			saveBooksInfo(&list);
			return 0;
			break;
		case ERROR:
		default:
			notSuchSelect();
			break;
		}
	}
}

//搜索菜单
void search(struct List* list) {
	enum Select search;
	while (1) {
		system("cls");
		mainMenu();
		int select = selectBetter();
		switch (select) {
		case searchByISBNNumber:
			searchByISBN(list);
			break;
		case 
			break;
		case 
			break;
		case 
			break;
		case 
			break;
		case 
			break;
		case returnToMainMenu:
			return;
			break;
		case ERROR:
		default:
			notSuchSelect();
			break;
		}
	}
}