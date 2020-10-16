#include<stdio.h>
#include<stdlib.h>
int RemoveSame(int *a,int  n);
void Bubble_sort(int *a,int n);


int main(void)
{
	printf("程序作用，输入去掉有n个元素的重复整数序列\n");
	printf("输入整数序列的元素个数\n");
	int n = 0;
	scanf_s("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	printf("输入含有%d个元素的整数序列", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", a + i);
	}
	Bubble_sort(a, n);
	int left=RemoveSame(a, n);
	printf("去重后结果为:\n");
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

//去掉有n个元素的有序整数序列a中的重复元素，返回去重后序列的长度值
int RemoveSame(int a[], int n)
{
	int flag = *a;		//用a数组的第一个元素标记，表示应被去掉的数
	int count = 0;		//记录被减去的数的个数
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

//冒泡法升序排序
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
