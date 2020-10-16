#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(void)
{
	int a, b, c, d, e, f, g, h, i, j;
	int x;
	int m, n;																												//声明m为abcde，声明n为fghij
	int flag=0;
	printf("输入正整数x(2<=x<=79),输出所有形如abcde/fghij=x的表达式：\n");
	scanf_s("%d", &x);	
	assert(x >= 2 && x <= 79);																					//用断言防止输入不满足要求
	for ( a = 0; a < 10; a++)																						//从a~b依次枚举所有情况
	{
		for ( b = 0; b < 10; b++)
		{
			if (a == b)continue;
			for ( c = 0; c < 10; c++)
			{
				if ((c - a) * (c - b) == 0)continue;																//因为数不重复，若c=a或c=b直接跳过
				for ( d = 0; d < 10; d++)
				{
					if ((d - a) * (d - b) * (d - c) == 0)continue;
					for ( e = 0; e < 10; e++)
					{
						if ((e - a) * (e - b) * (e - c) * (e - d) == 0)continue;
						for ( f = 0; f < 10; f++)
						{
							if ((f - a) * (f - b) * (f - c) * (f - d) * (f - e) == 0)continue;
							for ( g = 0; g < 10; g++)
							{
								if ((g - a) * (g - b) * (g - c) * (g - d) * (g - e) * (g - f) == 0)continue;
								for ( h = 0; h < 10; h++)
								{
									if ((h - a) * (h - b) * (h - c) * (h - d) * (h - e) * (h - f) * (h - g) == 0)continue;
									for ( i = 0; i < 10; i++)
									{
										if ((i - a) * (i - b) * (i - c) * (i - d) * (i - e) * (i - f) * (i - g) * (i - h) == 0)continue;
										for ( j = 0; j < 10; j++)
										{
											if ((j - a) * (j - b) * (j - c) * (j - d) * (j - e) * (j - f) * (j - g) * (j - h) * (j - i) == 0)continue;
											m = 10000 * a + 1000 * b + 100 * c + 10 * d + e;
											n = 10000 * f + 1000 * g + 100 * h + 10 * i + j;													//为mn赋值
											if (m==n*x)																											//若满足条件则打印之
											{
												printf("%05d/%05d=%d\n", m, n, x);
												flag = 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (flag==0)
	{
		printf("无满足该条件的式子\n");																								//flag为0表示无满足条件的情况，输出该信息
	}
	system("pause");
	return 0;
}