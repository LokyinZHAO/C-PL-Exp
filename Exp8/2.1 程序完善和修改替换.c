#include<stdio.h>
#include<stdlib.h>	

int main(int argc, char* argv[])
{
	char ch;
	FILE* fp;
	if (argc!=2)
	{
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("can't open %s file!\n", argv[1]);
		exit(-1);
	}
	while ((ch=fgetc(fp))!=EOF)		//ch=fget()ÐèÀ¨ÆðÀ´
	{
		putchar(ch);
	}
	fclose(fp);
	system("pause");
	return 0;
}