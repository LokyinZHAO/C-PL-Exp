#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char c, numchar, numline;
	numchar = 0;
	numline = 0;
	printf("���������ı���ctrl+z����\n");
	while ((c = getchar()) != EOF)								//ԭ����while (c = getchar() != EOF)�������ȼ���������ִ��!=
	{
		numchar++;
		if (c == '\n')
		{
			numline++;
		};
	};
	printf("�ַ�����%d\n", numchar);
	printf("������%d\n",numline);
	system("pause");
	return 0;
}