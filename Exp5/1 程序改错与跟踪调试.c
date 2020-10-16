#include<stdio.h>
#include<stdlib.h>
void strcate(char[], char[]);
void strdelc(char[], char);

int main(void)
{
	char a[] = "Language", b[] = "Programming";
	printf("%s %s\n", b, a);
	strcate(b, a);
	printf("%s %s\n", b, a);
	strdelc(b, 'a');
	printf("%s\n", b);

	system("pause");
	return 0;
}

void strcate(char t[], char s[])
{
	int i = 0, j = 0;
	while (t[i++]);
	i--;																							//第一个while使用后置式自增，在读到'\0'时还自增一次，故'\0'未被修改，需i-1
	while ((t[i++] = s[j++]) != '\0');
}

void strdelc(char s[], char c)
{
	int j, k;
	for (j=k=0;s[j]!='\0';j++)
		if (s[j] != c) 
			s[k++] = s[j];
	s[k] = '\0';																					//应在字符串末尾接上一个'\0'表示字符串结束
}
