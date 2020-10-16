#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("输入一个整数，以字符串的形式输出其二进制\n");
	int x;
	scanf_s("%d", &x);
	char dec[32];																			//声明一个32位的字符型数组存放二进制

	if (x==0)																					//0做特殊处理
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < 32; i++)															//进行进制转换
	{
		dec[i] = (x&0x00000001)+'0';
		x /=2;
	}

	for (int i = 31;i>=0 ; i--)															//将多余的0用'f'进行特殊标记
	{
		if (dec[i] == '0') dec[i] = 'f';
		else break;
	}

	for (int i = 31; i>=0; i--)															//逆序打印该字符数组，直至遇到标记'f'，从而的到正确的二进制
	{
		if (dec[i] != 'f')	 printf("%c", dec[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}