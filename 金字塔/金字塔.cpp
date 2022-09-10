#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char num1, num2;
	int i, j, n = 1;
	printf("请输入一个字符和一个数字，将打印该字符的金字塔\n");
	scanf("%c %d", &num1, &num2);
	for (i = num2; i >= 1; i--) //打印金字塔
	{
		for (j = 1; j < i; j++) 
		{
			printf(" ");
		}

		for (int y = 1; y <= n * 2 - 1; y++)
		{
			printf("%c", num1);
		}
		n = n + 1;

		printf("\n");
	}

	return 0;
}