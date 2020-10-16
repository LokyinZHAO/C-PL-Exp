#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int line_check( int board[],int flag[] );
int row_check( int board[], int flag[]);
int main(void)
{
	printf("����������Ϸ\n");
	int n, m;
	printf("�������̵�����n������m(������10)\n");												//n��ʾ��������m��ʾ������
	scanf_s("%d %d", &n, &m);
	assert(n >= 3 && m >= 3);
	int board[10][10];
	printf("������������(1~9)���س�����һ�У�\n");
	for (int line = 0; line <n ; line++)																		//line��ʾ�У�row��ʾ��
	{
		for (int row = 0; row < m; row++)
		{
			scanf_s("%d", &board[line][row]);
			assert(board[line][row] >= 1 && board[line][row] <= 9);
		}
	}																														//�������
	//����һ�����̣���Ϊ1�����ɱ�������Ϊ0
	int flag[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			flag[i][j] = 1;
	}

	//���ÿ���Ƿ�������
	for (int line = 0; line < n; line++)
	{
		for (int row = 1; row < m - 1; row++)
		{
			line_check(&board[line][row], &flag[line][row]);
		}
	}

	//���ÿ���Ƿ��������
	for (int row = 0; row < m; row++)
	{
		for (int line = 1; line < n - 1; line++)
		{
			row_check(&board[line][row], &flag[line][row], m);
		}
	}

	//��ӡ���
	printf("/////////////������///////////////\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flag[i][j]==0)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", board[i][j]);
			}
		}
		printf("\n");
	}

	system("pause");
	return 0;
}



//����������һ��ֵ�����꣨line��row�����Լ���ֵ����������ҵ����Ƿ���ͬ�����ǣ�����1�����򷵻�0
int line_check(int board[], int flag[])
{
	if (board[-1] == board[0] && board[1] == board[0])
	{
		flag[-1] = 0;
		flag[0] = 0;
		flag[1] = 0;
		return 1;
	}
	return 0;
}


int row_check(int board[], int flag[])
{
	if (board[-10]==board[0]&&board[10]==board[0])
	{
		flag[-10] = 0;
		flag[0] = 0;
		flag[10] = 0;
		return 1;
	}
	return 0;
}
