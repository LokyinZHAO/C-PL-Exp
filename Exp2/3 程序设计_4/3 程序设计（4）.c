#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//�������� ����ʼ������������
	int day, k;
	k = 0;
	printf("����������\n");
	scanf_s("%d", &day);
	int sellings[50] = {0};
	
	//���������� ����������sellings��
	for (int  i = 0; i < day; i++)
	{
		scanf_s("%d", &sellings[i]);
	}

	//���μ��� �����ڹյ� k����
	for (int i = 2; i < day; i++)
	{
		if ((sellings[i] - sellings[i - 1]) * (sellings[i - 1] - sellings[i - 2]) < 0)
			k++;
	}

	//����յ���k
	printf("%d", k);

	system("pause");
	return 0;
}