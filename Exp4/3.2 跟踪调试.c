#include<stdio.h>																	//��������ͷ�ļ�
#include<stdlib.h>
#include<assert.h>
#define R 1
int integer_fraction(float x);														//��������ԭ��
int main(void)
{
	float r, s;
	int s_integer = 0;
	printf("Input a number\n");
	scanf_s("%f", &r);
#ifdef R
	s = 3.1415926 * r * r;
	printf("area of round is :%f\n", s);
	s_integer = integer_fraction(s+0.5);										//s��Ӧ�룬��0.5��ȡ����1����Ӧ�ᣬ��0.5��ȡ����Ӱ��
	assert((s - s_integer) < 0.5);													//��s��С�����ִ���0.5ʱ���Գ���
	printf("the intger fraction of area is %d\n", s_integer);
#endif // R
	system("pause");
	return 0;
}


//�������ܣ���һ�������ͱ�������������
int integer_fraction(float x)
{
	int i = x;
	return i;
}
