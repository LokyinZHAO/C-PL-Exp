//��1000�ڵ�����

#include<stdio.h>
#include<stdlib.h>


int	 isPerfect(int x)
{
	int y, s;
	for ( s = 0,y=1; y<=x/2; y++)							//yӦ<=x/2�ŷ�������
	{
		if (!(x % y)) s += y;
	}
	if (s==x)
	{
		return 1;
	}

	return 0;	
																							
}

int main()
{
	int	 a;
	printf("1000�ڵ������У�");
	for ( a  = 1; a  <= 1000; a ++)																								
	{
		if (isPerfect(a)) printf("%8d", a);
		
	}			
	return 0;																						
}