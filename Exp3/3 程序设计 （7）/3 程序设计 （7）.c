#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define N 1000000

unsigned int a[N + 1] = { 0,0,1,1 };																			//声明1000000以内的素数表，并标记4以前的数,下标表示该数，储存的值表示是否为素数


int main(void)
{
	printf("输入m(4<=m<=1000000),查找m之前的所有孪生素数\n");
	int m = 0;																												//声明输入值m，并输入
	scanf_s("%d", &m);
	assert(m >= 4 && m <= 1000000);																		//断言以防止出现不满足条件的输入
	for (int i = 4; i <= N; i++)a[i] = 1;																			//初始化该素数表，默认都为素数

	for (int  i = 2; i*i <N ; i++)																					//从2开始到根号N逐一筛查
	{
		if (a[i]==1)																										
		{
			for (int j=i*i ; j <=N; j+=i)																				//若a[i]为素数，则i的所有倍数不再是素数，但避免重复计算，从i平方开始筛即可
			{
				a[j] = 0;																										//将这些素数的倍数标为0，表示非素数
			}
		}
	}

	for (int i = 2;i+2<=m; i++)																					//用for循环查找m以前的孪生素数
	{
		if (a[i+2]==1&& a[i] == 1)																				//满足孪生素数的条件，输出之
		{
			printf("(%d,%d)\n", i, i+2);
		}
	}
	
	system("pause");
	return 0;
}

