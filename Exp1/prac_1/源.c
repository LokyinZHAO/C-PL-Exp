#include<stdio.h>
#include<stdlib.h>
#include<math.h>																		

int main(void)
{
	long x, y;																					//int i δ����
	for (int  i = 0; i < 100000; i++)
	{
		x = sqrt(i + 100);																	
		y = sqrt(i + 268);
		if ((x*x==i+100)&&(y*y==i+268))				//ȱ������
		{
			printf("%d\n",i);																	//printf����д����print
		}
	}
	system("pause");
	return 0;
}