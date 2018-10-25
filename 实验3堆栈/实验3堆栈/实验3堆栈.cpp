#include "pch.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"
#include "stdlib.h"

#define MAXSIZE 50
#define ERROR -1
typedef struct sqstack
{
	char *top;
	char *bottom;
	int stack_size;
}stack;

int creatstack(stack *nStack);
int push(char sign, stack *nStack);
int pop(char *sign, stack *nStack);
int signmatch(stack *nStack, char input[], int lenth);

int main(int argv[], char *argc[])
{
	printf("请输入元素：");
	char str[MAXSIZE];
	scanf_s("%s", str, MAXSIZE);
	int lenth = strlen(str);
	stack sign_stack;
	creatstack(&sign_stack);

	int value = 5;
	int flag = 1;
	while (flag == 1)
	{
		value = signmatch(&sign_stack, str, lenth);
		printf("%d", value);
		printf("继续？Y/N\n");
		if ((getchar() == 'Y') || (getchar() == 'y'))
			flag = 1;
		else
			flag = 0;
	}
	return 0;
}

/*初始化栈*/
int creatstack(stack *nStack)
{
	nStack->bottom = (char*)malloc(MAXSIZE * sizeof(char));
	if (nStack->bottom == NULL)
		return ERROR;
	nStack->top = nStack->bottom;
	nStack->stack_size = MAXSIZE;
	return 0;
}

/*将元素压入栈中*/
int push(char sign, stack *nStack)
{
	if (nStack->top - nStack->bottom >= MAXSIZE)
	{
		printf("OVERFLOW");
		return ERROR;
	}
	*(nStack->top) = sign;
	nStack->top++;
	return 0;
}

/*将元素从栈内弹出*/
int pop(char *sign, stack *nStack)
{
	if (nStack->top == nStack->bottom)
	{
		printf("EMPTY STACK!!");
		return ERROR;
	}
	nStack->top--;
	*sign = *(nStack->top);
	return 0;
}

/*匹配括号*/
int signmatch(stack *nStack, char input[], int lenth)
{
	char pop_sign = '\0';
	char *s = &pop_sign;
	int turn;
	for (turn = 0; turn < lenth; turn++)
	{
		if ((input[turn] == '(') || (input[turn] == '[') || (input[turn] == '{'))
			push(input[turn], nStack);
		else if ((input[turn] == ')') || (input[turn] == ']') || (input[turn] == '}'))
		{
			if (nStack->top == nStack->bottom)
				return -2;
			pop(s, nStack);
			if ((pop_sign == '(') && (input[turn] != ')'))
				return -1;
			else if ((pop_sign == '[') && (input[turn] != ']'))
				return -1;
			else if ((pop_sign == '{') && (input[turn] != '}'))
				return -1;

		}
	}
	if (nStack->top == nStack->bottom)
		return 0;
	else if (nStack->top != nStack->bottom)
		return -3;
}