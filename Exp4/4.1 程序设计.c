//��֤��°ͺղ���
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 10000
int verify(int);
unsigned int prime_number_sheet[N+1];
void make_prime_number_sheet(void);

int main(void)
{
	printf("����һ�����ڵ���4��ż������֤��°ͺղ���\n");
	int n;
	make_prime_number_sheet();																			//����������
	scanf_s("%d", &n);
	assert(n >= 4 && n % 2 == 0);
	if (verify(n)!=0)																									
	{
	printf("%d=%d+%d\n", n, verify(n),n-verify(n) );													//������������ӡ���
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
			return i;																																		//�ҵ���������i��n-i�͵����������������i
		}
	}
 	return 0;																																				//���δ�ҵ�������0
}

void make_prime_number_sheet(void)
{
		for (int i = 2; i <= N; i++)prime_number_sheet[i] = 1;																		//��ʼ����������Ĭ�϶�Ϊ����

		for (int i = 2; i * i < N; i++)																												//��2��ʼ������N��һɸ��
		{
			if (prime_number_sheet[i] == 1)
			{
				for (int j = i * i; j <= N; j += i)																									//��a[i]Ϊ��������i�����б����������������������ظ����㣬��iƽ����ʼɸ����
				{
					prime_number_sheet[j] = 0;																									//����Щ�����ı�����Ϊ0����ʾ������
				}
			}
		}
	
}
