#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"
#include "pch.h"

#define Ver1

struct ship_data
{
	char name[10];
	char rare[5];
	double persent;
	int LuckyNum;
	struct ship_data *next;
};
typedef struct ship_data nNode_ship;


struct persent_num
{
	double LuckyNum_L;
	double LuckyNum_H;
	struct persent_num *next;
};
typedef persent_num nNode_per;

nNode_ship *ship_input(int ship_num);
nNode_per *calculate_num(int ship_num, nNode_ship *L);

#ifdef Ver0
int simulate(int ship_num, nNode_ship *ship, nNode_per *num, int times, int times_one);

#else Ver1
nNode_ship *shoot(nNode_ship *head, int num, int time_one, nNode_per *per_head);
int all(nNode_ship *head, int num);
double Statistic(int num, int times, int time_one, nNode_ship *head, nNode_per *per_head);

#endif