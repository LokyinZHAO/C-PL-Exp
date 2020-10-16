#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//输入天数 并初始化销售量数组
	int day, k;
	k = 0;
	printf("请输入天数\n");
	scanf_s("%d", &day);
	int sellings[50] = {0};
	
	//输入销售量 保存于数组sellings中
	for (int  i = 0; i < day; i++)
	{
		scanf_s("%d", &sellings[i]);
	}

	//依次检验 若存在拐点 k自增
	for (int i = 2; i < day; i++)
	{
		if ((sellings[i] - sellings[i - 1]) * (sellings[i - 1] - sellings[i - 2]) < 0)
			k++;
	}

	//输出拐点数k
	printf("%d", k);

	system("pause");
	return 0;
}