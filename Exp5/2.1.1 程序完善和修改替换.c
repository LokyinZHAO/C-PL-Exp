#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void RemoveDuplicate(char* s);

int main(void)
{
	char str[200];
	printf("Input strings,end of Ctrl+z\n");
	while (fgets(str, 200, stdin) != NULL)
	{
		RemoveDuplicate(str);
		printf("%s", str);
	}
	system("pause");
	return 0;
}

void RemoveDuplicate(char* s)
{
	int r, w, i, len;
	len = strlen(s);
	for (r = w = 0; r < len; r++)
	{
		if (s[r])										//s[r]��0��ʾδ���ֹ�����ʼ����֮����ظ�����
		{
			w = s[r];								//��w��¼s[r]
			for (i = r + 1; i < len; i++)
			{
				if (w == s[i])						//���ҵ��ظ����ݣ�������0
					s[i] = '\0';
			}
		}
	}

	for (r = w = 0; r < len; r++)			//������������������У�ʹ֮��Ϊ�ַ���
	{
		if (s[r])
		{
			s[w++] = s[r];
		}
	}
	s[w] = '\0';
}
