//����׳˺͵ĳ���
#include<stdio.h>
#include<stdlib.h>
long long  sum_fac(int n);																	//δ��������ԭ��

int main(void)
{
	int k;
	for ( k = 1	; k <=20; k++)
	{
		printf("k=%d\tthe sum is %llu\n", k, sum_fac(k));						//��Ϊ��long long int ���������õ���Ӧ��ת����
	}
	return 0;
	system("pause");
	return 0;
}

unsigned long long sum_fac(int n)
{
	unsigned long long s = 0;															//sӦ��facƥ��
	int i;
	unsigned long long int fac = 1;													//fac������һ���ǳ����������Ҫlong long int�洢�������䲻���Ǹ������Կ��Ըĳ�unsigned��
	for ( i = 1	; i <=n; i++)
	{
		fac *= i;
		s += fac;																					//sӦ����forѭ���ڲ��ܼ���׳˺�
	}
	
	return s;
}