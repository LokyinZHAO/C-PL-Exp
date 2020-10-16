#include<stdio.h>
#include<stdlib.h>
#define CHANGE 1


int main(void)
{
	char s[200];
	gets_s(s,200);																								//输入一行英文字符

#if CHANGE==0																								//CHANGE值为0时，执行该段代码，正常输出
	printf("%s", s);
#elif CHANGE==1																							//CHANGE值为1时，执行该段代码，大小写反转
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (s[i] <= 'Z' && s[i] >= 'A') s[i] = s[i] - 'A' + 'a';
		else if (s[i] <= 'z' && s[i] >= 'a') s[i] = s[i] - 'a' + 'A';
	}
	printf("%s", s);
#endif // 

	system("pause");
	return 0;
}