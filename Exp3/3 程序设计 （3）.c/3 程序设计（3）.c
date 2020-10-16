#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char ch,lastch=0;
	printf("将输入的正文复制到输出，复制过程中将每行连续的多个空格替换为一个空格\n");
	while ((ch = getchar()) != EOF)																		//重复循环读入字符 直至读入EOF结束
	{

		if (ch==' ')																								//若读入' ' ，进入重复读入‘ ’ 的状态，但不输出
		{
			putchar(' ');
			while ((ch = getchar()) == ' ');
			putchar(ch);
		}
		else
		{
			putchar(ch);																							//其他情况下复制输出即可
		}
	}
	
	system("pause");
	return 0;
}