#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i, x, k, flag;
	printf("本程序判断合数，请输入大于1的整数，Ctrl+z结束\n");
	while (scanf_s("%d", &x) != EOF)
	{
		flag = 0;																					//flag应在此处初始化，在原位置只会初始化一次，存在逻辑错误

		for (i = 2, k = x >> 1; i <= k; i++)
			if (!(x % i))																				//逻辑非!运算优先级比取余%优先级高应给x%i加括号
			{
				flag = 1;
				break;
			}
		if (flag == 1)		printf("%d 是合数\n", x);									//判断相等应用关系运算符==
		else printf("%d 不是合数\n", x);
	}
	return 0;
}
	

