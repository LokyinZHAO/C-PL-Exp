//计算阶乘和的程序
#include<stdio.h>
#include<stdlib.h>
long long  sum_fac(int n);																	

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

unsigned long long sum_fac(int n)
{
	static unsigned long long s = 0;															//声明static静态变量s和fac，减少每次调用该函数时的重复运算
	static unsigned long long int fac = 1;													
	fac *= n;
	s += fac;
	return s;
}