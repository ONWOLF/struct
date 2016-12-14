// 5-5.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int Data;
	struct btnode  *Llink;
	struct btnode  *Rlink;
}btnode,*btreetype;

void PutputTree(btreetype &root)
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

void PreOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if (p != NULL)
	{
		printf("%d", p->Data);
		PreOrder(p->Llink);//�ݹ鴦��������
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

		//�����µĽ��
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf_s("%d", &newNode->Data);/*�½�㸳ֵ*/	
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;//�洢��ǰ���ָ��
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


				//������ֵ��С���Ӹ��ڵ���ӽڵ�
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
	//����������
	printf("\n������������Ķ�����");
	PreOrder(btree);
	printf("\n������������Ķ��������ݹ鷽ʽ��");
	InOrder(btree);
	printf("\n������������Ķ��������ǵݹ鷽ʽ��");
	InOrder_Norecursion(btree);
	printf("\n������������Ķ�����");
	PostOrder(btree);
}