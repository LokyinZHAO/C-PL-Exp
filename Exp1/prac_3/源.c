//求1000内的完数

#include<stdio.h>
#include<stdlib.h>


int	 isPerfect(int x)
{
	int y, s;
	for ( s = 0,y=1; y<=x/2; y++)							//y应<=x/2才符合题意
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
	printf("1000内的完数有：");
	for ( a  = 1; a  <= 1000; a ++)																								
	{
		if (isPerfect(a)) printf("%8d", a);
		
	}			
	return 0;																						
}