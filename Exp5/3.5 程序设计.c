#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
void strnins(char[],char[],int);

int main(void)
{
	printf("输入字符串s和字符串t以及整数n，将字符串s插入字符串t的第n个字符后面\n");
	char s[N], t[2*N];
	printf("输入字符串t（长度不小于100）\n");
	gets_s(t, N);	
	printf("输入字符串s（长度不小于100）\n");
	gets_s(s, N);
	int n;
	printf("输入n\n");
	scanf_s("%d", &n);		//读取相应的变量参数
	strnins(t, s, n);
	printf("%s", t);

	system("pause");
	return 0;
}

void strnins(char t[], char s[], int n)
{
	char temp[N];		//声明字符型数组temp用于储存t后被截断的部分
	int len_s = strlen(s), len_t = strlen(t);
	int token_t = 0; 
	for (int  i = n;i<=len_t; i++) temp[token_t++] = t[i];
	for (int i = 0; i <=len_s; i++)  t[n++] = s[i];		//将s插入
	n--;
	int len_temp = strlen(temp);
	for (int i = 0; i <= len_temp; i++) t[n++] = temp[i];		//通过temp将t被截断的部分复原
	t[--n] = '\0';
}
 