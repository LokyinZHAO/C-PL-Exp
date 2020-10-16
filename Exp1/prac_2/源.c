#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char c, numchar, numline;
	numchar = 0;
	numline = 0;
	printf("输入若干文本，ctrl+z结束\n");
	while ((c = getchar()) != EOF)								//原错误：while (c = getchar() != EOF)——优先级错误，优先执行!=
	{
		numchar++;
		if (c == '\n')
		{
			numline++;
		};
	};
	printf("字符数：%d\n", numchar);
	printf("行数：%d\n",numline);
	system("pause");
	return 0;
}