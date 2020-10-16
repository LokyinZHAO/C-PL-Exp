#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define English score[0]
#define Math score[1]
#define Physics score[2]
#define CPL score[3]
#define	 check_malloc(x) assert(x!=0);		//���malloc�Ƿ����ɹ�
#define sum_score(current_node) (current_node->data->score[0] + current_node->data->score[1] + current_node->data->score[2] + current_node->data->score[3])
typedef struct student_info sheet;
typedef struct student_data info;
void input(void);
void output(void);
void change_info(void);
void calcu_average(void);
void appro_output(void);
void ascending_sort(void);
void node_switch(sheet**prior1,sheet**p1,sheet**p2);
void (*func[])() = { input,output,change_info,calcu_average,appro_output,ascending_sort };
struct student_info
{
	info* data;
	sheet* next;
};
struct student_data
{
	int number;
	char* name;
	int score[4];
};
int n;		//ѧ������
sheet* head = NULL;		//��ͷָ��

/*********************************************************

*********************************************************/
int main(void)
{
	printf("����˵����룬ִ�в�ͬ����:\n");
	printf("\t1 ����ÿ��ѧ���ĸ�����Ϣ\n");
	printf("\t2 ���ÿ��ѧ���ĸ�����Ϣ\n");
	printf("\t3 �޸�ָ����ѧ�����ƶ������������\n");
	printf("\t4 ͳ��ÿ��ѧ����ƽ���ɼ�\n");
	printf("\t5 �����λѧ����ѧ�š����������ſγ̵��ܳɼ���ƽ���ɼ�\n");
	printf("\t6 ��ƽ���ɼ���������\n");
	printf("\t0 �˳�����\n");
	int choice;
	scanf_s("%d", &choice);
	while (choice > 0 && choice < 7)
	{
		printf("========ִ�в˵�%d========\n", choice);
		func[choice - 1]();
		printf("======�˵�%dִ�����======\n", choice);
		printf("�����ѡ��˵����˳�\n");
		scanf_s("%d", &choice);
	}
	system("pause");
	return 0;
}
/*********************************************************

*********************************************************/
void input(void)
{
	printf("����ѧ��������");
	scanf_s("%d", &n);
	sheet* current_node = NULL;		//����һ��ָ��ǰ����Ľṹָ��
	current_node = (sheet*)malloc(sizeof(sheet));
	check_malloc(current_node);
	current_node->data = (info*)malloc(sizeof(info));
	check_malloc(current_node->data);
	printf("��������%d��ѧ������Ϣ\nѧ��\t����\tӢ��\t����\t����\tC����\n", n);
	char name[50];		//��һ�������豻headָ�򣬹ʵ�������
	scanf_s("%d", &(current_node->data->number));
	scanf_s("%*c %s", &name[0], 49);		//error note��scanf_s�����ַ���ʱ�����������볤��
	int len = strlen(name);
	(*current_node).data->name = (char*)malloc(sizeof(char) * len);
	check_malloc((*current_node).data->name);
	strcpy_s((*current_node).data->name, len + 1, name);		//error note��strlen����'\n'����+1���ܰ�ȫ����
	scanf_s("%d %d %d %d", &(current_node->data->score[0]), &(current_node->data->score[1]), &(current_node->data->score[2]), &(current_node->data->score[3]));
	head = current_node;
	for (int i = 1; i < n; i++)		//�������µ�ָ��
	{
		current_node->next = (sheet*)malloc(sizeof(sheet));
		check_malloc(current_node->next);
		current_node = current_node->next;
		current_node->data = (info*)malloc(sizeof(info));
		scanf_s("%d", &(current_node->data->number));
		scanf_s("%*c %s", name, 49);
		len = strlen(name);
		current_node->data->name = (char*)malloc(sizeof(char) * len);
		check_malloc(current_node->data->name);
		strcpy_s(current_node->data->name, len + 1, name);
		scanf_s("%d %d %d %d", &(current_node->data->score[0]), &(current_node->data->score[1]), &(current_node->data->score[2]), &(current_node->data->score[3]));
	}
	current_node->next = NULL;		//���������ָ����Ϊ��
}
/*********************************************************

*********************************************************/
void output(void)
{
	printf("ѧ��\t����\tӢ��\t����\t����\tC����\n");
	sheet* current_node = head;		//����һ��ָ��ǰ�����ָ�룬��ʼ��Ϊhead
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\n", current_node->data->number, current_node->data->name, current_node->data->score[0], current_node->data->score[1], current_node->data->score[2], current_node->data->score[3]);
		current_node = current_node->next;
	}
}
/*********************************************************

*********************************************************/
void change_info(void)
{
	printf("��������Ҫ������Ϣ��ѧ��������");
	char name_to_change[50];
	getchar();
	gets_s(name_to_change, 49);
	sheet* current_node = head;
	while (current_node != NULL && strcmp(current_node->data->name, name_to_change) != 0)
		//error note��&&���жϵ�һ������٣�����һ��Ϊ�������жϣ�������ȷ��current_nodeΪNULLʱ�������name��Ա��������
	{
		current_node = current_node->next;
	}
	if (current_node == NULL)
	{
		printf("δ�ҵ�%s\n", name_to_change);
		return;
	}
	printf("����������ĵ���Ŀ����ţ�\n");
	printf("1 ѧ��\n2 ����\n3 Ӣ��ɼ�\n4 �����ɼ�\n5 ����ɼ�\n6 C���Գɼ�\n");
	int prog;
	scanf_s("%d", &prog);
	switch (prog)
	{
	case 1:
		printf("%s�ľ�ѧ��Ϊ%d����������ѧ�ţ�\t", current_node->data->name, current_node->data->number);
		scanf_s("%d", &(current_node->data->number));
		break;
	case 2:
		printf("������%s����������\t", current_node->data->name);
		scanf_s("%s", current_node->data->name, 49);
		break;
	case 3:
		printf("%s��ԭӢ��ɼ�Ϊ%d���������³ɼ���\t", current_node->data->name, current_node->data->score[0]);
		scanf_s("%d", &current_node->data->score[0]);
		break;
	case 4:
		printf("%s��ԭ�����ɼ�Ϊ%d���������³ɼ���\t", current_node->data->name, current_node->data->score[1]);
		scanf_s("%d", &current_node->data->score[1]);
		break;
	case 5:
		printf("%s��ԭ����ɼ�Ϊ%d���������³ɼ���\t", current_node->data->name, current_node->data->score[2]);
		scanf_s("%d", &current_node->data->score[2]);
		break;
	case 6:
		printf("%s��ԭC���Գɼ�Ϊ%d���������³ɼ���\t", current_node->data->name, current_node->data->score[3]);
		scanf_s("%d", &current_node->data->score[3]);
		break;
	}
	printf("�޸ĺ�����\n");
	printf("ѧ��\t����\tӢ��\t����\t����\tC����\n");
	printf("%d\t%s\t%d\t%d\t%d\t%d\n", current_node->data->number, current_node->data->name, current_node->data->score[0], current_node->data->score[1], current_node->data->score[2], current_node->data->score[3]);
}
/*********************************************************

*********************************************************/
void calcu_average(void)
{
	printf("��λѧ����ƽ���ɼ����£�\n");
	printf("ѧ��\t����\tƽ���ɼ�\n");
	sheet* current_node = head;
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", current_node->data->number);
		printf("%s\t", current_node->data->name);
		printf("%.2f\n", (current_node->data->score[0] + current_node->data->score[1] + current_node->data->score[2] + current_node->data->score[3]) / 4.0);
		current_node = current_node->next;
	}
}
/*********************************************************

*********************************************************/
void appro_output(void)
{
	printf("��λѧ���ĳɼ����£�\n");
	printf("ѧ��\t����\t�ܳɼ�\tƽ���ɼ�\n");
	sheet* current_node = head;
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", current_node->data->number);
		printf("%s\t", current_node->data->name);
		printf("%d\t", current_node->data->score[0] + current_node->data->score[1] + current_node->data->score[2] + current_node->data->score[3]);
		printf("%.2f\n", (current_node->data->score[0] + current_node->data->score[1] + current_node->data->score[2] + current_node->data->score[3]) / 4.0);
		current_node = current_node->next;
	}
}
/*********************************************************

*********************************************************/
void ascending_sort(void)
{
	if (n < 2) return;
	sheet* pre_head = (sheet*)malloc(sizeof(sheet));
	check_malloc(pre_head);
	pre_head->next = head;
	sheet* prior = pre_head;
	sheet* p1 = head;
	sheet* p2 = head->next;
	sheet* bubble_place = p1;
	sheet* pre_bubble_place = pre_head;
	for (int i = 1; i < n; i++)
	{
		prior = pre_bubble_place;
		p1 = bubble_place;
		p2 = bubble_place->next;
		if (!p2)
		{
			break;
		}
		for (int j = 0; j < n-i&&p2!=NULL; j++)
		{
			if (sum_score(p1) > sum_score(p2))
			{
				p1->next = p2->next;
				prior->next = p2;
				p2->next = p1;
			}
			sheet* exchange = p1;
			p1 = p2;
			p2 = exchange;
			prior = prior->next;
			p1 = p1->next;
			p2 = p2->next;
		}

		pre_bubble_place = pre_bubble_place->next;
		bubble_place = bubble_place->next;
	}

}
//����������������
void node_switch(sheet** prior1, sheet** p1, sheet** p2)
{
	(*p1)->next = (*p2)->next;
	(*prior1)->next = (*p2);
	(*p2)->next = (*p1);
}
