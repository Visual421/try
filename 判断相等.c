#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
int main()
{
	char num1[10], num3[] = "czf0421",num4[]="#######";//����һ���ַ��ܿ��Ƿ����
	int num2, i, left = 0, right = strlen(num3) - 1;
	printf("#######\n����������czf0421\n");
	
	while (1)
	{	scanf("%s", num1);
		if (strcmp(num1, "czf0421") == 0)
		{
			printf("��ȷ");
			while (left <= right) {
				if (strcmp(num1, "czf0421") == 0) {
					system("cls");
					num4[left] = num3[left];
					num4[right] = num3[right];
					system("color B");
					printf("%s", num4);//��ӡ
					Sleep(1000);//��Ϣһ��
					left += 1;
					right -= 1;
				}
			}
			break;
		}
		else
		{
			printf("����,���ٴ�����\n");
		}
	}
	return 0;
}