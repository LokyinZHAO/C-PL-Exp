#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define creat_node(x) x=(node*)malloc(sizeof(node))
#define creat_data(x) x=(struct info*)malloc(sizeof(struct info))
#define check_malloc(x) assert(x)
void file_save(void);
void file_open(void);
struct info
{
	char name[10];
	int score;
};
struct student_info	//建立学生信息链表
{
	struct info* data;
	struct student_info* next;
}*save_head,*open_head;
typedef struct student_info node;

int main(void)
{
	printf("1. 将链表节点中学生各项信息保存到二进制文件中\n");
	printf("2. 从文件中读取数据到链表中\n");
	printf("请输入菜单选项:\n");
	int choice;
	scanf("%d", &choice);
	while (choice==1||choice==2)
	{
		switch (choice)
		{
		case 1:file_save(); break;
		case 2:file_open(); break;
		}
		printf("菜单%d执行完毕，请重新选择菜单或退出（0）\n",choice);
		scanf("%d", &choice);
	}
	system("pause");
	return 0;
}

void file_save(void)
{
	creat_node(save_head);
	check_malloc(save_head);
	creat_data(save_head->data);
	check_malloc(save_head->data);
	////////////////先输入数据存到链表中/////////////////////
	printf("请输入学生个数\n");
	int num;
	scanf("%d", &num);
	printf("请输入学生信息\n");
	printf("姓名\t成绩\n");
	int score;
	char name[20];
	scanf("%s", name);
	scanf("%d", &score);
	save_head->data->score = score;
	strcpy(save_head->data->name, name);
	node* current_node;
	creat_node(current_node);
	check_malloc(current_node);
	save_head->next = current_node;
	for (int i = 1; i < num; i++)
	{
		creat_data(current_node->data);
		check_malloc(current_node->data);
		scanf("%s", name);
		scanf("%d", &score);
		current_node->data->score = score;
		strcpy(current_node->data->name, name);
		creat_node(current_node->next);
		check_malloc(current_node->next);
		current_node = current_node->next;
	}
	free(current_node);	//释放最后一次多余创建的node
	///////////////////将链表中的内容存到文件中////////////////////
	FILE* fp;
	char  filename[] = "d://stu.dat";
	if ((fp=fopen(filename,"wb"))==NULL)
	{
		printf("无法找到文件%s\n", filename);
		return;
	}
	fwrite(&num, sizeof(int), 1, fp);	//在文件开头输入学生数
	current_node = save_head;
	for (int i = 0; i < num; i++)		//将链表中的信息存入
	{
		fwrite(current_node->data->name, sizeof(char),10, fp);
		fwrite(&current_node->data->score, sizeof(int), 1, fp);
		current_node = current_node->next;
	}
	printf("文件已成功存储到%s中\n", filename);
	fclose(fp);
	return;
}

void file_open(void)
{
	creat_node(open_head);
	check_malloc(open_head);
	creat_data(open_head->data);
	check_malloc(open_head->data);
	int num;
	FILE* fp;
	char  filename[] = "d://stu.dat";
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("无法找到文件%s\n", filename);
		return;
	}
	fread(&num, sizeof(int), 1, fp);
	fread(open_head->data->name, sizeof(char), 10, fp);
	fread(&open_head->data->score, sizeof(int), 1, fp);
	creat_node(open_head->next);
	check_malloc(open_head->next);
	node* current_node = open_head->next;
	for (int i = 1; i < num; i++)
	{
		creat_data(current_node->data);
		fread(current_node->data->name, sizeof(char), 10, fp);
		fread(&current_node->data->score, sizeof(int), 1, fp);
		creat_node(current_node->next);
		check_malloc(current_node->next);
		current_node = current_node->next;
	}
	free(current_node);
	printf("从文件中读入的信息如下\n");
	printf("姓名\t成绩\n");
	current_node = open_head;
	for (int i = 0; i < num; i++)
	{
		printf("%s\t", current_node->data->name);
		printf("%d\n", current_node->data->score);
		current_node = current_node->next;
	}
	fclose(fp);
}
