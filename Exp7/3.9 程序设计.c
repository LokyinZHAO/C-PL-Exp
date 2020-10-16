#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define check_malloc(x)  assert(x)

struct rePolandNota		//op表示预算符,data表示数字
{
	char flag;		//标识这个链结是运算符还是数字，0表示数字，1表示运算符,-1表示处理过的无效值
	char op;
	float data;
	struct rePolandNota* next;
};
typedef struct rePolandNota node;

node* current_node;
node* head;
char notation[100];		//存放键盘读入的表达式

void converse(void);
void calcu(void);
node* search_op(void);
void sum(node*);
void mun(node*);
void mul(node*);
void divi(node*);

int main(void)
{
	printf("input a reverse Polish notation(each part is spaced off)\n");
	current_node = (node*)malloc(sizeof(node));		//初始化
	current_node->next = NULL;
	gets_s(notation, 99);
	converse();		//将表达式由字符串转化为后进先出链表形式
	calcu();			//进行计算
	system("pause");
	return 0;
}

void converse(void)
{
	int i = 0;
	char temp[10] = { 0 };		//用于临时存一个数字
	int t = 0;		//temp中计数
	while (notation[i])
	{
		if ((notation[i] >= '0' && notation[i] <= '9') || notation[i] == '.')		//数字录入
		{
			t = 0;
			for (int i = 0; i < 10; i++)		//temp重置清零
			{
				temp[i] = '\0';
			}
			while ((notation[i] >= '0' && notation[i] <= '9') || notation[i] == '.')
			{
				temp[t++] = notation[i];
				i++;
			}
			temp[t] = '\0	';
			current_node->flag = 0;
			current_node->data = atof(temp);		//将串形式转化为float形式
		}
		if (notation[i] == '+')
		{
			current_node->flag = 1;
			current_node->op = '+';
			i++;
		}
		if (notation[i] == '-')
		{
			current_node->flag = 1;
			current_node->op = '-';
			i++;
		}
		if (notation[i] == '*')
		{
			current_node->flag = 1;
			current_node->op = '*';
			i++;
		}
		if (notation[i] == '/')
		{
			current_node->flag = 1;
			current_node->op = '/';
			i++;
		}
		if (notation[i] == ' ')
		{
			i++;
		}
		current_node->next = head;		//创建新链结
		head = current_node;
		current_node = (node*)malloc(sizeof(node));
		check_malloc(current_node);
	}
	free(current_node);	//释放最后一次多余创建的malloc
	return;
}

//计算方法：逆波兰表达式从右往左读，最左边的一个运算符其左侧一定是两个数字，由此以此计算
//计算后把计算的结果置于其中一个链结中，其他两个链结的flag标为-1
//直至计算到没有运算符为止，此时最左边的一个数字为最终结果
void calcu(void)
{
	node* search;
	search=search_op();		//从右往左，找到最左边的一个运算符
	while (search)
	{
		switch (search->op)
		{
		case '+': sum(search);	break;
		case '-': mun(search);	break;
		case '*': mul(search);		break;
		case '/': divi(search);		break;
		}
		search = search_op();
	}
	node* current_node = head;			//找到最左边一个flag为0的链结，其data即为最终结果
	node* result = head;
	while (current_node)
	{
		if (current_node->flag==0)
		{
			result = current_node;
		}
		current_node = current_node->next;
	}
	printf("%.2f\n", result->data);
}

//从右往左，找出最左边的一个运算符
//若遍历之后未找到，说明计算完成，返回NULL
node* search_op(void)
{
	node* current_node = head;
	node* search=NULL;
	while (current_node)
	{
		if (current_node->flag==1)
		{
			search = current_node;
		}
		current_node = current_node->next;
	}
	return  search;
}

//进行相应的四则运算
void sum(node* op)
{
	node* current_node = op;
	node* num1;
	node* num2;
	while (current_node->flag!=0)
	{
		current_node = current_node->next;
	}
	num1 = current_node;
	current_node = current_node->next;
	while (current_node->flag!=0)
	{
		current_node = current_node->next;
	}
	num2 = current_node;
	//以上的操作为了找的这个运算符左边最相邻的两个数
	op->flag = -1;
	num2->data = num1->data + num2->data;
	num1->flag = -1;
}

void mun(node* op)
{
	node* current_node = op;
	node* num1;
	node* num2;
	while (current_node->flag != 0)
	{
		current_node = current_node->next;
	}
	num1 = current_node;
	current_node = current_node->next;
	while (current_node->flag != 0)
	{
		current_node = current_node->next;
	}
	num2 = current_node;
	op->flag = -1;
	num2->data = num2->data - num1->data;
	num1->flag = -1;
}

void mul(node* op)
{
	node* current_node = op;
	node* num1;
	node* num2;
	while (current_node->flag != 0)
	{
		current_node = current_node->next;
	}
	num1 = current_node;
	current_node = current_node->next;
	while (current_node->flag != 0)
	{
		current_node = current_node->next;
	}
	num2 = current_node;
	op->flag = -1;
	num2->data = num1->data * num2->data;
	num1->flag = -1;
}

void divi(node* op)
{
	node* current_node = op;
	node* num1;
	node* num2;
	while (current_node->flag != 0)
	{
		current_node = current_node->next;
	}
	num1 = current_node;
	current_node = current_node->next;
	while (current_node->flag != 0)
	{
		current_node = current_node->next;
	}
	num2 = current_node;
	op->flag = -1;
	assert(num1->data);
	num2->data = num2->data / num1->data;
	num1->flag = -1;
}