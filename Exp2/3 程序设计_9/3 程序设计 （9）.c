#include<stdio.h>
#include<stdlib.h>
enum {tobedeter,num,dot};																	//����״̬��tobedeter���� num���� dot��
int main(void)
{
	int state=tobedeter;																			//��ʼ״̬����
	int number[4] = { 0 };																		//�ĸ��������Ľ�����
	int flag = 1;																						//flag����Ƿ�Ϊ�Ϸ�IP
	int s = 1, k = 1;																					//s���ڼ�¼��ǰ�ǵڼ������ֲ�Ӧ����4  k���ڱ�ǵ�ǰ���м�λ����Ӧ����3
	char c;																								//c���ڶ�ȡ��ǰ�ַ�

	while ((c=getchar())!='\n')																	//��ȡ���س�����
	{
		if (c!='.'&&(c>'9'||c<'0')) flag = 0;													//c�Ȳ�������Ҳ����'.' �Ƿ�IP 
		
 		switch (state)																				//״̬��
		{

//*******************************************************************************************************
		case tobedeter:																			//��ʼ�Ĵ���״̬
			if (c=='.')																					//��һ��char����Ϊ'.'
			{
				flag = 0;
			}
			else																							//����Ϊchar��Ϊ���� ��¼c��number[0]��ת����num״̬
			{
				number[0] = c - '0';
				state = num;
			}
			break;																						//��״̬����
//*********************************************************************************************************
		case num:
			if (c == '.')																					//��num״̬�¶���'.'��ʾ����������� s++ k���� �л���dot״̬
			{
				s++;
				k = 0;
				state = dot;
			}
			else if (k > 3) flag = 0;																//�������������3������ Ϊ�Ƿ�IP
			else if (s > 4) flag = 0;																//���ܽ�������4 Ϊ�Ƿ�IP
			else																							//�������c���� �����������λ����һ
			{
				number[s - 1] = number[s - 1] * 10 + c - '0';						//ע��s��1��ʼ����
				k++;
			}
			if (number[s - 1] > 255) flag = 0;												//�������������255 Ϊ�Ƿ�IP
			break;
//***********************************************************************************************************
		case dot:
			if (c == '.') flag = 0;																	//������������'.' Ϊ�Ƿ�IP
			else
			{
			 state = num;
			 number[s - 1] = number[s - 1] * 10 + c - '0';
			}
			break;
		}
	}

	if (flag && s == 4)																			//�����������Ϊ�Ϸ�IP
		printf("YES. %lu", number[0] << 24 | number[1] << 16 | number[2] << 8 | number[3]);
	else printf("NO");
	system("pause");
	return 0;
}