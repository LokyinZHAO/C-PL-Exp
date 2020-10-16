#include<stdio.h>
#include<stdlib.h>
char* strcopy(char*, const char*);

int main(void)
{
	char s1[100],  s2[100],  *s3;											//初始化未规定元素个数时，需要标出数组的长度
	char* p;
	printf("Input a string:\n");												//无占位符，无需传s2参数
	scanf("%s", s2);
	strcopy(s1, s2);
	printf("%s \n", s1);
	printf("Input a string again:\n");									//无占位符，无需传s2参数
	scanf("%s", s2);
	s3= strcopy(s1, s2);														//;遗漏
	printf("%s\n", s3);
	system("pause");
	return 0;
}

//将字符串s复制给字符串t，并返回串t的首地址
char* strcopy(char* t, const char* s)
{
	char* des=t;
	while (*t++ = *s++);
	return (des);																	//t已经移动改变，需要返回初始传入的
}
