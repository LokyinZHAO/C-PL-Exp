#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define check_malloc(x)  assert(x)

struct rePolandNota		//op��ʾԤ���,data��ʾ����
{
	char flag;		//��ʶ���������������������֣�0��ʾ���֣�1��ʾ�����,-1��ʾ���������Чֵ
	char op;
	float data;
	struct rePolandNota* next;
};
typedef struct rePolandNota node;

node* current_node;
node* head;
char notation[100];		//��ż��̶���ı��ʽ

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
	current_node = (node*)malloc(sizeof(node));		//��ʼ��
	current_node->next = NULL;
	gets_s(notation, 99);
	converse();		//�����ʽ���ַ���ת��Ϊ����ȳ�������ʽ
	calcu();			//���м���
	system("pause");
	return 0;
}

void converse(void)
{
	int i = 0;
	char temp[10] = { 0 };		//������ʱ��һ������
	int t = 0;		//temp�м���
	while (notation[i])
	{
		if ((notation[i] >= '0' && notation[i] <= '9') || notation[i] == '.')		//����¼��
		{
			t = 0;
			for (int i = 0; i < 10; i++)		//temp��������
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
			current_node->data = atof(temp);		//������ʽת��Ϊfloat��ʽ
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
		current_node->next = head;		//����������
		head = current_node;
		current_node = (node*)malloc(sizeof(node));
		check_malloc(current_node);
	}
	free(current_node);	//�ͷ����һ�ζ��ഴ����malloc
	return;
}

//���㷽�����沨�����ʽ���������������ߵ�һ������������һ�����������֣��ɴ��Դ˼���
//�����Ѽ���Ľ����������һ�������У��������������flag��Ϊ-1
//ֱ�����㵽û�������Ϊֹ����ʱ����ߵ�һ������Ϊ���ս��
void calcu(void)
{
	node* search;
	search=search_op();		//���������ҵ�����ߵ�һ�������
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
	node* current_node = head;			//�ҵ������һ��flagΪ0�����ᣬ��data��Ϊ���ս��
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

//���������ҳ�����ߵ�һ�������
//������֮��δ�ҵ���˵��������ɣ�����NULL
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

//������Ӧ����������
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
	//���ϵĲ���Ϊ���ҵ�����������������ڵ�������
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