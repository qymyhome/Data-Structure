﻿#include "pch.h"
#include "stdio.h"

#define MAXLEN 50
struct list
{
	int key[MAXLEN];
	int len;
};

int first = 'T';

void QuickSort(int low, int high, struct list seqlist);
void ShowList(struct list seqlist);

int main(int argc, char *argv[])
{
	int i;
	struct list seqlist;
	scanf_s("%d", &seqlist.len);
	for (i = 1; i <= seqlist.len; i++)
		scanf_s("%d", &seqlist.key[i]);
	ShowList(seqlist);
	QuickSort(1, seqlist.len, seqlist);
	ShowList(seqlist);
	getchar();
	getchar();
	return 0;
}

/*显示顺序表*/
void ShowList(struct list seqlist)
{
	int i;
	for (i = 1; i <= seqlist.len; i++)
		printf("%d ", seqlist.key[i]);
	if (i == seqlist.len + 1)
		printf("\n");
}
/*快速排序*/
void QuickSort(int low, int high, struct list seqlist)
{
	int i, j, pivotkey;
	i = low;
	j = high;
	pivotkey = seqlist.key[low];
	while (low < high)
	{
		while ((seqlist.key[high] > pivotkey) && (high > 0))
			high--;
		if(seqlist.key[high]<pivotkey)
			seqlist.key[low] = seqlist.key[high];
		while ((seqlist.key[low] < pivotkey) && (low < seqlist.len))
			low++;
		if (seqlist.key[low] > pivotkey)
			seqlist.key[high] = seqlist.key[low];
	}
	seqlist.key[low] = pivotkey;
	if (first == 'T')
	{
		ShowList(seqlist);
		first = 'F';
	}
	if (i < low - 1)
		QuickSort(i, low - 1, seqlist);
	if (high + 1 < j)
		QuickSort(high + 1, j, seqlist);
}