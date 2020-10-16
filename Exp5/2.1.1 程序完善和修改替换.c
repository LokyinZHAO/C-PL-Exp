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
		if (s[r])										//s[r]非0表示未出现过，开始查找之后的重复数据
		{
			w = s[r];								//用w记录s[r]
			for (i = r + 1; i < len; i++)
			{
				if (w == s[i])						//查找到重复数据，将其置0
					s[i] = '\0';
			}
		}
	}

	for (r = w = 0; r < len; r++)			//将处理的数组重新排列，使之成为字符串
	{
		if (s[r])
		{
			s[w++] = s[r];
		}
	}
	s[w] = '\0';
}
