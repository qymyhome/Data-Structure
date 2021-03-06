// 顺序表实验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//玄学

#include "pch.h"
#include "stdio.h"

#define MAXSIZE 20

//输出表中元素
int print(int example[], int num)
{
	int circle_2;
	for (circle_2 = 0; circle_2 < num; circle_2++)
	{
		printf("%d ", example[circle_2]);
		if (circle_2 == num - 1)
			printf("\n");
	}
	return 0;
}

int main(int argc[], char *argv[])
{
	//创建顺序表
	int sqlist[MAXSIZE];
	printf("输入数据元素个数，20个以内：\n");
	int sample_num;
	scanf_s("%d", &sample_num);
	printf("输入数据元素：\n");
	int circle_1;
	for (circle_1 = 0; circle_1 < sample_num; circle_1++)
		scanf_s("%d", &sqlist[circle_1]);

	print(sqlist, sample_num);

	//指定位置给出数据
	int pos;
	printf("输入数据位置：");
	scanf_s("%d", &pos);
	if (pos > MAXSIZE - 1)
	{
		printf("超过表长，请输入1到20之内的数字\n");
		scanf_s("%d", &pos);
	}
	printf("输出：%d\n", sqlist[pos - 1]);

	//指定位置插入数据
	int new_num, new_pos;
	printf("想要插入的数据的位置：");
	scanf_s("%d", &new_pos);
	printf("想要插入的数据：");
	scanf_s("%d", &new_num);
	printf("\n");
	int temp;
	temp = sqlist[new_pos - 1];
	sample_num++;

	int circle_3;//移动表中数据
	for (circle_3 = sample_num; circle_3 > new_pos - 1; circle_3--)
	{
		sqlist[new_pos - 1] = new_num;
		sqlist[circle_3 + 1] = sqlist[circle_3];
	}
	sqlist[new_pos] = temp;
	print(sqlist, sample_num);

	//指定位置删除元素
	int delete_pos;
	printf("输入要删除的元素的位置：");
	scanf_s("%d", &delete_pos);
	printf("\n");

	int circle_4;//移动表中数据
	for (circle_4 = delete_pos; circle_4 < sample_num; circle_4++)
		sqlist[circle_4 - 1] = sqlist[circle_4];
	sample_num--;
	print(sqlist, sample_num);

	getchar();
	getchar();
	return 0;
}