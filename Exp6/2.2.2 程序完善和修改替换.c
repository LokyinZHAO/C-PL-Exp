#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char* (*p[3])(char a[], char b[]) = {strcpy,strcat,strtok};
	char a[80], b[80], * result;
	int choice;
	while (1)
	{
		do
		{
			printf("\t\t1 copy string.\n");
			printf("\t\t2 connect sstring.\n");
			printf("\t\t3 parse string.\n");
			printf("\t\t0 exit.\n");
			printf("\t\tinput a number(0-3) please!\n");
			scanf("%d", &choice);
			if (choice)
			{
				getchar();		//屏蔽上一个scanf的回车
				printf("input the first string please!\n");
				gets_s(a, 79);
				printf("input the second string please!\n");
				gets_s(b, 79);
				result = p[choice - 1](a,b);		//根据choice选择函数
				printf("the result is %s\n", result);
			}
			else return 0;

		} while (choice < 1 || choice>4);

	}
	return 0;
}