#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void Input(char* name,int* score,int* numberofstd);
void SizeSort(char name[][10],int* score,int n);
void Output(char name[][10],int* score,int n);
#define MaxNumberofStd 30															//最大学生数
int main(void)
{
	printf("输入menu数字执行对应功能\n");
	printf("1.输入n(n<=30)个学生的姓名(不超过十个字节)和C语言课程的成绩\n");
	printf("2.将成绩按从高到低的次序排序\n");
	printf("3.输出所有学生的姓名和C语言课程的成绩\n");
	printf("0.退出程序\n");
	int choice;																						//记录选择
	scanf_s("%d", &choice);
	char name[MaxNumberofStd][10];												//声明字符串数组用于存储姓名
	int score[MaxNumberofStd] = { 0 };												//记录成绩 下标与姓名对应						
	int n = 0;																						//记录学生数
	do
	{
		switch (choice)
		{
		case 1:Input(&name[0][0],&score[0],&n); break;
		case 2:SizeSort(&name[0][0],&score[0],n); break;
		case 3:Output(&name[0][0], &score[0], n); break;
		case 0:return 0;
		}
		printf("______________________________\n菜单%d执行完毕，请继续执行菜单或退出（0）\n",choice);
		scanf_s("%d", &choice);
	} while (choice!=0);
	system("pause");
	return 0;
}

/****************************************************************************
函数原型：void Input(char* name,int* score,int* numberofstd);
函数作用：输入n(n<=30)个学生的姓名(不超过十个字节)和C语言课程的成绩\
参数说明：
				char* name:学生姓名表，应传入一个字符串数组的首地址，此为&name[][10]
				int* score:学生成绩表，应传入一个整型数组的首地址，此为&score[0]下标与name的第一个下标对应从而表示对应成绩
				int* numberofstd:学生数，应传入n的地址
****************************************************************************/
void Input(char* name, int* score, int* numberofstd)
{
	printf("输入学生数（不超过30）\n");
	scanf_s("%d", numberofstd);
	assert(*numberofstd <= 30);
	printf("输入学生姓名（不超过八字节）与其对应成绩（百分制）格式：\nTom 95 \n张三 66\n______________________________\n");
	for (int i = 0; i < *numberofstd; i++)
	{
		scanf("%s %d", &(name[i*10]), &score[i]);
	}	
	printf("______________________________\n");
}


/****************************************************************************
函数原型：void SizeSort(char* name,char* number,int n);
函数作用：将成绩按从高到低的次序排序
参数说明：
				char** name:学生姓名表，应传入一个字符串数组的首地址，此为&name[][10]
				int* score:学生成绩表，应传入一个整型数组的首地址，此为&score[0]下标与name的第一个下标对应从而表示对应成绩
				int n:学生数，应传入学生数量，此为主函数的n
****************************************************************************/
void SizeSort(char name[][10],int score[],int n)
{
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n-i;j++)
			if (score[j]<score[j+1])
			{
				char name_temp[10];
				strcpy_s(name_temp,10, name[j]);
				strcpy_s(&name[j][0], 10,&name[j + 1][0]);
				strcpy_s(&name[j + 1][0],10, name_temp);

				int score_temp;
				score_temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = score_temp;
				
			}
	}
	printf("已完成排序\n");
}

/****************************************************************************
函数作用：按序输出所有学生的姓名和C语言课程的成绩
参数说明：
				char** name:学生姓名表，应传入一个字符串数组的首地址，此为&name[][10]
				int* score:学生成绩表，	
****************************************************************************/
void Output(char name[][10], int* score, int n)
{
	printf("成绩表如下：\n");
	for (int i = 0; i < n; i++)
	{
		printf("%8s:%3d\n", name[i],score[i]);
	}
}
