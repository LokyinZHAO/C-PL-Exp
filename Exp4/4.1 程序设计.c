//验证哥德巴赫猜想
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 10000
int verify(int);
unsigned int prime_number_sheet[N+1];
void make_prime_number_sheet(void);

int main(void)
{
	printf("输入一个大于等于4的偶数，验证哥德巴赫猜想\n");
	int n;
	make_prime_number_sheet();																			//建立素数表
	scanf_s("%d", &n);
	assert(n >= 4 && n % 2 == 0);
	if (verify(n)!=0)																									
	{
	printf("%d=%d+%d\n", n, verify(n),n-verify(n) );													//满足条件，打印结果
	}

	system("pause");
	return 0;
}

int  verify(int n)
{

	for (int  i=2; i <= n/2; i++)
	{
		if (prime_number_sheet[n-i]==1 && prime_number_sheet[i] == 1)
		{
			return i;																																		//找到两个素数i，n-i和等于输入的数，返回i
		}
	}
 	return 0;																																				//穷尽后未找到，返回0
}

void make_prime_number_sheet(void)
{
		for (int i = 2; i <= N; i++)prime_number_sheet[i] = 1;																		//初始化该素数表，默认都为素数

		for (int i = 2; i * i < N; i++)																												//从2开始到根号N逐一筛查
		{
			if (prime_number_sheet[i] == 1)
			{
				for (int j = i * i; j <= N; j += i)																									//若a[i]为素数，则i的所有倍数不再是素数，但避免重复计算，从i平方开始筛即可
				{
					prime_number_sheet[j] = 0;																									//将这些素数的倍数标为0，表示非素数
				}
			}
		}
	
}
