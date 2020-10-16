#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
#define MaxString 10
char* seek_longest(int n, int* max_len, char* s[]);

int main(void)
{
	printf("input several strings to find out the longest one\n");
	printf("first please input the number of the strings\n");
	int n;
	scanf_s("%d", &n);
	getchar();
	printf("input %d strings \n",n);
	char* s[MaxString];
	for (int  i = 0; i < n; i++)		//获取字符串
	{
		char temp[100];
		gets_s(temp,99);
		s[i] = (char*)malloc(sizeof(char) * strlen(temp));
		strcpy_s(s[i], 99, temp);
	}
	int max_len = 0;
	printf("\nthe longest string is:\n%s\t(%dbyte)\n", seek_longest(n, &max_len, s),max_len);
	system("pause");
	return 0;
}

/********************************************************
函数功能：从一组字符串中找出最长的一个字符串，返回其首地址
参数说明：	int n：字符串个数
					int* max_len：用于通过参数返回最长串的长度
					char* s[]：被处理的字符串数组
*******************************************************/
char* seek_longest(int n, int* max_len, char* s[])
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int len = strlen(s[i]);
		if (len>*max_len)
		{
			*max_len = len;
			flag = i;
		}
	}
	return s[flag];
}
