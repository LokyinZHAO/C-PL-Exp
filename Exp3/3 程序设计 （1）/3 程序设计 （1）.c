#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//x为工资金额 m为税金额度
	int x ;
	float m;

	printf("输入工资金额，计算税金额度\n");
	scanf_s("%d", &x);
	if (x<1000)
	{
		m = 0;
	}
	else if (1000<=x&&x<2000)
	{
		m = 0.05 * x;
	}
	else if (2000<=x&&x<3000)
	{
		m = 0.1 * x;
	}
	else if (3000 <= x && x < 4000)
	{
		m = 0.15 * x;
	}
	else if (4000 <= x && x < 5000)
	{
		m = 0.20 * x;
	}
	else if (x >= 5000)
	{
		m = 0.25 * x;
	}
	printf("税金为%f" ,m);
	system("pause");
	return 0;
}