#include<stdio.h>
#include<stdlib.h>
void lineprint(int);														//������ӡÿһ�еĺ���

int main(void)
{
	printf("��ӡ�������:\n");
	int line;
	printf("                  1\n");										//ֱ�Ӵ�ӡ��һ��
	for (line=1 ; line< 10; line++)
	{
		lineprint(line);													//�ظ�ѭ�����øú����������10��
	}
	system("pause");
	return 0;
}

void lineprint(int i)
{	
		
	for (int k = 1; k < 10-i; k++)									//��ӡÿһ��֮ǰ�Ŀո�
	{
		printf("  ");
	}	
	int c = 1; printf("1   ");											//ֱ�Ӵ�ӡ��һ������1�Լ�����' ' 
	for (int j = 1; j <=i ; j++)										
	{
		c = c * (i - j + 1) / j;											//���ݹ�ʽ����
		printf("%d", c);
		if (c<10)															//����λ�������Ӧ�Ŀո���
		{
			printf("   ");
		}
		else if (c>=10&&c<100)
		{
			printf("  ");
		}
		else if(c>=100)
		{
			printf(" ");
		}

	}
	printf("\n");															//����
}
