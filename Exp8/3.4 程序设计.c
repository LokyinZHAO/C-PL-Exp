#include<stdio.h>
#include<stdlib.h>
#define Line_Max	10
#define Row_Max 10
int* anticlock_rotate(int* p, int* q, int n, int m);
void save_image(int n,int m);
void save_rotated_image(int n, int m);
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
	anticlock_rotate(image, rotated_image, n, m);
	/////////////图像已经过旋转处理///////////////
	save_image(n, m);//存储原始图片
	save_rotated_image(m, n);//存储旋转后的图片
	printf("文件matrix.in和matrix.out已以文本文件形式存储到当前目录下\n");
	system("pause");
	return 0;
}

int* anticlock_rotate(int* p, int* q, int n, int m)
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

void save_image(int n, int m)//n表示行数，m表示列数
{
	FILE* fp;
	if ((fp=fopen("matrix.in","w"))==NULL)
	{
		printf("cannot creat the file matrix.in\n");
		return;
	}
	fprintf(fp, "%d %d\n", n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fprintf(fp,"%d ", image[i][j]);
		fprintf(fp,"\n");
	}
	fclose(fp);
	return;
}

void save_rotated_image(int n, int m)
{
	FILE* fp;
	if ((fp = fopen("matrix.out", "w")) == NULL)
	{
		printf("cannot creat the file matrix.in\n");
		return;
	}
	fprintf(fp, "%d %d\n", n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fprintf(fp, "%d ", rotated_image[i][j]);
		fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}
