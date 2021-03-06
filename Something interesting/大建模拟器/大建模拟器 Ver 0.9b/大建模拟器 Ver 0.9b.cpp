// 大建模拟器 Ver 0.9b.cpp
//用于模拟碧蓝航线中的活动建造情况
//玄不改非，氪不改命，玄学建造，就在大建模拟器，给你一个欧皇与非酋并存的世界
//见证奇迹吧

#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "module.h"

#define Ver1

int main(int argc[], char *argv[])
{
	printf("欢迎来到欧皇模拟器，下面输入你要模拟建造的船的条数：\n");
	int num;
	scanf_s("%d", &num);

	int flag = 1;

	nNode_ship *ship;
	ship = ship_input(num);
	int times = 0, times_one = 0;
	nNode_per *ship_per;
	ship_per = calculate_num(num, ship);
	double result = 0;
	
	while (flag != 0)
	{
		printf("输入模拟次数：\n");
		scanf_s("%d", &times);
		printf("输入一次连续抽取次数：\n");
		scanf_s("%d", &times_one);
#ifdef Ver0
		simulate(num, ship, ship_per, times, times_one);
		//输出统计结果
		nNode_ship *s = ship->next;
		nNode_per *p = ship_per->next;
		int circle_1;
		for (circle_1 = 0; circle_1 < num + 0; circle_1++)
		{
			printf("在%d次%d连中抽到%s的概率为：%.4f%%\n", times, times_one, s->name, s->rate);
			s = s->next;
		}
#else Ver1
		/*开始模拟*/
		result = Statistic(num, times, times_one, ship, ship_per);
		printf("%d次%d连中，毕业概率为%.2lf%%\n", times, times_one, result);
#endif
		flag = 1;
		printf("是否要继续测试：Y/N\n");
		char input;
		fflush(stdin);
		getchar();
		input = getchar();
		if (input == 'n' || input == 'N')
			flag = 0;
	}
	return 0;
}