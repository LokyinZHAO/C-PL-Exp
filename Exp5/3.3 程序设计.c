#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void Input(char* name, int* score, int* numberofstd);
void SizeSort(char name[][10], int* score, int n);
void Output(char name[][10], int* score, int n);
void Search(char name[][10], int* score, int n);
int left_search_for_menu4(char name[][10], int* score, int targ);
int right_search_for_menu4(char name[][10], int* score, int targ);

#define MaxNumberofStd 30															//���ѧ����
int main(void)
{
	printf("����menu����ִ�ж�Ӧ����\n");
	printf("1.����n(n<=30)��ѧ��������(������ʮ���ֽ�)��C���Կγ̵ĳɼ�\n");
	printf("2.���ɼ����Ӹߵ��͵Ĵ�������\n");
	printf("3.�������ѧ����������C���Կγ̵ĳɼ�\n");
	printf("4.����һ���ɼ�ֵ���в���\n");
	printf("0.�˳�����\n");
	int choice;																						//��¼ѡ��
	scanf_s("%d", &choice);
	char name[MaxNumberofStd][10];												//�����ַ����������ڴ洢����
	int score[MaxNumberofStd] = { 0 };												//��¼�ɼ� �±���������Ӧ						
	int n = 0;																						//��¼ѧ����
	do
	{
		switch (choice)
		{
		case 1:Input(&name[0][0], &score[0], &n); break;
		case 2:SizeSort(&name[0][0], &score[0], n); break;
		case 3:Output(&name[0][0], &score[0], n); break;
		case 4:Search(&name[0][0], &score[0], n); break;
		case 0:return 0;
		}
		printf("______________________________\n�˵�%dִ����ϣ������ִ�в˵����˳���0��\n", choice);
		scanf_s("%d", &choice);
	} while (choice != 0);
	system("pause");
	return 0;
}

/****************************************************************************
����ԭ�ͣ�void Input(char* name,int* score,int* numberofstd);
�������ã�����n(n<=30)��ѧ��������(������ʮ���ֽ�)��C���Կγ̵ĳɼ�\
����˵����
				char* name:ѧ��������Ӧ����һ���ַ���������׵�ַ����Ϊ&name[][10]
				int* score:ѧ���ɼ���Ӧ����һ������������׵�ַ����Ϊ&score[0]�±���name�ĵ�һ���±��Ӧ�Ӷ���ʾ��Ӧ�ɼ�
				int* numberofstd:ѧ������Ӧ����n�ĵ�ַ
****************************************************************************/
void Input(char* name, int* score, int* numberofstd)
{
	printf("����ѧ������������30��\n");
	scanf_s("%d", numberofstd);
	assert(*numberofstd <= 30);
	printf("����ѧ�����������������ֽڣ������Ӧ�ɼ����ٷ��ƣ���ʽ��\nTom 95 \n���� 66\n______________________________\n");
	for (int i = 0; i < *numberofstd; i++)
	{
		scanf("%s %d", &(name[i * 10]), &score[i]);
	}
	printf("______________________________\n");
}


/****************************************************************************
����ԭ�ͣ�void SizeSort(char* name,char* number,int n);
�������ã����ɼ����Ӹߵ��͵Ĵ�������
����˵����
				char** name:ѧ��������Ӧ����һ���ַ���������׵�ַ����Ϊ&name[][10]
				int* score:ѧ���ɼ���Ӧ����һ������������׵�ַ����Ϊ&score[0]�±���name�ĵ�һ���±��Ӧ�Ӷ���ʾ��Ӧ�ɼ�
				int n:ѧ������Ӧ����ѧ����������Ϊ��������n
****************************************************************************/
void SizeSort(char name[][10], int score[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
			if (score[j] < score[j + 1])
			{
				char name_temp[10];
				strcpy_s(name_temp, 10, name[j]);
				strcpy_s(&name[j][0], 10, &name[j + 1][0]);
				strcpy_s(&name[j + 1][0], 10, name_temp);

				int score_temp;
				score_temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = score_temp;

			}
	}
	printf("���������\n");
}

