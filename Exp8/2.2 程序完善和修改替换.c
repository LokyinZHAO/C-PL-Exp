#include<stdio.h>
#include<stdlib.h>	
#include<string.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE* fp;
	if (argc != 2&&argc!=3)
	{
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("can't open %s file!\n", argv[1]);
		exit(-1);
	}

	if (argc==3&&!strcmp(argv[2],"/p"))		//带有/p的情况
	{
		int line = 1;
		int flag = 0;
		printf("%d\t", line);
		while ((ch = fgetc(fp)) != EOF)
		{
			putchar(ch);
			if (ch=='\n')
			{
				line++;
			}
			if (ch=='\n'&&line%25==1)
			{
				system("pause");		//25行暂停
				system("cls");
				printf("%d\t", line);
			}
			else if (ch=='\n')
			{
				printf("%d\t", line);
			}
		}
		
	}
	else
	{
		int line = 0;
		printf("%d\t", ++line);
		while ((ch = fgetc(fp)) != EOF)		//ch=fget()需括起来
		{
			putchar(ch);
			if (ch=='\n')
			{
				printf("%d\t", ++line);
			}
		}
	}
	fclose(fp);
	system("pause");
	return 0;
}