//计算阶乘和的程序
#include<stdio.h>
#include<stdlib.h>
long long  sum_fac(int n);																	//未声明函数原型

int main(void)
{
	int k;
	for ( k = 1	; k <=20; k++)
	{
		printf("k=%d\tthe sum is %llu\n", k, sum_fac(k));						//因为是long long int ，所以需用到相应的转换符
	}
	return 0;
	system("pause");
	return 0;
}

unsigned long long sum_fac(int n)
{
	unsigned long long s = 0;															//s应与fac匹配
	int i;
	unsigned long long int fac = 1;													//fac可以是一个非常大的数，需要long long int存储，（因其不会是负数所以可以改成unsigned）
	for ( i = 1	; i <=n; i++)
	{
		fac *= i;
		s += fac;																					//s应放在for循环内才能计算阶乘和
	}
	
	return s;
}