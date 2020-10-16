//输入一个正整数，求它是几位数并计算它的各位数字之和
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("输入一个正整数，求它是几位数并计算它的各位数字之和\n");
	int n, k, s, n0;
	s = 0;
	scanf_s("%d", &n);
	n0 = n;
	for ( k = 0; n; k++)
	{
		s += n % 10;
		n /= 10;
	}
	printf("%d是%d位数，各位数字之和为%d", n0, k, s);
	system("pause");
	return 0;
}