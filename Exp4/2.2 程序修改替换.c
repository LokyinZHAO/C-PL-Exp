//�ݹ����׳˺͵ĳ���
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

unsigned long long sum_fac(int x)																		//�ú������ڼ���׳˺�
{
	unsigned long long int s = 0;
	if (x == 1)
	{
		return factorial(1);
	}
	else return s += sum_fac(x - 1) + factorial(x);													//�ݹ����
}

unsigned long long factorial(int n)																		//�ú������ڼ���׳�
{
	if (n == 1 || n == 0)																			
	{
		return 1;																										//�ݹ鵽1ʱ����
	}
	else
		return (n * (factorial(n - 1)));																			//�ݹ����
}
