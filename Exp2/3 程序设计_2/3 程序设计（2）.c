//����һ���������������Ǽ�λ�����������ĸ�λ����֮��
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("����һ���������������Ǽ�λ�����������ĸ�λ����֮��\n");
	int n, k, s, n0;
	s = 0;
	scanf_s("%d", &n);
	n0 = n;
	for ( k = 0; n; k++)
	{
		s += n % 10;
		n /= 10;
	}
	printf("%d��%dλ������λ����֮��Ϊ%d", n0, k, s);
	system("pause");
	return 0;
}