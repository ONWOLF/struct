// 5-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct btnode
{
	int Data;
	struct btnode *Llink;
	struct btnode *Rlink;//右子树指针

}btnode,*btreetype;

btreetype CreateTree(int n)
{
	int i;
	btreetype root = NULL;

	for (i = 0; i < n; i++)
	{
		btreetype newNode;
		btreetype currentNode;
		btreetype parentNode=NULL;

		//建立新的节点
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;
		if (currentNode == NULL)
			root = newNode;//新结点作为二叉树根节点
		else
		{
			while (currentNode!=NULL)
			{
				parentNode = currentNode;
				if (newNode->Data < currentNode->Data)
					currentNode = currentNode->Llink;
				else
					currentNode = currentNode->Rlink;

			}
			//根据数值大小连接父节点和子节点
			if (newNode->Data < parentNode->Data)
				parentNode->Llink = newNode;
			else
				parentNode->Rlink = newNode;
		}

	}
	return root;
}


void OutputTree(btreetype &root)
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

//测试主程序
void main()
{
	btreetype btree;
	int count;
	printf("input the number of elements:\n");
	scanf_s("%d", &count);
	printf("input data(num=%d):\n", count);
	btree = CreateTree(9);
	OutputTree(btree);
}