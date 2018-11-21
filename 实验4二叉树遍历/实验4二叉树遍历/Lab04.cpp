#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define ERROR -1

typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}tree;

//typedef struct stack
//{
//	tree *top;
//	tree *base;
//}stack;

int nodeID;

tree *creatTree(char *input, int num);
void preorder(tree *t);
void inorder(tree *t);
void postorder(tree *t);
//int pop(tree *t);
//int push(tree *t);

int main(int argc[], char *argv[])
{
	int element_num = 0;
	char element[100] = { '\0' };
	scanf_s("%d", &element_num);
	fflush(stdin);
	scanf_s("%s", &element, 100);
	nodeID = -1;
	tree *new_tree = creatTree(element, element_num);
	preorder(new_tree);
	printf("\n");
	inorder(new_tree);
	printf("\n");
	postorder(new_tree);
	getchar();
	getchar();
	return 0;
}


/*创建二叉树*/
tree *creatTree(char *input, int num)
{	
	nodeID++;
	if (nodeID > num + 1)
		return NULL;
	if (input[nodeID] == '0')
		return NULL;
	tree *ntree = (tree*)malloc(sizeof(tree));
	ntree->data = input[nodeID];
	
	ntree->lchild = creatTree(input, num);
	ntree->rchild = creatTree(input, num);
	return ntree;
}

/*先序遍历*/
void preorder(tree *t)
{
	if (t == NULL)
		return;
	printf("%c", t->data);  
	preorder(t->lchild);   
	preorder(t->rchild); 
}

/*中序遍历*/
void inorder(tree *t)
{
	if (t == NULL)
		return;
	inorder(t->lchild);
	printf("%c", t->data);
	inorder(t->rchild);
}

/*后序遍历*/
void postorder(tree *t)
{
	if (t == NULL)
		return;
	postorder(t->lchild);
	postorder(t->rchild);
	printf("%c", t->data);
}