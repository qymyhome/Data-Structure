#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAXLEN 50

#ifdef YES

struct list
{
	int key[MAXLEN];
	int len;
};
struct list seqlist;

int first = 'T';

void QuickSort(int low, int high, int input[], int n);
void ShowList(int input[], int n);

int main(int argc, char *argv[])
{
	int i;
	int n;
	int input[MAXLEN];
	srand((unsigned int)time(NULL));
	//scanf_s("%d", &seqlist.len);
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
		//scanf_s("%d", &seqlist.key[i]);
		input[i] = (rand() % 100) + 1;
	ShowList(input, n);
	QuickSort(1, n, input, n);
	ShowList(input, n);
	getchar();
	getchar();
	return 0;
}

/*显示顺序表*/
void ShowList(int input[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", input[i]);
	if (i == n + 1)
		printf("\n");
}
/*快速排序*/
void QuickSort(int low, int high, int input[], int n)
{
	int i, j, key, temp;
	if (low > high)
		return;
	key = input[low];
	i = low;
	j = high;
	while (i != j)
	{
		while (input[j] >= key && i < j)
			j--;
		while (input[i] <= key && i < j)
			i++;
		if (i < j)
		{
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}
	input[low] = input[i];
	input[i] = key;
	ShowList(input, n);
	QuickSort(low, i - 1, input, n);
	QuickSort(i + 1, high, input, n);
}
#endif // YES
