#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//��ʼ������
	int year, month, day,d;
	scanf_s("%d %d", &year, &d);
	day = d;

	//�г�ÿ�µ�����
	int month_day[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

	//�ж�����
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		month_day[2]++;
	}

	//d���μ�ȥÿ�µ�����
	for ( month = 1; d >month_day[month]; month++)
	{
		d -= month_day[month];
	}
	printf("%d��ĵ�%d����%d��%d��",year,day,month,d );
	system("pause");
	return 0;
}
