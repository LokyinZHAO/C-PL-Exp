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
struct student_info	//����ѧ����Ϣ����
{
	struct info* data;
	struct student_info* next;
}*save_head,*open_head;
typedef struct student_info node;

int main(void)
{
	printf("1. ������ڵ���ѧ��������Ϣ���浽�������ļ���\n");
	printf("2. ���ļ��ж�ȡ���ݵ�������\n");
	printf("������˵�ѡ��:\n");
	int choice;
	scanf("%d", &choice);
	while (choice==1||choice==2)
	{
		switch (choice)
		{
		case 1:file_save(); break;
		case 2:file_open(); break;
		}
		printf("�˵�%dִ����ϣ�������ѡ��˵����˳���0��\n",choice);
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
	////////////////���������ݴ浽������/////////////////////
	printf("������ѧ������\n");
	int num;
	scanf("%d", &num);
	printf("������ѧ����Ϣ\n");
	printf("����\t�ɼ�\n");
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
	free(current_node);	//�ͷ����һ�ζ��ഴ����node
	///////////////////�������е����ݴ浽�ļ���////////////////////
	FILE* fp;
	char  filename[] = "d://stu.dat";
	if ((fp=fopen(filename,"wb"))==NULL)
	{
		printf("�޷��ҵ��ļ�%s\n", filename);
		return;
	}
	fwrite(&num, sizeof(int), 1, fp);	//���ļ���ͷ����ѧ����
	current_node = save_head;
	for (int i = 0; i < num; i++)		//�������е���Ϣ����
	{
		fwrite(current_node->data->name, sizeof(char),10, fp);
		fwrite(&current_node->data->score, sizeof(int), 1, fp);
		current_node = current_node->next;
	}
	printf("�ļ��ѳɹ��洢��%s��\n", filename);
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
		printf("�޷��ҵ��ļ�%s\n", filename);
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
	printf("���ļ��ж������Ϣ����\n");
	printf("����\t�ɼ�\n");
	current_node = open_head;
	for (int i = 0; i < num; i++)
	{
		printf("%s\t", current_node->data->name);
		printf("%d\n", current_node->data->score);
		current_node = current_node->next;
	}
	fclose(fp);
}
