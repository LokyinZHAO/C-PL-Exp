#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//初始化变量
	int year, month, day,d;
	scanf_s("%d %d", &year, &d);
	day = d;

	//列出每月的天数
	int month_day[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

	//判断闰年
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		month_day[2]++;
	}

	//d依次减去每月的天数
	for ( month = 1; d >month_day[month]; month++)
	{
		d -= month_day[month];
	}
	printf("%d年的第%d天是%d月%d日",year,day,month,d );
	system("pause");
	return 0;
}
