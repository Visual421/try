#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<Windows.h>
char* copy(char* Ch1, const char* Ch2)//��֤Ch2��Ч��
{
	assert(Ch1 != NULL);//����
	assert(Ch1 != NULL);//����
	while (*Ch1++ = *Ch2++)//��Ch2������Ch1
	{
		;
	}
}
int main()
{
	char ch1[10], ch2[5];
	printf("����һ��������10��һ��2������5���ַ���\n");
	scanf("%s%s",ch1,ch2);
	copy(ch1, ch2);
	printf("%s", ch1);//����������ch1
	return 0;
}