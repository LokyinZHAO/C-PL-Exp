#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	int closingprice=0, lastclosingprice=0, balance=0;								//声明今日收盘价closingprice,昨日收盘价lastclosingprice，差额balance
	printf("输入股票波动价格，计算最大波动值\n");
	while (scanf_s("%d",&closingprice)!=EOF)												//若今日与昨日的收盘价差值大于balance，则将该差值作为新balance

	{
		if (abs(lastclosingprice-closingprice)>balance)
		{
			balance = abs(lastclosingprice - closingprice);
		}			
		lastclosingprice = closingprice;															//今日收盘价赋给昨日收盘价，以进行新循环

	}
	printf("%d\n", balance);
	system("pause");
	return 0;
}
