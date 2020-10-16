#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRCPY(a,b) strcpy(a##_p,#b)

int main(void)
{
	char var1_p[20];
	char var2_p[30];
	strcpy(var1_p, "aaaa");															//将aaaa复制到var1_p上
	strcpy(var2_p, "bbbb");															//将aaaa复制到var1_p上
	STRCPY(var1, var2);																//将字符串“var2”复制到var1(_p)上	
	STRCPY(var2, var1);																//将字符串“var1”复制到var2(_p)上	
	printf("var1=%s\n", var1_p);
	printf("var2=%s\n", var2_p);

	system("pause");
	return 0;
}