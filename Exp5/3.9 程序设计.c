#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void intSplit(int sum, int k, int prio);
int n;
int a[100] = { 0 };		//���ڴ�ŵ�ǰ�Ļ���

int main(void)
{
	printf("����һ����λ��������������������������\n");

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
	else if (sum==n)		//sum==nʱ��ʾ��ǰ����Ļ��ּ�����������������a[i]�еĽ��
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
 		for (int j = prio; j >0; j--)		//�Ӵ�С���л���
		{
			a[k] = j;
			sum += j;
			intSplit(sum, k + 1, j);		//�ݹ����
			sum -= j;		//���غ���ָ�sum
		}
	}
}
