#include<stdio.h>																	//声明引用头文件
#include<stdlib.h>
#include<assert.h>
#define R 1
int integer_fraction(float x);														//声明函数原型
int main(void)
{
	float r, s;
	int s_integer = 0;
	printf("Input a number\n");
	scanf_s("%f", &r);
#ifdef R
	s = 3.1415926 * r * r;
	printf("area of round is :%f\n", s);
	s_integer = integer_fraction(s+0.5);										//s若应入，加0.5后取整进1；若应舍，加0.5后取整无影响
	assert((s - s_integer) < 0.5);													//当s的小数部分大于0.5时断言成立
	printf("the intger fraction of area is %d\n", s_integer);
#endif // R
	system("pause");
	return 0;
}


//函数功能：求一个浮点型变量的整数部分
int integer_fraction(float x)
{
	int i = x;
	return i;
}
