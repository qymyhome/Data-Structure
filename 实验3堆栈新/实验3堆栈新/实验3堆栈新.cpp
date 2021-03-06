// 实验3堆栈新.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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

struct input
{
	char string[MAXSIZE];
};

int creatstack(stack *nStack);
int push(char sign, stack *nStack);
int pop(char *sign, stack *nStack);
int signmatch(stack *nStack, char input[], int lenth);

int main(int argv[], char *argc[])
{
	printf("0为括号匹配正确，-1为括号不匹配，-2为右括号多于左括号，-3为左括号多于右括号\n");
	printf("输入：\n");
	struct input str[MAXSIZE];
	int rows = 0;
	scanf_s("%d", &rows);

	int m;
	for (m = 0; m < rows; m++)
		scanf_s("%s", &str[m].string, MAXSIZE);
	
	int lenth[MAXSIZE];
	int n;
	for (n = 0; n < rows; n++)
		lenth[n] = strlen(str[n].string);
	stack sign_stack;
	creatstack(&sign_stack);
	
	int q;
	for (q = 0; q < rows; q++)
	{
		int value = 5;
		value = signmatch(&sign_stack, str[q].string, lenth[q]);
		if (q == 0)
			printf("输出:");
		printf("\n%d", value);
		sign_stack.top = sign_stack.bottom;
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
			push(input[turn], nStack);			/*当检测到左括号将其压入栈内*/
		
		else if ((input[turn] == ')') || (input[turn] == ']') || (input[turn] == '}'))
		{
			if (nStack->top == nStack->bottom)
				return -2;						/*栈都空了还有右括号，肯定是右括号多了*/
			pop(s, nStack);
			if ((pop_sign == '(') && (input[turn] != ')'))
				return -1;
			else if ((pop_sign == '[') && (input[turn] != ']'))
				return -1;
			else if ((pop_sign == '{') && (input[turn] != '}'))
				return -1;						/*括号顺序不对，肯定是搭配错误啦*/
		}
	}
	
	if (nStack->top == nStack->bottom)
		return 0;								/*循环完了，栈空了，括号也没了*/
	else if (nStack->top != nStack->bottom)
		return -3;								/*嗯还有括号，那就是左边的多了*/
}