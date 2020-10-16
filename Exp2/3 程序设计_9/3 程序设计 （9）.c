#include<stdio.h>
#include<stdlib.h>
enum {tobedeter,num,dot};																	//三个状态：tobedeter待定 num数字 dot点
int main(void)
{
	int state=tobedeter;																			//起始状态待定
	int number[4] = { 0 };																		//四个数组存放四节数字
	int flag = 1;																						//flag标记是否为合法IP
	int s = 1, k = 1;																					//s用于记录当前是第几节数字不应大于4  k用于标记当前节有几位数不应大于3
	char c;																								//c用于读取当前字符

	while ((c=getchar())!='\n')																	//读取到回车结束
	{
		if (c!='.'&&(c>'9'||c<'0')) flag = 0;													//c既不是数字也不是'.' 非法IP 
		
 		switch (state)																				//状态机
		{

//*******************************************************************************************************
		case tobedeter:																			//起始的待定状态
			if (c=='.')																					//第一个char不能为'.'
			{
				flag = 0;
			}
			else																							//若不为char则为数字 记录c到number[0]并转换到num状态
			{
				number[0] = c - '0';
				state = num;
			}
			break;																						//该状态结束
//*********************************************************************************************************
		case num:
			if (c == '.')																					//在num状态下读到'.'表示这个节数结束 s++ k清零 切换到dot状态
			{
				s++;
				k = 0;
				state = dot;
			}
			else if (k > 3) flag = 0;																//若这节数超过了3个数字 为非法IP
			else if (s > 4) flag = 0;																//若总节数大于4 为非法IP
			else																							//这节数将c计入 并且这结束的位数加一
			{
				number[s - 1] = number[s - 1] * 10 + c - '0';						//注意s从1开始计数
				k++;
			}
			if (number[s - 1] > 255) flag = 0;												//若这节数大于了255 为非法IP
			break;
//***********************************************************************************************************
		case dot:
			if (c == '.') flag = 0;																	//连续输入两个'.' 为非法IP
			else
			{
			 state = num;
			 number[s - 1] = number[s - 1] * 10 + c - '0';
			}
			break;
		}
	}

	if (flag && s == 4)																			//满足该条件即为合法IP
		printf("YES. %lu", number[0] << 24 | number[1] << 16 | number[2] << 8 | number[3]);
	else printf("NO");
	system("pause");
	return 0;
}