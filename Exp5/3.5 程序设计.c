#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
void strnins(char[],char[],int);

int main(void)
{
	printf("�����ַ���s���ַ���t�Լ�����n�����ַ���s�����ַ���t�ĵ�n���ַ�����\n");
	char s[N], t[2*N];
	printf("�����ַ���t�����Ȳ�С��100��\n");
	gets_s(t, N);	
	printf("�����ַ���s�����Ȳ�С��100��\n");
	gets_s(s, N);
	int n;
	printf("����n\n");
	scanf_s("%d", &n);		//��ȡ��Ӧ�ı�������
	strnins(t, s, n);
	printf("%s", t);

	system("pause");
	return 0;
}

void strnins(char t[], char s[], int n)
{
	char temp[N];		//�����ַ�������temp���ڴ���t�󱻽ضϵĲ���
	int len_s = strlen(s), len_t = strlen(t);
	int token_t = 0; 
	for (int  i = n;i<=len_t; i++) temp[token_t++] = t[i];
	for (int i = 0; i <=len_s; i++)  t[n++] = s[i];		//��s����
	n--;
	int len_temp = strlen(temp);
	for (int i = 0; i <= len_temp; i++) t[n++] = temp[i];		//ͨ��temp��t���ضϵĲ��ָ�ԭ
	t[--n] = '\0';
}
 