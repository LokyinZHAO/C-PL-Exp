#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	int a, b, number;																//声明前两位数a，后两位数b，车牌号number
	float check;
	for (a=1;a<=9;a++)															//采用枚举法
	{
		for ( b = 1; b < 10; b++)
		{
			if (a == b)continue;													//要求a不等于b
			number = a * 1000 + a * 100 + b * 10 + b;
			check = sqrt(number);
			if (check==(int)check)												//满足该条件，说明number是个平方数
			{
				printf("所求的车牌号为\n%d\n", number);
			}
		}
	}
	system("pause");
	return 0;
}