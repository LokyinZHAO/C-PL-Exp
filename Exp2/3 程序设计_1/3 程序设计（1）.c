//�����ַ�c ��c�Ǵ�д ת����Сд ����c����
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char c;
	c = getchar();
	putchar((c>='A'&&c<='Z')?c+'a'-'A':c);
	system("pause");
	return 0;
}