#include<stdio.h>
#include<stdlib.h>
#define Line_Max	10
#define Row_Max 10
int* anticlock_rotate(int* p, int* q, int n, int m);
void save_image(int n,int m);
void save_rotated_image(int n, int m);
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
	anticlock_rotate(image, rotated_image, n, m);
	/////////////ͼ���Ѿ�����ת����///////////////
	save_image(n, m);//�洢ԭʼͼƬ
	save_rotated_image(m, n);//�洢��ת���ͼƬ
	printf("�ļ�matrix.in��matrix.out�����ı��ļ���ʽ�洢����ǰĿ¼��\n");
	system("pause");
	return 0;
}

int* anticlock_rotate(int* p, int* q, int n, int m)
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

void save_image(int n, int m)//n��ʾ������m��ʾ����
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
