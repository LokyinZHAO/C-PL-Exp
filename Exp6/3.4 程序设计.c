#include<stdio.h>
#include<stdlib.h>
#define Line_Max	10
#define Row_Max 10
int* anticlock_rotate(int* p, int* q, int n, int m);
int image[Line_Max][Row_Max] = { 0 };		//����ǰͼ��
int rotated_image[Row_Max][Line_Max] = { 0 };	//�����ͼ��

int main(void)
{
	printf("����һ�����󣬶��������ʱ��90����ת\n");
	printf("������������n������m:\n");
	int n, m;
	scanf_s("%d %d", &n, &m);
	printf("�������\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &image[i][j]);
		}
	}
	anticlock_rotate(image,rotated_image, n, m);
	printf("//////////////��ʱ����ת90�㴦����ͼ��////////////////\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", rotated_image[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}

int* anticlock_rotate(int* p,int* q, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			rotated_image[j][i] = image[i][m - 1 - j];		//��������ת
		}
	}
	return NULL;
}
