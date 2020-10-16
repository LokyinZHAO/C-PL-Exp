#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char u[] = "UVWXYZ", v[] = "xyz";
	struct T
	{
		int x;
		char c;
		char* t;
	}a[] = { {11,'A',u},{100,'B',v} }, * p = a;
	printf("1.	(++p)->x\n");
	printf("%d\n", (++p)->x);
	p = a;
	printf("\n");
	printf("2.	p++,p->c\n");
	printf("%c\n", (p++, p->c));
	p = a;
	printf("\n");
	printf("3.	*p++->t,*p->t\n");
	printf("%c\n", (*p++->t, *p->t));
	p = a;
	printf("\n");
	printf("4.	*(++p)->t\n");
	printf("%c\n", *(++p)->t);
	p = a;
	printf("\n");
	printf("5.	*++p->t\n");
	printf("%c\n", *++p->t);
	p = a;
	p->t--;
	printf("\n");
	printf("6.	++*p->t\n");
	printf("%c\n", ++* p->t);
	system("pause");
	return 0;
}