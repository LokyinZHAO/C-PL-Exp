#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//����xmn
	unsigned short x, m, n;
	printf("Input x \n");
	scanf("%hx", &x);
	printf("Input m and n\n");
	scanf("%hd %hd", &m, &n);

	//���mn�ķ�Χ
	if (m<0||m>15)
	{
		printf("mӦ���ڵ���0С�ڵ���15");
		return 0;
	}
	if (n<1||n>16-m)
	{
		printf("nӦ���ڵ���1 С�ڵ���16-m");
		return 0;
	}

	//��λ����
	x = (x << (16 - (m + n))) & ((~(~0 << n)) << (16 - n));

	printf("%hx", x);
	system("pause");
	return 0;
}