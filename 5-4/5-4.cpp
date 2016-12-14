// 5-4.cpp : 定义控制台应用程序的入口点。
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
	int Data;//节点数据内容
	struct btnode *Llink; //左子树指针
	struct btnode *Rlink;//柚子树指针
}btnode,*btreetype;

btreetype CreateTree(int n)
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

		currentNode = root;
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
				{
					currentNode = currentNode->Rlink;
				}

				//根据数值大小连接父结点和子结点
				if (newNode->Data < parentNode->Data)
					parentNode->Llink = newNode;
				else
					parentNode->Rlink = newNode;

			}
		}
	}
	return root;
}


int Check(btreetype &root)
{
	btreetype p;
	p = root;

	//进行比较判别
	if (p == NULL)
		return 1;
	if (p->Llink && (p->Llink->Data > p->Data))
		return 0;
	if (p->Rlink && (p->Rlink->Data < p->Data))
		return 0;
	//进行递归判别
	return (Check(p->Llink) && Check(p->Rlink));
}


void main()
{
	btreetype btree;
	int count;
	printf("input the number of elements:\n");
	scanf_s("%d", &count);
	printf("input data(num=%d):\n", count);
	btree = CreateTree(count);
	if (Check(btree))
		printf("建立的二叉树是二叉排序树");
	else
		printf("建立的二叉树不是二叉排序树");
}