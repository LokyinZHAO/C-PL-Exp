#include<stdio.h>
#include<stdlib.h>
struct s_list
{
	int data;
	struct s_list* next;
};
void create_list(struct s_list** headp, int* p);

int main(void)
{
	struct s_list* head = NULL, * p;
	int s[] = { 1,2,3,4,5,6,7,8,0 };
	create_list(&head, s);		//指针作为形参应该传入指针的地址，相应的函数原型用二级指针
	p = head;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	system("pause");
	return 0;
}

void create_list(struct s_list** headp, int* p)
{
	struct s_list* loc_head = NULL, * tail;
	if (p[0] == 0);
	else 
	{
		loc_head = (struct s_list*)malloc(sizeof(struct s_list));
		loc_head->data = *p++;
		tail = loc_head;
		while (*p)
		{
			tail->next = (struct s_list*)malloc(sizeof(struct s_list));
			tail = tail->next;
			tail->data = *p++;
		}
		tail->next = NULL;
	}
	*headp = loc_head;		//相应此处应该给指针指向的结构赋值
}
