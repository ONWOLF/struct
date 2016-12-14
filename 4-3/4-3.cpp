// 4-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#define OK 1
#define MAX 10

//定义三元组表
typedef struct
{
	int i, j;
	int v;
}TriTupleNode;

typedef struct
{
	TriTupleNode data[MAX];
	int m;
	int n;
	int t;
}TSMatrix;

void InitTriTupleNode(TSMatrix *a)
{
	int i=0, j=0, k, val, maxrow, maxcol;
	maxrow = 0;
	maxcol = 0;
	k = 1;
	while (i != -1 && j != -1)
	{
		printf("input row col val:");
		scanf_s("%d %d %d", &i, &j, &val);
		a->data[k].i = i;
		a->data[k].j = j;
		a->data[k].v = val;
		if (maxrow < i)
			maxrow = i;
		if (maxcol < j)
			maxcol = j;
		k++;
	}
	a->m = maxrow;
	a->n = maxcol;
	a ->t = k;
}


void ShowMatrix(TSMatrix *a)
{
	int p, q;
	int t = 1;
	for (p = 1; p <= a->m; p++)
	{
		for (q = 1; q <= a->n; q++)
			if (a->data[t].i == p&&a->data[t].j == q)//打印非零元素
			{
				printf("%d  ", a->data[t].v);
				t++;
			}
			else
				printf("0  ");
		printf("\n");
	}//for
}
void TransposeSMatrix(TSMatrix *a, TSMatrix *b)
{
	int q, col, p;
	b->m = a->n;
	b->n = a->m;
	b->t = a->t;
	if (b->t)
	{
		q = 1;
		for(col=1;col<=a->n;col++)
			for(p=0;p<=a->t;p++)
				if (a->data[p].j == col)
				{
					b->data[q].i = a->data[p].j;
					b->data[q].j = a->data[p].i;
					b->data[q].v = a->data[p].v;
					++q;
				}
	}//if
}

void main()
{
	TSMatrix a, b;
	TSMatrix *pa = &a, *pb = &b;
	InitTriTupleNode(pa);
	printf("稀疏矩阵转置前：\n");
	ShowMatrix(pa);
	printf("稀疏矩阵转置后：\n");
	TransposeSMatrix(pa, pb);
	ShowMatrix(pb);
}