#include<stdio.h>
#include<stdlib.h>
int check(int);																		//声明检查合数的函数

int main(void)
{
	int x = 100;
	int   flag;
	while (x>=100&&x<=999)
	{
		flag = 0;
		if (check(x)&&check(x/10)&&check(x/100))					//分别检查三位合数，同时满足为纯粹合数
		{
			flag = 1;
		}

		if (flag==1)
		{
			printf("%d\n", x);
		}
		x++;
	}

		
	return 0;
}

int check(int n)
{
	if (n==1||n==2)																//排除1和2的特殊情况	
	{
		return 0;
	}
	int i=2;
	int  k = n / 2;
	do
	{
		if (!(n % i) && n != 2) return 1;
		i++;
	} while (i <= k );

	return 0;
}
