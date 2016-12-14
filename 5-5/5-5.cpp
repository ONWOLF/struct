// 5-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>	
#define MAX 50
//二叉树存储结构
typedef struct btnode
{
	int Data;
	struct btnode  *Llink;
	struct btnode  *Rlink;
}btnode,*btreetype;

void PutputTree(btreetype &root)
{
	btreetype p;

	//打印左子树
	p = root->Llink;
	printf("建立的二叉树左子树为：");
	while (p!=NULL)
	{
		printf("%d", p->Data);
		p = p->Llink;
	}

	//打印右子树
	p = root->Rlink;
	printf("建立的二叉树左子树为：");
	while (p != NULL)
	{
		printf("%d", p->Data);
		p = p->Rlink;
	}
}

void PreOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if (p != NULL)
	{
		printf("%d", p->Data);
		PreOrder(p->Llink);//递归处理左子树
		PreOrder(p->Rlink);
	}
}

void InOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if (p != NULL)
	{
		InOrder(p->Llink);
		printf("%d", p->Data);
		InOrder(p->Rlink);
	}
}

void InOrder_Norecursion(btreetype &root)
{
	btreetype stack[MAX];
	btreetype p;
	int top = 0;
	p = root;
	do
	{
		while (p != NULL)
		{
			top++;
			stack[top] = p;
			p = p->Llink;
		}
		if (top > 0)
		{
			p = stack[top];
			top--;
			printf("%d", p->Data);
			p = p->Rlink;
		}
	} while (p != NULL || top != 0);
}

void PostOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if (p != NULL)
	{
		PreOrder(p->Llink);
		PreOrder(p->Rlink);
		printf("%d", p->Data);
	}
}


btreetype CreatrTree(int n)
{
	int i;
	btreetype root = NULL;

	for (i = 0; i < n; i++)
	{
		btreetype newNode;
		btreetype currentNode;
		btreetype parentNode;

		//建立新的结点
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);/*新结点赋值*/	
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;//存储当前结点指针
		if (currentNode == NULL)
			root = newNode;
		else
		{
			while (currentNode != NULL)
			{
				parentNode = currentNode;
				if (newNode->Data < currentNode->Data)
					currentNode = currentNode->Llink;
				else
					currentNode = currentNode->Rlink;


				//根据数值大小连接父节点和子节点
				if (newNode->Data < parentNode->Data)
					parentNode->Llink = newNode;
				else
					parentNode->Rlink = newNode;
			}
		}
	}
	return root;
}


void main()
{
	btreetype btree;
	int count;
	printf("input the number of elements:\n");
	scanf_s("%d", &count);
	printf("input data(num=%d):\n", count);
	btree = CreatrTree(count);
	//二叉树遍历
	printf("\n先序遍历建立的二叉树");
	PreOrder(btree);
	printf("\n中序遍历建立的二叉树（递归方式）");
	InOrder(btree);
	printf("\n中序遍历建立的二叉树（非递归方式）");
	InOrder_Norecursion(btree);
	printf("\n后序遍历建立的二叉树");
	PostOrder(btree);
}