#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void intSplit(int sum, int k, int prio);
int n;
int a[100] = { 0 };		//用于存放当前的划分

int main(void)
{
	printf("输入一个个位数，输出这个数得所有整数划分\n");

	scanf_s("%d", &n);
	assert(n > 0 && n < 10);
	
	intSplit(0, 0, n);
	system("pause");
	return 0;
}


void intSplit(int sum, int k, int prio)
{
	if (sum>n)
	{
		return;
	}
	else if (sum==n)		//sum==n时表示当前情况的划分计算结束，输出保存在a[i]中的结果
	{
		int i;
		for ( i = 0; i < k-1; i++)
		{
			printf("%d+", a[i]);
		}
		printf("%d\n", a[i]);
	}
	else
	{
 		for (int j = prio; j >0; j--)		//从大到小进行划分
		{
			a[k] = j;
			sum += j;
			intSplit(sum, k + 1, j);		//递归调用
			sum -= j;		//返回后需恢复sum
		}
	}
}
