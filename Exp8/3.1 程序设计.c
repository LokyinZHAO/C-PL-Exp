#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
char origin[N];		//创建临时字符串，存储原文件的内容
char target[N];		//创建临时字符串，存储修改后内容，用此覆盖到原文件中
int check(char* head, char* cmp, int len);

int main(int argc, char* argv[])
{
	FILE* fp;
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("can't open the file %s\n", argv[1]);
		return -1;
	}
	int i = 0;
	char ch;
	while ((ch=fgetc(fp))!=EOF)		//将文件的数据存储到字符串中
	{
		origin[i++] = ch;
	}
	int whole_len = strlen(origin);
	int len = strlen(argv[2]);
	int j = 0;
	for ( i = 0; i < whole_len; i++)		//查找并替换
	{
		if (origin[i]==argv[2][0])
		{
			if (check(&origin[i], argv[2], len))		//找到应被替换文字
			{
				for (int i = 0; i < strlen(argv[3]); i++)
				{
					target[j++] = argv[3][i];
				}
				i += len-1;
			}
			else
			{
				target[j++] = origin[i];
			}
		}
		else
		{
			target[j++] = origin[i];
		}
	}
	fclose(fp);
	if ((fp = fopen(argv[1], "w")) == NULL)		//以写方式打开
	{
		printf("can't open the file %s\n", argv[1]);
		return -1;
	}
	for (int i = 0; i < strlen(target); i++)
	{
		fputc(target[i], fp);
	}
	fclose(fp);
	printf("all the \"%s\" have been replaced as \"%s\" successfully\n", argv[2], argv[3]);
	system("pause");
	return 0;
}

int check(char* head, char* cmp, int len)		//遇到argv[1]的首字母进行检查，若符合则返回1，否则返回0
{
	for (int i = 0; i < len; i++)
	{
		if (head[i]!=cmp[i])
		{
			return 0;
		}
	}
	return 1;
}
