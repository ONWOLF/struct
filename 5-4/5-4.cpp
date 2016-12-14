// 5-4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//�������洢�ṹ
typedef struct btnode
{
	int Data;//�ڵ���������
	struct btnode *Llink; //������ָ��
	struct btnode *Rlink;//������ָ��
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

		//�����µĽ��
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);/*�½�㸳ֵ*/
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

				//������ֵ��С���Ӹ������ӽ��
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

	//���бȽ��б�
	if (p == NULL)
		return 1;
	if (p->Llink && (p->Llink->Data > p->Data))
		return 0;
	if (p->Rlink && (p->Rlink->Data < p->Data))
		return 0;
	//���еݹ��б�
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
		printf("�����Ķ������Ƕ���������");
	else
		printf("�����Ķ��������Ƕ���������");
}