/****************************************************************************
����ԭ�ͣ�void Output(char name[][10], int* score, int n);
�������ã������������ѧ����������C���Կγ̵ĳɼ�
����˵����
				char** name:ѧ��������Ӧ����һ���ַ���������׵�ַ����Ϊ&name[][10]
				int* score:ѧ���ɼ���Ӧ����һ������������׵�ַ����Ϊ&score[0]�±���name�ĵ�һ���±��Ӧ�Ӷ���ʾ��Ӧ�ɼ�
				int n:ѧ������Ӧ����ѧ����������Ϊ��������n
****************************************************************************/
void Output(char name[][10], int* score, int n)
{
	printf("�ɼ������£�\n"); 
	for (int i = 0; i < n; i++)
	{
		printf("%8s:%3d\n", name[i], score[i]);
	}
}
/****************************************************************************
����ԭ�ͣ�void Search(char name[][10], int* score, int n);
�������ã�����һ���ɼ�ֵ���ж��ֲ��ҡ������ҵ������ѧ�������ͳɼ����������not found!
����˵����
				char** name:ѧ��������Ӧ����һ���ַ���������׵�ַ����Ϊ&name[][10]
				int* score:ѧ���ɼ���Ӧ����һ������������׵�ַ����Ϊ&score[0]�±���name�ĵ�һ���±��Ӧ�Ӷ���ʾ��Ӧ�ɼ�
				int n:ѧ������Ӧ����ѧ����������Ϊ��������n
****************************************************************************/
void Search(char name[][10], int* score, int n)
{
	printf("����һ���ɼ�ֵ���ж��ֲ��ҡ������ҵ������ѧ�������ͳɼ����������not found!\n");
	int search_score;
	scanf_s("%d", &search_score);
	int front = 0, back = n - 1, middle;
	while (front <=back)
	{
		middle = (front + back) / 2;
		if (search_score > score[middle]) back = middle - 1;
		else if (search_score < score[middle]) front = middle + 1;
		else
		{
			printf("found!\n%s:%d\n", name[middle], score[middle]);
			left_search_for_menu4(&name[middle][0], &score[middle], score[middle]);	
			right_search_for_menu4(&name[middle][0], &score[middle], score[middle]);
			return;
		}
	}
	printf("not found!\n");
	return;
}
/****************************************************************************
����ԭ�ͣ�int left_search_for_menu4(char name[][10], int* score, int targ);
�������ã���Search�����������ҵ�Ŀ�꣬������߲����Ƿ�����ͬ�ɼ���������©
����˵����
				char** name:ѧ��������Ӧ����һ���ַ���������׵�ַ����Ϊ&name[][10]
				int* score:ѧ���ɼ���Ӧ����һ������������׵�ַ����Ϊ&score[0]�±���name�ĵ�һ���±��Ӧ�Ӷ���ʾ��Ӧ�ɼ�
				int targ:ѧ���ɼ����˴�Ӧ����score[middle]
****************************************************************************/
int left_search_for_menu4(char name[][10], int* score, int targ)
{
	if (score[-1]==targ)
	{
		printf("%s:%d\n", name[-1], score[-1]);
		left_search_for_menu4(&name[-1][0], &score[-1], targ);
		return 1;
	}
	else	return 0;
}
/****************************************************************************
����ԭ�ͣ�int right_search_for_menu4(char name[][10], int* score, int targ);
�������ã���Search�����������ҵ�Ŀ�꣬�����ұ߲����Ƿ�����ͬ�ɼ���������©
����˵����
				char** name:ѧ��������Ӧ����һ���ַ���������׵�ַ����Ϊ&name[][10]
				int* score:ѧ���ɼ���Ӧ����һ������������׵�ַ����Ϊ&score[0]�±���name�ĵ�һ���±��Ӧ�Ӷ���ʾ��Ӧ�ɼ�
				int targ:ѧ���ɼ����˴�Ӧ����score[middle]
****************************************************************************/
int right_search_for_menu4(char name[][10], int* score, int targ)
{
	if (score[1] == targ)
	{
		printf("%s:%d\n", name[1], score[1]);
		right_search_for_menu4(&name[1][0], &score[1], targ);
		return 1;
	}
	else	return 0;
}
