// 5-2.cpp : �������̨Ӧ�ó������ڵ㡣
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
		btreetype parentNode=NULL;

		//�����µĽڵ�
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;
		if (currentNode == NULL)
			root = newNode;//�½����Ϊ���������ڵ�
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
			//������ֵ��С���Ӹ��ڵ���ӽڵ�
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

	//��ӡ������
	p = root->Llink;
	printf("�����Ķ�����������Ϊ��");
	while (p!=NULL)
	{
		printf("%d", p->Data);
		p = p->Llink;
	}

	//��ӡ������
	p = root->Rlink;
	printf("�����Ķ�����������Ϊ��");
	while (p != NULL)
	{
		printf("%d", p->Data);
		p = p->Rlink;
	}
}

//����������
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