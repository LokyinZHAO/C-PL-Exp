#include<stdio.h>
#include<stdlib.h>
int RemoveSame(int *a,int  n);
void Bubble_sort(int *a,int n);


int main(void)
{
	printf("�������ã�����ȥ����n��Ԫ�ص��ظ���������\n");
	printf("�����������е�Ԫ�ظ���\n");
	int n = 0;
	scanf_s("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	printf("���뺬��%d��Ԫ�ص���������", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", a + i);
	}
	Bubble_sort(a, n);
	int left=RemoveSame(a, n);
	printf("ȥ�غ���Ϊ:\n");
	int flag = *a;
	for (int i = 0; i < left; i++)
	{
		if (i==0)
		{
			printf("%d ", flag);
		}
		if (i>0&&flag!=*(a+i))
		{
			printf("%d ", *(a + i));
		}
	}
	system("pause");
	return 0;
}

//ȥ����n��Ԫ�ص�������������a�е��ظ�Ԫ�أ�����ȥ�غ����еĳ���ֵ
int RemoveSame(int a[], int n)
{
	int flag = *a;		//��a����ĵ�һ��Ԫ�ر�ǣ���ʾӦ��ȥ������
	int count = 0;		//��¼����ȥ�����ĸ���
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n-i; j++)
		{
			if (*(a + i) == *(a + i + j))
			{
				*(a + i + j) = flag;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == flag&&i!=0)
		{
			count++;
			for (int j = 0; j < n-i; j++)
			{
				*(a + i + j) = *(a + i + j + 1);
			}
		}
	}
	return n-count;
}

//ð�ݷ���������
void Bubble_sort(int *a, int n)
{	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (*(a + j) > *(a + j + 1))
			{
				int temp = *(a + j + 1);
				*(a + j + 1) = *(a + j);
				*(a + j) = temp;
			}
		}
	}
}
