#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
int main()
{
	char num1[10], num3[] = "czf0421",num4[]="#######";//输入一个字符窜看是否相等
	int num2, i, left = 0, right = strlen(num3) - 1;
	printf("#######\n请输入密码czf0421\n");
	
	while (1)
	{	scanf("%s", num1);
		if (strcmp(num1, "czf0421") == 0)
		{
			printf("正确");
			while (left <= right) {
				if (strcmp(num1, "czf0421") == 0) {
					system("cls");
					num4[left] = num3[left];
					num4[right] = num3[right];
					system("color B");
					printf("%s", num4);//打印
					Sleep(1000);//休息一秒
					left += 1;
					right -= 1;
				}
			}
			break;
		}
		else
		{
			printf("错误,请再次输入\n");
		}
	}
	return 0;
}