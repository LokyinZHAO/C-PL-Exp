//输入字符c 若c是大写 转换成小写 否则c不变
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char c;
	c = getchar();
	putchar((c>='A'&&c<='Z')?c+'a'-'A':c);
	system("pause");
	return 0;
}