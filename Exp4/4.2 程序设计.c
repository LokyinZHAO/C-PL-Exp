#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
int check_self_power(int,int);

int main(void)
{
	int k;																														//����kλ��
	printf("����λ���������λ�������е���������\n");
	scanf_s("%d", &k);

	do																														//ѭ������k
	{
		int dom[1000];																									//��������dom���ڴ洢������������
		for (int i = 0; i < 1000; i++)																				//��ʼ��domΪ-1
		{
			dom[i] = -1;
		}
		int count = 0;																									//����count���ڼ�����
		assert(k >= 0 && k <= 8);
		for (int i = pow(10, (k - 1)); i < pow(10, k); i++)												//���μ���
		{
			if (check_self_power(i, k) == 1)
			{
				dom[count++] = i;
			}
		}
		switch (k)																											//����kֵ��Ӧ˵��
		{
		case 0:return 0;
		case 3:printf("��λ��ˮ�ɻ�������%d����", count + 1); break;
		case 4:printf("��λ����Ҷõ��������%d����", count + 1); break;
		case 5:printf("��λ�������������%d����", count + 1); break;
		case 6:printf("��λ������������%d����", count + 1); break;
		case 7:printf("��λ�ı�������������%d����", count + 1); break;
		case 8:printf("��λ�İ���������%d����", count + 1); break;
		}
		for (int i = 0; dom[i] != -1; i++)																		//���������������
		{
			printf("%d", dom[i]);
			if (dom[i + 1] != -1)printf(",");
			else printf("\n");
		}

		scanf_s("%d", &k);
	} while (k!=0);


	system("pause");
	return 0;
}

int check_self_power(int x,int n)
{
	int b = x;																					//����x��ֵ 
	int sum = 0, a = 0, i;
	while (b!=0)
	{
		a = b % 10;																			//aȡ��λ
		b /= 10;																				//b����һλ
		sum += pow((double)a, n);		
	}


	if (sum == x) return 1;
	else return 0;
}

