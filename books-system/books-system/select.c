#include"system.h"
//ѡ����
int selectBetter() {
	char selectStr[100];
	int select;
	printf("����������ѡ��:\n");
	scanf("%s", selectStr);
	select = atoi(selectStr);
	return select;
}

//���˵�ѡ��
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
			printf("����ɹ�");
			break;
		case EXIT:
			printf("��л����ʹ�ã���ӭ�´�ʹ�ã�");
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

//�����˵�
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