#include"system.h"
int main() {
	//初始化集合，建集合并将数据读入集合中
	struct List list;
	initList(&list);
	mainSelect(&list);
	return 0;
}