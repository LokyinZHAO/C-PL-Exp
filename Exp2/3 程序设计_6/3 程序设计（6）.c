#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned long x;

	while (scanf_s("%lu",&x) != EOF)
	{
		int a, b, c, d;

		a = (x & 0xff000000)>>24;
		b = (x & 0x00ff0000)>>16;
		c = (x & 0x0000ff00)>>8;
		d = x & 0x000000ff;
		printf("%d.%d.%d.%d\n", a, b, c, d);
		
		

	}
	system("pause");
	return 0;
}