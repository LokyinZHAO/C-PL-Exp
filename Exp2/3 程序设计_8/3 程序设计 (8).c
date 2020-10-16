#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int letter=0, token=0, line=1;																					//初始化字符tok 字let 行line
	char ch;

	while ((ch=getchar())!=EOF)																							//以ctrl z结束
	{
		if (ch=='\n')
		{
			line++;
		}
		skip:
		if (ch >= 33 && ch <= 126)
		{
			token++;																										//c为西文字符 字符加一
			ch = getchar();
			if (ch == 9 || ch == 32 || ch == 10)
			{
				letter++;																									//空格 TAB 回车 字加一
				if (ch == 10)																							//回车还会行加一
				{
					line++;
				}
			}
			else
			{
				goto skip;
			}

		}
		if (ch<0)																											//c可能是中文字符的前一个Byte
		{
			if ((ch = getchar()) <0)																				//c是中文字符 字符和字加一
			{
				letter++;
				token++;
			}
			else
			{
				token++;																									//c不是中文字符 视作普通字符 字符加一
			}
		}

		
	}	
	printf("有%d个字符、%d个字、%d行", token, letter, line-1);
	system("pause");
	return 0;
}