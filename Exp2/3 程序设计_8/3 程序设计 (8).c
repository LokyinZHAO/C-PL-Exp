#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int letter=0, token=0, line=1;																					//��ʼ���ַ�tok ��let ��line
	char ch;

	while ((ch=getchar())!=EOF)																							//��ctrl z����
	{
		if (ch=='\n')
		{
			line++;
		}
		skip:
		if (ch >= 33 && ch <= 126)
		{
			token++;																										//cΪ�����ַ� �ַ���һ
			ch = getchar();
			if (ch == 9 || ch == 32 || ch == 10)
			{
				letter++;																									//�ո� TAB �س� �ּ�һ
				if (ch == 10)																							//�س������м�һ
				{
					line++;
				}
			}
			else
			{
				goto skip;
			}

		}
		if (ch<0)																											//c�����������ַ���ǰһ��Byte
		{
			if ((ch = getchar()) <0)																				//c�������ַ� �ַ����ּ�һ
			{
				letter++;
				token++;
			}
			else
			{
				token++;																									//c���������ַ� ������ͨ�ַ� �ַ���һ
			}
		}

		
	}	
	printf("��%d���ַ���%d���֡�%d��", token, letter, line-1);
	system("pause");
	return 0;
}