#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void RemoveDuplicate(char* s);

int main(void)
{
	char str[200];
	printf("Input strings,end of Ctrl+z\n");
	while (gets_s(str, 200) != NULL)
	{
		RemoveDuplicate(str);
		printf("%s", str);
	}
	system("pause");
	return 0;
}

void RemoveDuplicate(char* s)
{
	char check_apprearance[256] = { 0 };					//δ���ֹ����ַ����Ϊ0				
	int r, w, len = strlen(s);
	for (int i = 0; i <len; i++)
	{
		if (check_apprearance[s[i]] == 0)						//���ַ�״̬��δ���ָı�Ϊ����
			check_apprearance[s[i]] = 1;
		else s[i] = '\0';													//���򽫸��ַ���0
	}
	for (r=0,w=0; r <len; r++)										//�������������У�ʹ֮��Ϊһ���ַ���
	{
		if (s[r])
		{
			s[w++] = s[r];
		}
	}
	s[w] = '\0';
}
