#include<stdio.h>
#include<stdlib.h>
#include<math.h>																		

int main(void)
{
	long x, y;																					//int i 未声明
	for (int  i = 0; i < 100000; i++)
	{
		x = sqrt(i + 100);																	
		y = sqrt(i + 268);
		if ((x*x==i+100)&&(y*y==i+268))				//缺少括号
		{
			printf("%d\n",i);																	//printf函数写成了print
		}
	}
	system("pause");
	return 0;
}