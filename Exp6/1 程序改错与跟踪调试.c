#include<stdio.h>
#include<stdlib.h>
char* strcopy(char*, const char*);

int main(void)
{
	char s1[100],  s2[100],  *s3;											//��ʼ��δ�涨Ԫ�ظ���ʱ����Ҫ�������ĳ���
	char* p;
	printf("Input a string:\n");												//��ռλ�������贫s2����
	scanf("%s", s2);
	strcopy(s1, s2);
	printf("%s \n", s1);
	printf("Input a string again:\n");									//��ռλ�������贫s2����
	scanf("%s", s2);
	s3= strcopy(s1, s2);														//;��©
	printf("%s\n", s3);
	system("pause");
	return 0;
}

//���ַ���s���Ƹ��ַ���t�������ش�t���׵�ַ
char* strcopy(char* t, const char* s)
{
	char* des=t;
	while (*t++ = *s++);
	return (des);																	//t�Ѿ��ƶ��ı䣬��Ҫ���س�ʼ�����
}
