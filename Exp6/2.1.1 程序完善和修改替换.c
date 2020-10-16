
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define N 4
void strsort(char* s[], int size);

int main(void)
{
	int i;
	char  t[50], * s[N];
	for ( i = 0; i < N; i++)
	{
		gets_s(t, 50);
		s[i] = (char*)malloc(strlen(t) + 1);
		assert(s[i] != NULL);
		strcpy(s[i], t);		//复制t到s[i]
	}	
 	strsort(&s[0], N);		//传入参数s,N
	for ( i = 0; i < N; i++)
	{
		puts(s[i]);
	}
	system("pause");
	return 0;
}

void strsort(char* s[], int size)
{
	char* temp;		//声明临时的动态字符型数组
	int i, j;
	for ( i = 0; i < size-1; i++)
	{
		for(j=0;j<size-i-1;j++)
			if (strcmp(s[j],s[j+1])>0)		//检查排序
			{
				temp = s[j];
				s[j] = s[j + 1];		//交换
				s[j + 1] = temp;
			}
	}
}
