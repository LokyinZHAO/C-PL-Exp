#include<stdio.h>	
#include<stdlib.h>
#include<assert.h>
#define DEBUG 0
#define check_malloc(x) assert(x)		//在使用malloc后检查时候分配成功
struct extra_number
{
	int num;
	struct extra_number* next;
};
typedef struct extra_number node;
node* head1 = NULL;
node* head2 = NULL;
void input(node** head);
void sum(void);


int main(void)
{
	printf("input two extra large number to sum up\n");
	input(&head1);
	input(&head2);
	sum();
	return 0;
}

//建立后进先出链表来表示长整数
void input(node** head)
{
	printf("input one of the number\n	");
	char ch=getchar();	
	node* current_node = (node*)malloc(sizeof(node));
	check_malloc(current_node);
	if (ch>='0'&&ch<='9')		//第一个链结单独创建
	{
		current_node->num = ch - '0';
		current_node->next = NULL;
		*head = current_node;
	}
	ch = getchar();
	while (ch>='0'&&ch<='9')
	{
		current_node = (node*)malloc(sizeof(node));
		check_malloc(current_node);
		current_node->num = ch - '0';		//创建一个新链结
		current_node->next = *head;
		*head = current_node;
		ch = getchar();		//读取下一个数
	}
}

void sum(void)
{
	node* current_sum = (node*)malloc(sizeof(node));
	check_malloc(current_sum);
	node* head_sum = (node*)malloc(sizeof(node));
	check_malloc(head_sum);
	int carry=0;
	node* lochead1 = head1;
	node* lochead2 = head2;
	current_sum->num = lochead1->num + lochead2->num;
	if (current_sum->num>9)
	{
		carry = 1;
		current_sum->num %= 10;
	}
	current_sum->next = NULL;
	head_sum = current_sum;
	lochead1 = lochead1->next;
	lochead2 = lochead2->next;
	while (lochead1 != NULL || lochead2 != NULL)
	{
		if (lochead1 == NULL)		//处理位数不齐的情况，用0补齐位数
		{
			lochead1 = (node*)malloc(sizeof(node));
			lochead1->num = 0;
			lochead1->next = NULL;
		}
		if (lochead2==NULL)
		{
			lochead2 = (node*)malloc(sizeof(node));
			lochead2->num = 0;
			lochead2->next = NULL;
		}
		current_sum = (node*)malloc(sizeof(node));
		check_malloc(current_sum);
		current_sum->num = lochead1->num + lochead2->num+carry;
		if (current_sum->num > 9)
		{
			carry = 1;
			current_sum->num %= 10;
		}
		else
		{
			carry = 0;
		}
		current_sum->next = head_sum;
		head_sum = current_sum;
		lochead1 = lochead1->next;
		lochead2 = lochead2->next;
	}
	if (carry==1)
	{
		current_sum = (node*)malloc(sizeof(node));
		check_malloc(current_sum);
		current_sum->num = 1;
		current_sum->next = head_sum;
		head_sum = current_sum;
	}
	printf("the sum of the two numbers is\n");
	printf("\t");
	while (current_sum)
	{
		printf("%d", current_sum->num);
		current_sum = current_sum->next;
	}
}
