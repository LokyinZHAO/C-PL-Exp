#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
int check_self_power(int,int);

int main(void)
{
	int k;																														//声明k位数
	printf("输入位数，计算该位数中所有的自幂数：\n");
	scanf_s("%d", &k);

	do																														//循环读入k
	{
		int dom[1000];																									//声明数组dom用于存储满足条件的数
		for (int i = 0; i < 1000; i++)																				//初始化dom为-1
		{
			dom[i] = -1;
		}
		int count = 0;																									//声明count用于计数，
		assert(k >= 0 && k <= 8);
		for (int i = pow(10, (k - 1)); i < pow(10, k); i++)												//依次检验
		{
			if (check_self_power(i, k) == 1)
			{
				dom[count++] = i;
			}
		}
		switch (k)																											//根据k值相应说明
		{
		case 0:return 0;
		case 3:printf("三位的水仙花数共有%d个：", count + 1); break;
		case 4:printf("四位的四叶玫瑰数共有%d个：", count + 1); break;
		case 5:printf("五位的五角星数共有%d个：", count + 1); break;
		case 6:printf("六位的六合数共有%d个：", count + 1); break;
		case 7:printf("七位的北斗七星数共有%d个：", count + 1); break;
		case 8:printf("八位的八仙数共有%d个：", count + 1); break;
		}
		for (int i = 0; dom[i] != -1; i++)																		//输出满足条件的数
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
	int b = x;																					//保存x的值 
	int sum = 0, a = 0, i;
	while (b!=0)
	{
		a = b % 10;																			//a取个位
		b /= 10;																				//b减少一位
		sum += pow((double)a, n);		
	}


	if (sum == x) return 1;
	else return 0;
}

