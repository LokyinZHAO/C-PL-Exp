#include<stdio.h>
#define PI 3.14159															//#define�궨��󲻼ӣ�����PI��Ϊ�ַ�������
int main(void)
{
	int f;
	unsigned short p, k;														//Ϊ��֤k���ƺ��λ��0��Ӧʹ��unsigned����
	double c, r, s;

	//����һ ���뻪���¶�f������ת���������¶�c�����
	printf("Input Fahrenheit:");
	scanf("%d",&f);																//scanf��f�ĸ�ֵδȡ��ַ
	c = (5.0 / 9) * (f - 32);													//�����϶�c�ı��ʽ�г���5/9���Ϊ����0�ٳ����κ���ʹ��f��Ϊ0.00
	printf("\n %d (F)= %.2f (C)\n\n", f, c);

	//����� ����԰�İ뾶r�� ���㲢���Բ�����s
	printf("Input the radius r:");
	scanf("%lf", &r);																//rΪdouble���� Ӧʹ��lf
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);

	//������ ��k�ĸ��ֽ���Ϊ����ĵ��ֽ� p�ĸ��ֽ���Ϊ����ĵ��ֽ� ƴ��һ���µ����������
	short newint;																//δ�������newint
	k = 0xa1b2, p = 0x8423;
	newint = p & 0xff00| k >> 8;//
	printf("new int = %#hx\n\n", newint);							//Ӧָ������Ĳ����Ƕ�����

	return 0;
}