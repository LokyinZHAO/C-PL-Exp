#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	int a, b, number;																//����ǰ��λ��a������λ��b�����ƺ�number
	float check;
	for (a=1;a<=9;a++)															//����ö�ٷ�
	{
		for ( b = 1; b < 10; b++)
		{
			if (a == b)continue;													//Ҫ��a������b
			number = a * 1000 + a * 100 + b * 10 + b;
			check = sqrt(number);
			if (check==(int)check)												//�����������˵��number�Ǹ�ƽ����
			{
				printf("����ĳ��ƺ�Ϊ\n%d\n", number);
			}
		}
	}
	system("pause");
	return 0;
}