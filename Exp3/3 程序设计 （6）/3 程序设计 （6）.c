#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("双方进行十回合战斗后，体力值之差小于1000的概率为:\n");
	int flag = 0;																											//声明flag记录所有情况中满足条件的次数
	int round[5] ;
	for( round[1] = 0; round[1] < 2; round[1]++)														//round下标为局数，1表示a赢，反之则b赢，如此考虑所有的16种情况
		{
			for (round[2] = 0; round[2] < 2; round[2]++)
			{
				for (round[3] = 0; round[3] < 2; round[3]++)
				{
					for (round[4] = 0; round[4] < 2; round[4]++)
					{
						int hp = 1000;																					//因总血量为3000，只需计算a的血量hp，b的血量为(3000-hp)
						for (int  i = 1; i < 5; i++)																	//模拟进行四轮比赛
						{
							hp = hp + round[i] * (3000 - hp)*0.25 - (!round[i]) * hp*0.25;		//hp根据round的值即比赛结果进行血量加减
						}	
						if (hp>1000&&hp<2000)																	//满足该条件即ab血量差小于1000
							{
								flag++;
							}

					}
				}
			}
		}

	printf("%.4f\n", flag / 16.0);																					//计算概率并输出
	system("pause");
	return 0;
}