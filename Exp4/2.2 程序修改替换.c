//递归计算阶乘和的程序
#include<stdio.h>
#include<stdlib.h>
unsigned long long  sum_fac(int n);	
unsigned long long factorial(int n);

int main(void)
{
	int k;
	for (k = 1; k <= 20; k++)
	{
		printf("k=%d\tthe sum is %llu\n", k, sum_fac(k));
	}
	return 0;
	system("pause");
	return 0;
}

unsigned long long sum_fac(int x)																		//该函数用于计算阶乘和
{
	unsigned long long int s = 0;
	if (x == 1)
	{
		return factorial(1);
	}
	else return s += sum_fac(x - 1) + factorial(x);													//递归调用
}

unsigned long long factorial(int n)																		//该函数用于计算阶乘
{
	if (n == 1 || n == 0)																			
	{
		return 1;																										//递归到1时返回
	}
	else
		return (n * (factorial(n - 1)));																			//递归调用
}
