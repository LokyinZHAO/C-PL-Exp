#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//xΪ���ʽ�� mΪ˰����
	int x;
	float m;
	printf("���빤�ʽ�����˰����\n");
	scanf_s("%d", &x);

	switch (x/1000)
	{
	case 0:m = 0;				break;
	case 1:m = 0.05 * x;		break;
	case 2:m = 0.1 * x;		break;
	case 3:m = 0.15 * x;	   	break;
	case 4:m = 0.20 * x;		break;
	default:m = 0.25 * x;		break;
	}

	printf("˰��Ϊ%.2f\n", m);
	system("pause");
	return 0;
}