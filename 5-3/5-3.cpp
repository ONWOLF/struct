// 5-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//
typedef struct btnode
{
	int Data;//数据结构内容
	struct btnode * Llink;//左子树指针
	struct btnode * Rlink;//右子树指针
}btnode ,*btreetype;



btreetype CreateTree(int n)
{
	int i;
	btreetype root = NULL;

	for (i = 0; i < n; i++)
	{
		btreetype newNode;
		btreetype currentNode;
		btreetype parentNode;

		//建立新的节点
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);//新节点赋值
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;
		if (currentNode != NULL)
		{
			parentNode = currentNode;//存储当前父结点
			if (newNode->Data < currentNode->Data)
				currentNode = currentNode->Llink;
			else
				parentNode->Rlink = newNode;
		}
	}
	return root;
}

int depth(btreetype &root)
{
	btreetype p;
	p = root;

	int dep1;
	int dep2;
	if (root == NULL)
		return 0;
	else
	{
		dep1 = depth(p->Llink);
		dep2 = depth(p->Rlink);


		//二叉树的深度为左子树或右子树的最大深度加1
		if (dep1 > dep2)
			return (dep1 + 1);
		else
			return(dep2 + 1);
	}
}


void main()
{
	btreetype btree;
	int count;
	printf("input the number of elements:\n");
	scanf_s("%d", &count);
	printf("input data(num=%d):\n", count);
	btree = CreateTree(9);
	printf("\n建立的二叉树深度为:%d\n", depth(btree));
}