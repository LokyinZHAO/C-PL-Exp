#include<stdio.h>
#include<stdlib.h>
void lineprint(int);														//声明打印每一行的函数

int main(void)
{
	printf("打印杨辉三角:\n");
	int line;
	printf("                  1\n");										//直接打印第一行
	for (line=1 ; line< 10; line++)
	{
		lineprint(line);													//重复循环调用该函数，以输出10行
	}
	system("pause");
	return 0;
}

void lineprint(int i)
{	
		
	for (int k = 1; k < 10-i; k++)									//打印每一行之前的空格
	{
		printf("  ");
	}	
	int c = 1; printf("1   ");											//直接打印第一个数字1以及三个' ' 
	for (int j = 1; j <=i ; j++)										
	{
		c = c * (i - j + 1) / j;											//根据公式递推
		printf("%d", c);
		if (c<10)															//根据位数输出相应的空格数
		{
			printf("   ");
		}
		else if (c>=10&&c<100)
		{
			printf("  ");
		}
		else if(c>=100)
		{
			printf(" ");
		}

	}
	printf("\n");															//换行
}
