#include<stdio.h>
#include<stdlib.h>
#define CHANGE 1


int main(void)
{
	char s[200];
	gets_s(s,200);																								//����һ��Ӣ���ַ�

#if CHANGE==0																								//CHANGEֵΪ0ʱ��ִ�иöδ��룬�������
	printf("%s", s);
#elif CHANGE==1																							//CHANGEֵΪ1ʱ��ִ�иöδ��룬��Сд��ת
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (s[i] <= 'Z' && s[i] >= 'A') s[i] = s[i] - 'A' + 'a';
		else if (s[i] <= 'z' && s[i] >= 'a') s[i] = s[i] - 'a' + 'A';
	}
	printf("%s", s);
#endif // 

	system("pause");
	return 0;
}