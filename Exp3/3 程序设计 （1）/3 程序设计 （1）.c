#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//xΪ���ʽ�� mΪ˰����
	int x ;
	float m;

	printf("���빤�ʽ�����˰����\n");
	scanf_s("%d", &x);
	if (x<1000)
	{
		m = 0;
	}
	else if (1000<=x&&x<2000)
	{
		m = 0.05 * x;
	}
	else if (2000<=x&&x<3000)
	{
		m = 0.1 * x;
	}
	else if (3000 <= x && x < 4000)
	{
		m = 0.15 * x;
	}
	else if (4000 <= x && x < 5000)
	{
		m = 0.20 * x;
	}
	else if (x >= 5000)
	{
		m = 0.25 * x;
	}
	printf("˰��Ϊ%f" ,m);
	system("pause");
	return 0;
}