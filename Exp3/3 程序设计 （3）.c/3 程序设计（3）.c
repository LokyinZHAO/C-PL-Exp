#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char ch,lastch=0;
	printf("����������ĸ��Ƶ���������ƹ����н�ÿ�������Ķ���ո��滻Ϊһ���ո�\n");
	while ((ch = getchar()) != EOF)																		//�ظ�ѭ�������ַ� ֱ������EOF����
	{

		if (ch==' ')																								//������' ' �������ظ����롮 �� ��״̬���������
		{
			putchar(' ');
			while ((ch = getchar()) == ' ');
			putchar(ch);
		}
		else
		{
			putchar(ch);																							//��������¸����������
		}
	}
	
	system("pause");
	return 0;
}