#include<stdio.h>
#include<stdlib.h>
#define Line_Max	10
#define Row_Max 10
int* anticlock_rotate(int* p, int* q, int n, int m);
int image[Line_Max][Row_Max] = { 0 };		//处理前图像
int rotated_image[Row_Max][Line_Max] = { 0 };	//处理后图像

int main(void)
{
	printf("输入一个矩阵，对其进行逆时针90°旋转\n");
	printf("输入矩阵的行数n和列数m:\n");
	int n, m;
	scanf_s("%d %d", &n, &m);
	printf("输入矩阵：\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &image[i][j]);
		}
	}
	anticlock_rotate(image,rotated_image, n, m);
	printf("//////////////逆时针旋转90°处理后的图像////////////////\n");
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
			rotated_image[j][i] = image[i][m - 1 - j];		//按规律旋转
		}
	}
	return NULL;
}
