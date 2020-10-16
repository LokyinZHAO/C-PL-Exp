#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void scheduler();
void execute(void (*p[])(),int n);
void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void (*task[8])() = { task0,task1,task2,task3,task4,task5,task6,task7 };

int main(void)
{
	printf("input the order of the menu\n");
	scheduler();
	system("pause");
	return 0;
}

void scheduler()
{
	char caller[30];
	gets_s(caller, 29);
	void (*fcall[30])();
	int len = strlen(caller);
	for(int i=0;i<len;i++)
	{
		fcall[i] = task[caller[i] - '0'];
	}
	execute(fcall, len);
	return;
}

void execute(void(*p[])(), int n)
{
	for (int i = 0; i < n; i++)
	{
		p[i](); 
	}
}

void task0()
{
	printf("task0 is called!\n");
}

void task1()
{
	printf("task1 is called!\n");
}

void task2()
{
	printf("task2 is called!\n");
}

void task3()
{
	printf("task3 is called!\n");
}

void task4()
{
	printf("task4 is called!\n");
}

void task5()
{
	printf("task5 is called!\n");
}

void task6()
{
	printf("task6 is called!\n");
}

void task7()
{
	printf("task7 is called!\n");
}
