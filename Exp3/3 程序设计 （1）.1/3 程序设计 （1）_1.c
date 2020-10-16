#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//x为工资金额 m为税金额度
	int x;
	float m;
	printf("输入工资金额，计算税金额度\n");
	scanf_s("%d", &x);

	switch (x/1000)
	{
	case 0:m = 0;				break;
	case 1:m = 0.05 * x;		break;
	case 2:m = 0.1 * x;		break;
	case 3:m = 0.15 * x;	   	break;
	case 4:m = 0.20 * x;		break;
	default:m = 0.25 * x;		break;
	}

	printf("税金为%.2f\n", m);
	system("pause");
	return 0;
}