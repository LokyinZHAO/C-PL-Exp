#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 10
int main(void)
{
	int a[M], b[M];														//数组a存放圈中人编号，数组b存放出圈人编号
	int i, j, k;
	for (int  i = 0; i < M; i++)										//对圈中人按从1至M顺序编号
		a[i] = i + 1;
	for (i=M,j=0;i>1;i--)												//i表示圈中人数，初始为M，剩1人时结束循环，j为当前报数人得位置
	{
		for (k=1;k<=N;k++)											//从1开始报数，报到N为止
			if (++j > i - 1) j = 0;										//最后一个人报数后第一个人接着报，形成一个圈
			b[M - i] = j ? a[j-1]:a[i-1] ;							//如果不是最后一个人报N，则直接出圈人编号j-1；若恰好最后一个人报N则出圈，不能用j-1（此时j为0），应用i-1表示最后一个人
			if (j)
				for (k = --j; k < i; k++)
					a[k] = a[k + 1];										//有人出圈以后数组a要重新排
	}
	for (int i = 0; i < M-1; i++)									//按次序输出出圈人得编号
	{
		printf("%6d", b[i]);
	}
	printf("%6d\n", a[0]);												//输出最后一个出圈人得编号
	system("pause");
	return 0; 
}