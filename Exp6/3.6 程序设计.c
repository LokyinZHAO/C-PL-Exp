//参数10 -d
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ascending_sort(int v[], int n);		//升序
void descending_sort(int v[], int n);		//降序


int main(int argc, char* argv[])
{
	if (argc != 2 && argc != 3)
	{
		printf("command line error\n");
		return -1;
	}
	int n = atoi(argv[1]);	
	printf("input %d integers to be sorted\n",n);
	int* tobesorted = (int*)malloc(sizeof(int) * n);
	if (tobesorted==NULL)
	{
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &tobesorted[i]);
	}
	if (argc==3)		//检查是否-d
	{
		if (!strcmp("-d",argv[2]))
		{
			descending_sort(tobesorted, n);
		}
	}
	else
	{
		ascending_sort(tobesorted, n);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *tobesorted++);
	}
	system("pause");
	return 0;
}

void ascending_sort(int v[], int n)
{
	for (int  i = 1; i < n; i++)
	{
		for (int j = 0; j <n-i; j++)
		{
			if (v[j]>v[j+1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	printf("sorted ascendedly:\n");
}

void descending_sort(int v[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (v[j] < v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	printf("sorted desendedly:\n");
}
