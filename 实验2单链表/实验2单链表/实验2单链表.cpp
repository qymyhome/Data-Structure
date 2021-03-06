// 实验2单链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

#define MAXSIZE 20

struct sqlist
{
	int data;
	struct sqlist *next;
};

typedef struct sqlist nNode;

int printToScreen(nNode *ptr);
int search(int pos, nNode *ptr);
int insert(int pos, nNode *ptr, int num);
int deleteNum(int pos, nNode *ptr);



int main(int argc[], char *argv[])
{
	//输入元素，创建链表
	printf("输入元素个数：");
	int elem_num = 0;
	scanf_s("%d", &elem_num);
	if (elem_num > MAXSIZE)
		printf("元素个数超过链表长度！");
	printf("输入元素：");
	nNode *head, *node, *p;
	if ((head = (nNode*)malloc(sizeof(nNode))) == NULL)
	{
		printf("内存分配失败！");
		exit(0);
	}
	head->next = NULL;
	head->data = 0;
	p = head;
	int turn_2;
	for (turn_2 = 0; turn_2 < elem_num; turn_2++)
	{
		if (head->next == NULL)
		{
			if ((node = (nNode*)malloc(sizeof(nNode))) == NULL)
				exit(0);
			scanf_s("%d", &node->data);
			node->next = NULL;
			p = node;
			head->next = p;
			head->data++;
		}
		else if (head->next != NULL)
		{
			if ((node = (nNode*)malloc(sizeof(nNode))) == NULL)
				exit(0);
			scanf_s("%d", &node->data);
			node->next = NULL;
			p->next = node;
			p = node;
			head->data++;
		}
	}
	printToScreen(head);

	//查找操作
	printf("请输入要查找的元素的位置：");
	int num_pos = 0;
	scanf_s("%d", &num_pos);
	search(num_pos, head);

	//插入操作
	printf("请输入元素要插入的位置：");
	int pos_new = 0;
	scanf_s("%d", &pos_new);
	printf("请输入要插入的元素：");
	int num_new = 0;
	scanf_s("%d", &num_new);
	insert(pos_new, head, num_new);
	printToScreen(head);

	//删除操作
	printf("请输入要删除的数据的位置：");
	int pos_del = 0;
	scanf_s("%d", &pos_del);
	deleteNum(pos_del, head);
	printToScreen(head);

	return 0;
}

//输出链表中的元素到屏幕
int printToScreen(nNode *ptr)
{
	if (ptr == NULL)
	{
		printf("链表中元素为空！");
		return NULL;
	}
	nNode *p = ptr->next;
	int turn_1;
	for (turn_1 = 0; turn_1 < ptr->data; turn_1++)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	if (turn_1 == ptr->data)
		printf("\n");
	return 0;
}

//给定位置查找元素并输出
int search(int pos, nNode *ptr)
{
	if (pos > ptr->data)
	{
		printf("超出链表范围！");
		return NULL;
	}
	nNode *p = ptr->next;
	int turn_3;
	for (turn_3 = 1; turn_3 != pos; turn_3++)
	{
		p = p->next;
	}
	printf("%d\n", p->data);
	return 1;
}

//给定位置插入元素
int insert(int pos, nNode *ptr, int num)
{
	if (pos > ptr->data)
		return 0;
	nNode *node= NULL;
	nNode *p = ptr->next;
	int turn_4;
	if (pos == 1)
	{
		node = (nNode*)malloc(sizeof(nNode));
		node->data = num;
		node->next = ptr->next;
		ptr->next = node;
		ptr->data++;
	}
	else if (pos != 1)
	{
		node = (nNode*)malloc(sizeof(nNode));
		node->data = num;
		for (turn_4 = 1; turn_4 != pos - 1; turn_4++)
			p = p->next;
		node->next = p->next;
		p->next = node;
		ptr->data++;
	}
	return 1;
}

//给定位置删除元素
int deleteNum(int pos, nNode *ptr)
{
	if (pos > ptr->data)
		return 0;
	nNode *p = ptr->next;
	int turn_5;
	if (pos == 1)
	{
		ptr->next = ptr->next->next;
		ptr->data--;
	}
	else if (pos != 1)
	{
		for (turn_5 = 1; turn_5 != pos - 1; turn_5++)
			p = p->next;
		p->next = p->next->next;
		ptr->data--;
	}
	return 1;
}