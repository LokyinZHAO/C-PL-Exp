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
	char check_apprearance[256] = { 0 };					//未出现过的字符标记为0				
	int r, w, len = strlen(s);
	for (int i = 0; i <len; i++)
	{
		if (check_apprearance[s[i]] == 0)						//该字符状态从未出现改变为出现
			check_apprearance[s[i]] = 1;
		else s[i] = '\0';													//否则将该字符置0
	}
	for (r=0,w=0; r <len; r++)										//将数组重新排列，使之成为一个字符串
	{
		if (s[r])
		{
			s[w++] = s[r];
		}
	}
	s[w] = '\0';
}
