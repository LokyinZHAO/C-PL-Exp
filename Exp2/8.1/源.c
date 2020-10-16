#include<stdio.h>
#include<stdlib.h>
enum { TOBEDETER, CHINESE, WESTCHAR,BLANKSPACE };
#define isChinese ch<0
#define isWestchar ch >= 33 && ch <= 126
#define isblankspace ch=='\n'||ch=='\t'||ch==' '

int main(void)
{
	int letter = 0, token = 0, line = 1;
	char ch;
	int state = TOBEDETER;

	while ((ch=getchar)!=EOF)
	{
		switch (state)
		{
//______________________________________________________________________________
		case TOBEDETER:
			if (isWestchar)
			{
				letter++;
				state = WESTCHAR;
			}
			if (isChinese)
			{
				state = CHINESE;
			}
			if (isblankspace)
			{
				state = BLANKSPACE;
				if (ch=='\n')
				{
					line++;
				}
			}
			if (ch==EOF)
			{
				goto skip;
			}
			break;
//_____________________________________________________________________________
		case WESTCHAR:
			letter++;
			while ((ch=getchar())==isWestchar)
			{
				letter++;
			}
			if (isblankspace)
			{
				token++;
				state = BLANKSPACE;
			}
			if (isChinese)
			{
				state = CHINESE;
			}
			break;
//__________________________________________________________________________
		case CHINESE:
			ch = getchar();
			if (isChinese)
			{
				token++;
				letter++;
			}
			state = TOBEDETER;
			break;
//_________________________________________________________________________
		case BLANKSPACE:
			if (ch=='\n')
			{
				line++;
			}
			state = TOBEDETER;
			break;
		}
	}
	skip:
	printf("有%d个字符 %d个字 %d行", token, letter, line - 1);
	system("pause");
	return 0;
}