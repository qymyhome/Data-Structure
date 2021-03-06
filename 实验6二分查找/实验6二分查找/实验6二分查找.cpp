#include "pch.h"
#include "stdio.h"

#define SUCCESS 1
#define FAIL 0

int binSuccess  = 0;
int binPos = 0;
int binCount = 0;

void sort(int input[], int n);
void search(int input[], int key, int sampleNum);

int main(int argc[], char *argv[])
{
	int data[50] = { 0 };
	int key, times, sampleNum;
	printf("输入：测试次数\n      元素个数 元素\n      查找关键字的值\n");
	printf("输出：是否成功 位置 查找次数\n\n");
	scanf_s("%d", &times);
	for (int i = 0; i < times; i++)
	{
		scanf_s("%d", &sampleNum);
		for (int j = 1; j <= sampleNum; j++)
			scanf_s("%d", &data[j]);
		sort(data, sampleNum);;
		scanf_s("%d", &key);
		search(data, key, sampleNum);
		printf("输出%d:%d %d %d\n\n", i+1, binSuccess, binPos, binCount);
	}
	return 0;
}

void sort(int input[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		if (input[i] < input[i - 1])
		{
			temp = input[i];
			for (j = i - 1; j >= 0; j--)
			{
				if (temp < input[j])
					input[j + 1] = input[j];
				else
					break;
			}
			input[j + 1] = temp;
		}
	}
}

void search(int input[], int key, int sampleNum)
{
	binSuccess = 0;
	binPos = 0;
	binCount = 0;
	int flag = 1;
	int low, mid, high;
	low = 1;
	high = sampleNum + 1;
	while ((low <= high) && (binSuccess == 0))
	{
		mid = (int)((low + high) / 2);
		if (key == input[mid])
		{
			binSuccess = SUCCESS;
			binPos = mid;
			binCount++;
			if (flag == 1)
				binCount = 1;
		}
		else if (key > input[mid])
		{
			low = mid + 1;
			binCount++;
		}
		else if (key < input[mid])
		{
			high = mid - 1;
			binCount++;
		}
		flag++;
	}
}