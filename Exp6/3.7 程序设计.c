#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
#define MaxString 10
char* seek_longest(int n, int* max_len, char* s[]);

int main(void)
{
	printf("input several strings to find out the longest one\n");
	printf("first please input the number of the strings\n");
	int n;
	scanf_s("%d", &n);
	getchar();
	printf("input %d strings \n",n);
	char* s[MaxString];
	for (int  i = 0; i < n; i++)		//��ȡ�ַ���
	{
		char temp[100];
		gets_s(temp,99);
		s[i] = (char*)malloc(sizeof(char) * strlen(temp));
		strcpy_s(s[i], 99, temp);
	}
	int max_len = 0;
	printf("\nthe longest string is:\n%s\t(%dbyte)\n", seek_longest(n, &max_len, s),max_len);
	system("pause");
	return 0;
}

/********************************************************
�������ܣ���һ���ַ������ҳ����һ���ַ������������׵�ַ
����˵����	int n���ַ�������
					int* max_len������ͨ��������������ĳ���
					char* s[]����������ַ�������
*******************************************************/
char* seek_longest(int n, int* max_len, char* s[])
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int len = strlen(s[i]);
		if (len>*max_len)
		{
			*max_len = len;
			flag = i;
		}
	}
	return s[flag];
}
