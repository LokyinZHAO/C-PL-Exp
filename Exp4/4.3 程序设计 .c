#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define s(a,b,c) (((a)+(b)+(c))/2)
#define area(s,a,b,c) (sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c))))
int main(void)
{
	double a, b, c;
	printf("Input a,b,c to calculate the area\n");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	double area, s;
	s = s(a, b, c);
	area = area(s, a, b, c);
	printf("s=%.2f area=%.2f", s, area);
	system("pause");
	return 0;
}