//����׳˺͵ĳ���
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
	static unsigned long long s = 0;															//����static��̬����s��fac������ÿ�ε��øú���ʱ���ظ�����
	static unsigned long long int fac = 1;													
	fac *= n;
	s += fac;
	return s;
}