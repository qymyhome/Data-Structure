//此文件用于描述所需的数据以及函数

#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

#define List_Size 20

//船的数据结构，用带头结点的单向链表表示
struct ship_data
{
	char name[10];
	char rare[5];
	float persent;
	int LuckyNum;
	float flag;
	float rate;
	struct ship_data *next;
};
typedef struct ship_data nNode_ship;

//用于存储各船的范围数字，分两个值，用带头结点的单向链表表示
struct persent_num
{
	float LuckyNum_L;
	float LuckyNum_H;
	struct persent_num *next;
};
typedef persent_num nNode_per;

//输入信息所用的函数
nNode_ship *ship_input(int ship_num)
{
	nNode_ship *nNode, *head, *p;
	printf("请输入各船的信息：\n");
	if ((head = (nNode_ship*)malloc(sizeof(nNode_ship))) == NULL)
	{

		printf("内存分配失败！");
		exit(-1);
	}
	head->next = NULL;
	p = head;
	int t, ListLen = 0;
	for (t = 0; t < ship_num + 0; t++)
	{
		if (head->next == NULL)
		{
			if ((nNode = (nNode_ship*)malloc(sizeof(nNode_ship))) == NULL)
			{
				printf("内存分配失败！");
				exit(-1);
			}
			printf("请输入船名：");
			scanf_s("%s", &nNode->name, 10);
			printf("请输入稀有度：");
			scanf_s("%s", &nNode->rare, 5);
			printf("请输入概率：");
			scanf_s("%f", &nNode->persent);
			printf("\n");
			nNode->LuckyNum = 0;
			nNode->flag = 0;
			nNode->rate = 0;
			nNode->next = NULL;
			p = nNode;
			head->next = p;
		}
		else if (head->next != NULL)
		{
			if ((nNode = (nNode_ship*)malloc(sizeof(nNode_ship))) == NULL)
				exit(-1);
			printf("请输入船名：");
			scanf_s("%s", &nNode->name, 10);
			printf("请输入稀有度：");
			scanf_s("%s", &nNode->rare, 5);
			printf("请输入概率：");
			scanf_s("%f", &nNode->persent);
			printf("\n");
			nNode->LuckyNum = 0;
			nNode->flag = 0;
			nNode->rate = 0;
			nNode->next = NULL;
			p->next = nNode;
			p = nNode;
		}
	}
	return (head);
}

//计算和记录各船概率数字的范围,输出带头结点的单链表
nNode_per *calculate_num(int ship_num, nNode_ship *L)
{
	nNode_per *head, *nNode, *p;
	if ((head = (nNode_per*)malloc(sizeof(nNode_per))) == NULL)
	{
		printf("内存分配失败！");
		exit(-1);
	}
	head->next = NULL;
	p = head;

	int t;
	float num[20] = {0};
	nNode_ship *temp = L->next;
	for (t = 0; t < ship_num + 0; t++)
	{
		num[t] = (temp->persent) * 1000;
		temp = temp->next;
	}

	int i;
	for (i = 0; i < ship_num + 0; i++)
	{
		if ((nNode = (nNode_per*)malloc(sizeof(nNode_per))) == NULL)
		{
			printf("内存分配失败！");
			exit(-1);
		}
		if (head->next == NULL)
		{
			nNode->LuckyNum_L = 0;
			nNode->LuckyNum_H = 0;
			nNode->next = NULL;
			p = nNode;
			head->next = p;
		}
		else if (head->next != NULL)
		{
			nNode->LuckyNum_L = 0;
			nNode->LuckyNum_H = 0;
			nNode->next = NULL;
			p->next = nNode;
			p = nNode;
		}
	}

	p = head->next;
	int x;
	float a = 1;
	for (x = 0; x < ship_num + 0; x++)
	{
		p->LuckyNum_L = a;
		p->LuckyNum_H = num[x] + a;
		p = p->next;
		a += num[x];
	}
	return (head);
}

//建造模拟以及统计建造模拟的结果（这函数的参数好像有点多啊）
int simulate(int ship_num, nNode_ship *ship, nNode_per *num, int times, int times_one)
{
	srand((int)time(NULL));
	nNode_ship *a;
	if ((a = (nNode_ship*)malloc(sizeof(nNode_ship))) == NULL)
	{
		printf("分配内存失败！");
		exit(-1);
	}
	nNode_per *b;
	if ((b = (nNode_per*)malloc(sizeof(nNode_per))) == NULL)
	{
		printf("分配内存失败！");
		exit(-1);
	}
	a = ship->next;
	b = num->next;
	int m, n, o;//建造的循环变量
	int x, y;//统计的循环变量
	int single = 0;
	for (m = 0; m < times; m++)
	{
		for (n = 0; n < times_one; n++)
		{
			a = ship->next;
			b = num->next;
			single = (rand() % 1000) + 1;
			for (o = 0; o < ship_num + 0; o++)
			{
				if (single >= b->LuckyNum_L&&single < b->LuckyNum_H)
					a->LuckyNum++;
				a = a->next;
				b = b->next;
				/*if (a->next == NULL && b->next == NULL)
					break;*/
			}
		}
		
		//统计单次n连的结果
		a = ship->next;
		b = num->next;
		for (x = 0; x < ship_num + 0; x++)
		{
			if (a->LuckyNum != 0)
				a->flag++;
			a->LuckyNum = 0;
			a = a->next;
		}
		single = 0;
	}
	a = ship->next;
	//统计m次n连的结果
	for (y = 0; y < ship_num + 0; y++)
	{
		a->rate = ((a->flag) / times) * 100;
		a->LuckyNum = 0;
		a = a->next;
	}
	return 0;
}
