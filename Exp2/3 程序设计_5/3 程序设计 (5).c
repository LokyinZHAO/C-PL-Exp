#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//输入xmn
	unsigned short x, m, n;
	printf("Input x \n");
	scanf("%hx", &x);
	printf("Input m and n\n");
	scanf("%hd %hd", &m, &n);

	//检查mn的范围
	if (m<0||m>15)
	{
		printf("m应大于等于0小于等于15");
		return 0;
	}
	if (n<1||n>16-m)
	{
		printf("n应大于等于1 小于等于16-m");
		return 0;
	}

	//移位运算
	x = (x << (16 - (m + n))) & ((~(~0 << n)) << (16 - n));

	printf("%hx", x);
	system("pause");
	return 0;
}