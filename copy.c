#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<Windows.h>
char* copy(char* Ch1, const char* Ch2)//保证Ch2有效性
{
	assert(Ch1 != NULL);//断言
	assert(Ch1 != NULL);//断言
	while (*Ch1++ = *Ch2++)//把Ch2拷贝到Ch1
	{
		;
	}
}
int main()
{
	char ch1[10], ch2[5];
	printf("输入一串不长于10，一串2不长于5的字符串\n");
	scanf("%s%s",ch1,ch2);
	copy(ch1, ch2);
	printf("%s", ch1);//输出拷贝后的ch1
	return 0;
}