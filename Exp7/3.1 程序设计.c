//unfinished
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define mask 0x00000001
void f0(int b);
void f1(int b);
void f2(int b);
void f3(int b);
void f4(int b);
void f5(int b);
void f6(int b);
void f7(int b);

struct  bits		//声明字段结构
{
	unsigned int bit0 : 1, bit1 : 1, bit2 : 1,bit3 : 1, bit4 : 1,bit5 : 1,bit6 : 1,bit7 : 1;
};
union par		//联合使得存储共用，从而得到每一位得值
{
	unsigned char ch;
	struct bits bit;
}sheet;
void (*p[8])(int) = { f0,f1,f2,f3,f4,f5,f6,f7 };

int main(void)
{
	printf("input a number to call funtions by its binary\n");
	scanf_s("%d", &sheet.ch);
	assert(sheet.ch >= 0 && sheet.ch <= 255);
	if (sheet.bit.bit0)		p[0](sheet.bit.bit0);
	if (sheet.bit.bit1)			p[1](sheet.bit.bit1);
	if (sheet.bit.bit2)		p[2](sheet.bit.bit2);
	if (sheet.bit.bit3)		p[3](sheet.bit.bit3);
	if (sheet.bit.bit4)		p[4](sheet.bit.bit4);
	if (sheet.bit.bit5)		p[5](sheet.bit.bit5);
	if (sheet.bit.bit6)		p[6](sheet.bit.bit6);
	if (sheet.bit.bit7)		p[7](sheet.bit.bit7);
	system("pause");
	return 0;
}

void f0(int b)
{
	printf("the function %d is called\n", b);
}

void f1(int b)
{
	printf("the function %d is called\n", b);
}

void f2(int b)
{
	printf("the function %d is called\n", b);
}

void f3(int b)
{
	printf("the function %d is called\n", b);
}

void f4(int b)
{
	printf("the function %d is called\n", b);
}

void f5(int b)
{
	printf("the function %d is called\n", b);
}

void f6(int b)
{
	printf("the function %d is called\n", b);
}

void f7(int b)
{
	printf("the function %d is called\n", b);
}
