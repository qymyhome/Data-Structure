//���ļ�������������������Լ�����

#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

#define List_Size 20

//�������ݽṹ���ô�ͷ���ĵ��������ʾ
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

//���ڴ洢�����ķ�Χ���֣�������ֵ���ô�ͷ���ĵ��������ʾ
struct persent_num
{
	float LuckyNum_L;
	float LuckyNum_H;
	struct persent_num *next;
};
typedef persent_num nNode_per;

//������Ϣ���õĺ���
nNode_ship *ship_input(int ship_num)
{
	nNode_ship *nNode, *head, *p;
	printf("�������������Ϣ��\n");
	if ((head = (nNode_ship*)malloc(sizeof(nNode_ship))) == NULL)
	{

		printf("�ڴ����ʧ�ܣ�");
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
				printf("�ڴ����ʧ�ܣ�");
				exit(-1);
			}
			printf("�����봬����");
			scanf_s("%s", &nNode->name, 10);
			printf("������ϡ�жȣ�");
			scanf_s("%s", &nNode->rare, 5);
			printf("��������ʣ�");
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
			printf("�����봬����");
			scanf_s("%s", &nNode->name, 10);
			printf("������ϡ�жȣ�");
			scanf_s("%s", &nNode->rare, 5);
			printf("��������ʣ�");
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

//����ͼ�¼�����������ֵķ�Χ,�����ͷ���ĵ�����
nNode_per *calculate_num(int ship_num, nNode_ship *L)
{
	nNode_per *head, *nNode, *p;
	if ((head = (nNode_per*)malloc(sizeof(nNode_per))) == NULL)
	{
		printf("�ڴ����ʧ�ܣ�");
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
			printf("�ڴ����ʧ�ܣ�");
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

//����ģ���Լ�ͳ�ƽ���ģ��Ľ�����⺯���Ĳ��������е�డ��
int simulate(int ship_num, nNode_ship *ship, nNode_per *num, int times, int times_one)
{
	srand((int)time(NULL));
	nNode_ship *a;
	if ((a = (nNode_ship*)malloc(sizeof(nNode_ship))) == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	nNode_per *b;
	if ((b = (nNode_per*)malloc(sizeof(nNode_per))) == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	a = ship->next;
	b = num->next;
	int m, n, o;//�����ѭ������
	int x, y;//ͳ�Ƶ�ѭ������
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
		
		//ͳ�Ƶ���n���Ľ��
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
	//ͳ��m��n���Ľ��
	for (y = 0; y < ship_num + 0; y++)
	{
		a->rate = ((a->flag) / times) * 100;
		a->LuckyNum = 0;
		a = a->next;
	}
	return 0;
}
