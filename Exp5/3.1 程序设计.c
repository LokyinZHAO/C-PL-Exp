#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("����һ�����������ַ�������ʽ����������\n");
	int x;
	scanf_s("%d", &x);
	char dec[32];																			//����һ��32λ���ַ��������Ŷ�����

	if (x==0)																					//0�����⴦��
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < 32; i++)															//���н���ת��
	{
		dec[i] = (x&0x00000001)+'0';
		x /=2;
	}

	for (int i = 31;i>=0 ; i--)															//�������0��'f'����������
	{
		if (dec[i] == '0') dec[i] = 'f';
		else break;
	}

	for (int i = 31; i>=0; i--)															//�����ӡ���ַ����飬ֱ���������'f'���Ӷ��ĵ���ȷ�Ķ�����
	{
		if (dec[i] != 'f')	 printf("%c", dec[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}