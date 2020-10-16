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
	create_list(&head, s);
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
	if (!p[0]);
	else
	{
		loc_head = (struct s_list*)malloc(sizeof(struct s_list));		//第一个链结的指针域为NULL，特殊情况单独创建
		loc_head->data = p[0];
		loc_head->next = NULL;
		*headp = loc_head;		//headp始终指向当前的创建的链结
		while (*(++p))
		{
			loc_head = (struct s_list*)malloc(sizeof(struct s_list));
			loc_head->data = *p;
			loc_head->next = *headp;		//新链结的指针域指向之前的headp
			*headp = loc_head;
		}
	}

}