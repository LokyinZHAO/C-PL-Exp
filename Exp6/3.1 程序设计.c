#include<stdio.h>
#include<stdlib.h>
#define High_Byte_Mask 0x0F		//����λ����
#define Low_Byte_Mask 0xF0		//����λ����
int main(void)
{
	printf("����һ��ʮ���Ƶ�long����ʮ�������������ÿ����ֽ�\n");
	long source;
	scanf_s("%ld", &source);
	char* p = &source;													//char* ָ�뱣֤ÿ���ƶ�һ���ֽ�
	p += 3;																		//��source�ĸ��ֽڿ�ʼȡ
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