#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("please input 10 float numbers\n");		//读入10个浮点数
	float num[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &num[i]);
	}
	printf("please input the filename to store the data\n");		//读入文件名
	char filename[150];
	scanf("%s", filename);
	FILE* fp;
	if ((fp=fopen(filename,"wb"))==NULL)		//以写方式打开二进制文件
	{
		printf("cannot open the file %s", filename);
		return -1;
	}
	fwrite(num, sizeof(float), 10, fp);		//将10个浮点数存储
	fclose(fp);
	if ((fp = fopen(filename, "rb")) == NULL)		//以读方式打开二进制文件
	{
		printf("cannot open the file %s", filename);
		return -1;
	}
	float fnum[10];
	fread(fnum, sizeof(float), 10, fp);			//将二进制文件的内容存储到内存上
	for (int i = 0; i < 10; i++)		//输出内存上的二进制文件内容
	{
		printf("%f\n", fnum[i]);
	}
	fclose(fp);
	system("pause");
	return 0;
}