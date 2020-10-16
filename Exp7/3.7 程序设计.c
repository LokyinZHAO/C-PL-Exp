#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define English score[0]
#define Math score[1]
#define Physics score[2]
#define CPL score[3]
#define	 check_malloc(x) assert(x!=0);		//检查malloc是否分配成功
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
int n;		//学生个数
sheet* head = NULL;		//链头指针

/*********************************************************

*********************************************************/
int main(void)
{
	printf("输入菜单编码，执行不同功能:\n");
	printf("\t1 输入每个学生的各项信息\n");
	printf("\t2 输出每个学生的各项信息\n");
	printf("\t3 修改指定的学生的制定数据项的内容\n");
	printf("\t4 统计每个学生的平均成绩\n");
	printf("\t5 输出各位学生的学号、姓名、四门课程的总成绩和平均成绩\n");
	printf("\t6 按平均成绩升序排序\n");
	printf("\t0 退出程序\n");
	int choice;
	scanf_s("%d", &choice);
	while (choice > 0 && choice < 7)
	{
		printf("========执行菜单%d========\n", choice);
		func[choice - 1]();
		printf("======菜单%d执行完毕======\n", choice);
		printf("请继续选择菜单或退出\n");
		scanf_s("%d", &choice);
	}
	system("pause");
	return 0;
}
/*********************************************************

*********************************************************/
void input(void)
{
	printf("输入学生个数：");
	scanf_s("%d", &n);
	sheet* current_node = NULL;		//创建一个指向当前链结的结构指针
	current_node = (sheet*)malloc(sizeof(sheet));
	check_malloc(current_node);
	current_node->data = (info*)malloc(sizeof(info));
	check_malloc(current_node->data);
	printf("依次输入%d个学生的信息\n学号\t姓名\t英语\t高数\t物理\tC语言\n", n);
	char name[50];		//第一个链结需被head指向，故单独创建
	scanf_s("%d", &(current_node->data->number));
	scanf_s("%*c %s", &name[0], 49);		//error note：scanf_s读入字符串时需输入最大读入长度
	int len = strlen(name);
	(*current_node).data->name = (char*)malloc(sizeof(char) * len);
	check_malloc((*current_node).data->name);
	strcpy_s((*current_node).data->name, len + 1, name);		//error note：strlen不计'\n'，需+1才能安全传递
	scanf_s("%d %d %d %d", &(current_node->data->score[0]), &(current_node->data->score[1]), &(current_node->data->score[2]), &(current_node->data->score[3]));
	head = current_node;
	for (int i = 1; i < n; i++)		//创建余下的指针
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
	current_node->next = NULL;		//最后的链结的指针域为空
}
/*********************************************************

*********************************************************/
void output(void)
{
	printf("学号\t姓名\t英语\t高数\t物理\tC语言\n");
	sheet* current_node = head;		//创建一个指向当前链结的指针，初始化为head
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
	printf("请输入需要更改信息的学生姓名：");
	char name_to_change[50];
	getchar();
	gets_s(name_to_change, 49);
	sheet* current_node = head;
	while (current_node != NULL && strcmp(current_node->data->name, name_to_change) != 0)
		//error note：&&先判断第一个的真假，若第一个为假则不再判断，故这样确保current_node为NULL时不会访问name成员引起问题
	{
		current_node = current_node->next;
	}
	if (current_node == NULL)
	{
		printf("未找到%s\n", name_to_change);
		return;
	}
	printf("请输入需更改的项目的序号：\n");
	printf("1 学号\n2 姓名\n3 英语成绩\n4 高数成绩\n5 物理成绩\n6 C语言成绩\n");
	int prog;
	scanf_s("%d", &prog);
	switch (prog)
	{
	case 1:
		printf("%s的旧学号为%d，请输入新学号：\t", current_node->data->name, current_node->data->number);
		scanf_s("%d", &(current_node->data->number));
		break;
	case 2:
		printf("请输入%s的新姓名：\t", current_node->data->name);
		scanf_s("%s", current_node->data->name, 49);
		break;
	case 3:
		printf("%s的原英语成绩为%d，请输入新成绩：\t", current_node->data->name, current_node->data->score[0]);
		scanf_s("%d", &current_node->data->score[0]);
		break;
	case 4:
		printf("%s的原高数成绩为%d，请输入新成绩：\t", current_node->data->name, current_node->data->score[1]);
		scanf_s("%d", &current_node->data->score[1]);
		break;
	case 5:
		printf("%s的原物理成绩为%d，请输入新成绩：\t", current_node->data->name, current_node->data->score[2]);
		scanf_s("%d", &current_node->data->score[2]);
		break;
	case 6:
		printf("%s的原C语言成绩为%d，请输入新成绩：\t", current_node->data->name, current_node->data->score[3]);
		scanf_s("%d", &current_node->data->score[3]);
		break;
	}
	printf("修改后结果：\n");
	printf("学号\t姓名\t英语\t高数\t物理\tC语言\n");
	printf("%d\t%s\t%d\t%d\t%d\t%d\n", current_node->data->number, current_node->data->name, current_node->data->score[0], current_node->data->score[1], current_node->data->score[2], current_node->data->score[3]);
}
/*********************************************************

*********************************************************/
void calcu_average(void)
{
	printf("各位学生的平均成绩如下：\n");
	printf("学号\t姓名\t平均成绩\n");
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
	printf("各位学生的成绩如下：\n");
	printf("学号\t姓名\t总成绩\t平均成绩\n");
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
//交换两个相邻链结
void node_switch(sheet** prior1, sheet** p1, sheet** p2)
{
	(*p1)->next = (*p2)->next;
	(*prior1)->next = (*p2);
	(*p2)->next = (*p1);
}
