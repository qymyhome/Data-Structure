#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"
#include "pch.h"

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


struct persent_num
{
	float LuckyNum_L;
	float LuckyNum_H;
	struct persent_num *next;
};
typedef persent_num nNode_per;

nNode_ship *ship_input(int ship_num);
nNode_per *calculate_num(int ship_num, nNode_ship *L);
int simulate(int ship_num, nNode_ship *ship, nNode_per *num, int times, int times_one);