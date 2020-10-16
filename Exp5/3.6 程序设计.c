#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int line_check( int board[],int flag[] );
int row_check( int board[], int flag[]);
int main(void)
{
	printf("棋盘消除游戏\n");
	int n, m;
	printf("输入棋盘的行数n和列数m(不大于10)\n");												//n表示总行数，m表示总列数
	scanf_s("%d %d", &n, &m);
	assert(n >= 3 && m >= 3);
	int board[10][10];
	printf("按行输入棋盘(1~9)，回车结束一行：\n");
	for (int line = 0; line <n ; line++)																		//line表示行，row表示列
	{
		for (int row = 0; row < m; row++)
		{
			scanf_s("%d", &board[line][row]);
			assert(board[line][row] >= 1 && board[line][row] <= 9);
		}
	}																														//获得棋盘
	//复制一个棋盘，置为1，若可被消则置为0
	int flag[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			flag[i][j] = 1;
	}

	//检查每行是否横向可消
	for (int line = 0; line < n; line++)
	{
		for (int row = 1; row < m - 1; row++)
		{
			line_check(&board[line][row], &flag[line][row]);
		}
	}

	//检查每列是否竖向可消
	for (int row = 0; row < m; row++)
	{
		for (int line = 1; line < n - 1; line++)
		{
			row_check(&board[line][row], &flag[line][row], m);
		}
	}

	//打印结果
	printf("/////////////消消乐///////////////\n");
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



//输入棋盘上一个值的坐标（line，row），以及其值，检查其左右的数是否相同，若是，返回1，否则返回0
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
