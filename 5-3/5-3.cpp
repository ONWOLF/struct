// 5-3.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int Data;//���ݽṹ����
	struct btnode * Llink;//������ָ��
	struct btnode * Rlink;//������ָ��
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

		//�����µĽڵ�
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);//�½ڵ㸳ֵ
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;
		if (currentNode != NULL)
		{
			parentNode = currentNode;//�洢��ǰ�����
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


		//�����������Ϊ���������������������ȼ�1
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
	printf("\n�����Ķ��������Ϊ:%d\n", depth(btree));
}