#include<stdio.h>
#include<stdlib.h>
#define High_Byte_Mask 0x0F		//高四位掩码
#define Low_Byte_Mask 0xF0		//第四位掩码
int main(void)
{
	printf("输入一个十进制的long，按十六进制依次输出每半个字节\n");
	long source;
	scanf_s("%ld", &source);
	char* p = &source;													//char* 指针保证每次移动一个字节
	p += 3;																		//从source的高字节开始取
	for (int i = 0; i < 4; i++)
	{
		printf("\t%X", (*p & Low_Byte_Mask) >> 4);
		printf("\t%X", (*p &		High_Byte_Mask));
		p--;
	}
	printf("\n");
	system("pause");
	return 0;
}