#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)；

void strReverse(char s[]);
int strLength(char s[]);

int main(void)
{
	char s[1000];
	printf("输入一个字符串\n");
	scanf("%s", s);
	printf("串%s的长度为:%d\n", s, strLength(s));
	strReverse(s);
	printf("反转后:%s", s);
	system("pause");
	return 0;
}


void strReverse(char s[])
{
	int i, j;
	for ( i = 0,j=(strLength(s)-1); i < j; i++,j--)					//应让strLength返回值-1才能让j正确初始化计数
	{
		char	t;
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}

int strLength(char s[])
{	
	int i = 0;
	while (s[++i]);															//字符串的储存长度比实际长度多1（包含'/0')故++i即可
	return i;

}
