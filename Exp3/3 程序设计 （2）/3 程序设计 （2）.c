#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	int closingprice=0, lastclosingprice=0, balance=0;								//�����������̼�closingprice,�������̼�lastclosingprice�����balance
	printf("�����Ʊ�����۸񣬼�����󲨶�ֵ\n");
	while (scanf_s("%d",&closingprice)!=EOF)												//�����������յ����̼۲�ֵ����balance���򽫸ò�ֵ��Ϊ��balance

	{
		if (abs(lastclosingprice-closingprice)>balance)
		{
			balance = abs(lastclosingprice - closingprice);
		}			
		lastclosingprice = closingprice;															//�������̼۸����������̼ۣ��Խ�����ѭ��

	}
	printf("%d\n", balance);
	system("pause");
	return 0;
}
