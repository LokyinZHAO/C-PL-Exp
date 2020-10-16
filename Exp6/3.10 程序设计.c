#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void input(short a[]);
short* mul(short a[],short b[]);
void mystrrev(char* s,int n);
short a[210] = { 0 }, b[250] = { 0 };
short product[450] = { 0 };

int main(void)
{
	input(a);
	input(b);
	mul(a, b);
	int i;
	printf("the result is:\n");
	for (i = 399; i >= 0; i--)
	{
		if (product[i] != 0) break;
	}
	for (i; i >=0; i--)
	{
		assert(product[i] < 10&&product[i]>=0);
		printf("%d", product[i]);
	}
	system("pause");
	return 0;
}

void input(short a[])
{
	char a_s[201] = { 0 };
	printf("input an extra large integers to multiply\n");
	gets_s(a_s, 200);
	_strrev(a_s);
	for (int i = 0; i < 200; i++)
	{
		if (a_s[i])
		{
			a[i] = a_s[i] - '0';
		}
	}
}

short* mul(short a[], short b[])
{
	for (int i = 0; i < 200; i++)
	{
		short mul_bi[400] = { 0 };
		for (int  j = 0; j < 200; j++)
		{
			mul_bi[i + j] += a[j] * b[i];
		}
		for (int i = 0; i < 400; i++)
		{
			if (mul_bi[i]>9)
			{
				mul_bi[i + 1] += mul_bi[i] / 10;
				mul_bi[i] = mul_bi[i] % 10;
			}
			product[i] += mul_bi[i];
		}
	}
	for (int i = 0; i < 400; i++)
	{
		if (product[i] > 9)
		{
			product[i + 1] += product[i] / 10;
			product[i] = product[i] % 10;
		}
	}

	return NULL;
}

void mystrrev(char* s,int n)
{
	int i;
	for (i = 0; i < n && s[i] != '\0'; i++);
	i--;

}
