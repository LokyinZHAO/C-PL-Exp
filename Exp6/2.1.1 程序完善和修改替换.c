
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
		strcpy(s[i], t);		//����t��s[i]
	}	
 	strsort(&s[0], N);		//�������s,N
	for ( i = 0; i < N; i++)
	{
		puts(s[i]);
	}
	system("pause");
	return 0;
}

void strsort(char* s[], int size)
{
	char* temp;		//������ʱ�Ķ�̬�ַ�������
	int i, j;
	for ( i = 0; i < size-1; i++)
	{
		for(j=0;j<size-i-1;j++)
			if (strcmp(s[j],s[j+1])>0)		//�������
			{
				temp = s[j];
				s[j] = s[j + 1];		//����
				s[j + 1] = temp;
			}
	}
}
