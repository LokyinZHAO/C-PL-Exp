#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("please input 10 float numbers\n");		//����10��������
	float num[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &num[i]);
	}
	printf("please input the filename to store the data\n");		//�����ļ���
	char filename[150];
	scanf("%s", filename);
	FILE* fp;
	if ((fp=fopen(filename,"wb"))==NULL)		//��д��ʽ�򿪶������ļ�
	{
		printf("cannot open the file %s", filename);
		return -1;
	}
	fwrite(num, sizeof(float), 10, fp);		//��10���������洢
	fclose(fp);
	if ((fp = fopen(filename, "rb")) == NULL)		//�Զ���ʽ�򿪶������ļ�
	{
		printf("cannot open the file %s", filename);
		return -1;
	}
	float fnum[10];
	fread(fnum, sizeof(float), 10, fp);			//���������ļ������ݴ洢���ڴ���
	for (int i = 0; i < 10; i++)		//����ڴ��ϵĶ������ļ�����
	{
		printf("%f\n", fnum[i]);
	}
	fclose(fp);
	system("pause");
	return 0;
}