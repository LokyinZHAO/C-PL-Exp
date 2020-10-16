//原问题中的出圈等价于对将要出圈的人做上标记，当被标记的人报数时，N++
#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 10
int main(void)
{
	int a[M];																//数组a下标表示初始编号，其值表示是否在圈中
	int i, j;
	for (int i = 0; i < M; i++)										//对圈中人按从1至M,1表示在圈中，0表示出圈
		a[i] = 1 ;
	for (i = M, j = 0; i > 1; i--)									//i表示圈中人数，初始为M，剩1人时结束循环，j为当前报数人得位置
	{
		for (int k = 1,n=N; k <= n; k++)						//未出圈的人从1开始报数，报到n为止
		{
			if (++j >=M )												//报数超过M时从一开始循环报数（由于n的增加，实际时超过i）
				j = 0;
			if (a[j-1] == 0)												//遇到标记的人，n++
			{
				n++;
			}
		}
		if (j)																	//由于j=M时设位0，需特殊处理
		{
		a[j-1] = 0;
		printf("%5d", j);
		}
		else
		{
			a[M-1] = 0;
			printf("%5d", M);
		}

	}
	for (int i = 0; i < M; i++)										//输出唯一一个还未被标记的人，即最后的幸存者
		if (a[i])
		{
			printf("%5d\n", i+1);
		}
	system("pause");
	return 0;
}