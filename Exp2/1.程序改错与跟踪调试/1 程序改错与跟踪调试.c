#include<stdio.h>
#define PI 3.14159															//#define宏定义后不加；否则PI视为字符串常量
int main(void)
{
	int f;
	unsigned short p, k;														//为保证k右移后高位补0，应使用unsigned类型
	double c, r, s;

	//任务一 输入华氏温度f，将它转化成摄氏温度c后输出
	printf("Input Fahrenheit:");
	scanf("%d",&f);																//scanf中f的赋值未取地址
	c = (5.0 / 9) * (f - 32);													//求摄氏度c的表达式中出现5/9结果为整型0再乘上任何数使得f都为0.00
	printf("\n %d (F)= %.2f (C)\n\n", f, c);

	//任务二 输入园的半径r， 计算并输出圆的面积s
	printf("Input the radius r:");
	scanf("%lf", &r);																//r为double类型 应使用lf
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);

	//任务三 讲k的高字节作为结果的低字节 p的高字节作为结果的低字节 拼成一个新的整数后输出
	short newint;																//未定义变量newint
	k = 0xa1b2, p = 0x8423;
	newint = p & 0xff00| k >> 8;//
	printf("new int = %#hx\n\n", newint);							//应指出输出的参数是短整型

	return 0;
}