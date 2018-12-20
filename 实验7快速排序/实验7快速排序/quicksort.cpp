#include "pch.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define MAXLENGTH 50
#define YES

struct list
{
	int element[MAXLENGTH];
	int len;
};
typedef struct list list;

#ifdef YES
void show_list(list *p);
void quick_sort(int low, int high, list *p);

int show = 'T';

int main(int argc, char *argv[])
{
	list new_list;
	srand((unsigned int)time(NULL));
	//list *list_p = &new_list;
	scanf_s("%d", &new_list.len);
	int n;
	for (n = 1; n <= new_list.len; n++)
		//scanf_s("%d", &new_list.element[n]);
		new_list.element[n] = (rand() % 100) + 1;
	quick_sort(1, new_list.len, &new_list);
	show_list(&new_list);
	return 0;
}

/*显示列表元素*/
void show_list(list *p)
{
	int x;
	for (x = 1; x <= p->len; x++)
		printf("%d ", p->element[x]);
	if (x == p->len + 1)
		printf("\n");
}

/*快速排序*/
void quick_sort(int low, int high, list *p)
{
	int i, j, key, temp;
	i = low;
	j = high;
	key = p->element[low];
	if (i >= j)
		return;
	while (i != j)
	{
		while (p->element[j] >= key && i < j)
			j--;
		while (p->element[i] <= key && i < j)
			i++;
		if (i < j)
		{
			temp = p->element[i];
			p->element[i] = p->element[j];
			p->element[j] = temp;
		}
	}
	p->element[low] = p->element[i];
	p->element[i] = key;
	if (show == 'T')
	{
		show_list(p);
		show = 'F';
	}
	quick_sort(low, i - 1, p);
	quick_sort(i + 1, high, p);
}
#endif // YES
