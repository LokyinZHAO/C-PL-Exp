#include<stdio.h>
#include<stdlib.h>
unsigned long long fabonacci(long long , long long ,int);

int main(void)
{
	int i, k;
	unsigned long long sum = 0;
	printf("Input n:\n");
	scanf_s("%d", &k);
	for (i = 1; i <= k; i++)
	{
		sum += fabonacci(1,1,i);
		printf("i=%d\tthe sum is %llu\n", i, sum);
	}

	system("pause");
	return 0;
}

unsigned long long fabonacci(long long first,long long second,int n )
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n == 3)
	{
		return (first + second);
	}
	else return fabonacci(second, second+first, n - 1);
}
