#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("˫������ʮ�غ�ս��������ֵ֮��С��1000�ĸ���Ϊ:\n");
	int flag = 0;																											//����flag��¼������������������Ĵ���
	int round[5] ;
	for( round[1] = 0; round[1] < 2; round[1]++)														//round�±�Ϊ������1��ʾaӮ����֮��bӮ����˿������е�16�����
		{
			for (round[2] = 0; round[2] < 2; round[2]++)
			{
				for (round[3] = 0; round[3] < 2; round[3]++)
				{
					for (round[4] = 0; round[4] < 2; round[4]++)
					{
						int hp = 1000;																					//����Ѫ��Ϊ3000��ֻ�����a��Ѫ��hp��b��Ѫ��Ϊ(3000-hp)
						for (int  i = 1; i < 5; i++)																	//ģ��������ֱ���
						{
							hp = hp + round[i] * (3000 - hp)*0.25 - (!round[i]) * hp*0.25;		//hp����round��ֵ�������������Ѫ���Ӽ�
						}	
						if (hp>1000&&hp<2000)																	//�����������abѪ����С��1000
							{
								flag++;
							}

					}
				}
			}
		}

	printf("%.4f\n", flag / 16.0);																					//������ʲ����
	system("pause");
	return 0;
}