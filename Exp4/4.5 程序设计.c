#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRCPY(a,b) strcpy(a##_p,#b)

int main(void)
{
	char var1_p[20];
	char var2_p[30];
	strcpy(var1_p, "aaaa");															//��aaaa���Ƶ�var1_p��
	strcpy(var2_p, "bbbb");															//��aaaa���Ƶ�var1_p��
	STRCPY(var1, var2);																//���ַ�����var2�����Ƶ�var1(_p)��	
	STRCPY(var2, var1);																//���ַ�����var1�����Ƶ�var2(_p)��	
	printf("var1=%s\n", var1_p);
	printf("var2=%s\n", var2_p);

	system("pause");
	return 0;
}