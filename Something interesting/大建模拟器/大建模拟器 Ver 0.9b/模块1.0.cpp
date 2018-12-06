//���ļ�������������������Լ�����


#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

#define YES
#ifdef YES

#define List_Size 20

//�������ݽṹ���ô�ͷ���ĵ��������ʾ
/*ֻͳ��ȫ����ҵ�������������ͳ�ƹ��ܴ�����*/
struct ship_data
{
	char name[10];
	char rare[5];
	double persent;
	int LuckyNum;	//�����ж�
	struct ship_data *next;
};
typedef struct ship_data nNode_ship;

//���ڴ洢�����ķ�Χ���֣�������ֵ���ô�ͷ���ĵ��������ʾ
struct persent_num
{
	double LuckyNum_L;
	double LuckyNum_H;
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
			scanf_s("%lf", &nNode->persent);
			printf("\n");
			nNode->LuckyNum = 0;
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
			scanf_s("%lf", &nNode->persent);
			printf("\n");
			nNode->LuckyNum = 0;
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
	double num[20] = { 0 };
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
	double a = 1;
	for (x = 0; x < ship_num + 0; x++)
	{
		p->LuckyNum_L = a;
		p->LuckyNum_H = num[x] + a;
		p = p->next;
		a += num[x];
	}
	return (head);
}

/*��0����*/
void zero(nNode_ship *head, int num)
{
	nNode_ship *ship;
	ship = head->next;
	int x;
	for (x = 0; x < num; x++)
	{
		if (ship != NULL)
		{
			ship->LuckyNum = 0;
			ship = ship->next;
		}
	}
}

/*����n����ȡ*/
nNode_ship *shoot(nNode_ship *head, int num, int time_one, nNode_per *per_head)
{
	nNode_ship *ship;
	nNode_per *per;
	per = per_head->next;
	ship = head->next;
	srand((int)time(NULL));

	zero(head, num);

	int x, single = 0;
	int y;
	for (x = 0; x < time_one; x++)
	{
		ship = head->next;
		per = per_head->next;
		single = (rand() % 1000) + 1;
		for (y = 0; y < num; y++)
		{
			if (per != NULL)
			{
				if ((single >= per->LuckyNum_L) && (single < per->LuckyNum_H))
					ship->LuckyNum++;
				ship = ship->next;
				per = per->next;
			}
		}
	}
	return head;
}

/*�ж�n���Ƿ��ҵ*/
int all(nNode_ship *head, int num)
{
	nNode_ship *ship;
	ship = head->next;
	int flag = 0;
	int x;
	for (x = 0; x < num; x++)
	{
		if (ship != NULL)
		{
			if (ship->LuckyNum != 0)
				flag++;
			ship = ship->next;
		}
	}
	if (flag == num)
		return 1;
	else
		return 0;
}

/*ͳ��m��n����ҵ�����Լ�����*/
double Statistic(int num, int times, int time_one, nNode_ship *head, nNode_per *per_head)
{
	nNode_ship *ship_result;
	double result = 0;
	int x;
	int step = times / 50;
	for (x = 0; x < times; x++)
	{
		ship_result = shoot(head, num, time_one, per_head);
		result += all(ship_result, num);

		if ((x % step) == 0)
			printf("*");
		if (x == times - 1)
			printf("\n");
	}
	double rate = 0;
	rate = (result / times) * 100;
	return rate;
}

#endif