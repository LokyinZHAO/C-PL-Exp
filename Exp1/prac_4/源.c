#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)��

void strReverse(char s[]);
int strLength(char s[]);

int main(void)
{
	char s[1000];
	printf("����һ���ַ���\n");
	scanf("%s", s);
	printf("��%s�ĳ���Ϊ:%d\n", s, strLength(s));
	strReverse(s);
	printf("��ת��:%s", s);
	system("pause");
	return 0;
}


void strReverse(char s[])
{
	int i, j;
	for ( i = 0,j=(strLength(s)-1); i < j; i++,j--)					//Ӧ��strLength����ֵ-1������j��ȷ��ʼ������
	{
		char	t;
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}

int strLength(char s[])
{	
	int i = 0;
	while (s[++i]);															//�ַ����Ĵ��泤�ȱ�ʵ�ʳ��ȶ�1������'/0')��++i����
	return i;

}
