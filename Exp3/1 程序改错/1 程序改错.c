#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i, x, k, flag;
	printf("�������жϺ��������������1��������Ctrl+z����\n");
	while (scanf_s("%d", &x) != EOF)
	{
		flag = 0;																					//flagӦ�ڴ˴���ʼ������ԭλ��ֻ���ʼ��һ�Σ������߼�����

		for (i = 2, k = x >> 1; i <= k; i++)
			if (!(x % i))																				//�߼���!�������ȼ���ȡ��%���ȼ���Ӧ��x%i������
			{
				flag = 1;
				break;
			}
		if (flag == 1)		printf("%d �Ǻ���\n", x);									//�ж����Ӧ�ù�ϵ�����==
		else printf("%d ���Ǻ���\n", x);
	}
	return 0;
}
	

