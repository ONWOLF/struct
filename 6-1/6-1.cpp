// 6-1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//ͼ����Ӵ洢��ʾ
typedef struct ArcNode
{
	int adjvex;
	char info;
	struct ArcNode *nextarc;

}ArcNode;

typedef struct Vnode
{
	char data;
	ArcNode *link;
}Vnode,AdjList[MAX+1];

typedef struct 
{
	AdjList vertices;
	int vexnum;
	int arcmun;

}ALGraph;


//ͼ���ڽӾ����ʾ
typedef struct
{
	int n;
	char vexs[MAX + 1];
	int arcs[MAX + 1][MAX + 1];
}AdjMatrix;


void AdjListToAdjMatrix(AdjList gl, AdjMatrix &gm, int n)
{
	int i, j;
	ArcNode*p;
	for (i = 1; i <= MAX; i++)
		for (j = 1; j <= MAX; j++)
			gm.arcs[i][j] = 0;

	for (i = 1; i <= n; i++)
	{
		p = gl[i].link;
		while (p != NULL)
		{
			gm.arcs[i][p->adjvex] = 1;
			p = p->nextarc;
		}
	}
}


void AdjMatrixToAdjList(AdjMatrix gm, AdjList &gl, int n)
{
	int i, j;
	ArcNode *p;
	for (i = 1; i <= n; i++)
	{
		gl[i].data = 0;
		gl[i].link = NULL;
	}

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (gm.arcs[i][j] == 1)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->nextarc = gl[i].link;
				gl[i].link = p;
			}
}

void CreateGraph(ALGraph &G)
{
	int i, s, d;
	ArcNode *p;

	for (i = 1; i <= G.vexnum; i++)
	{
		getchar();
		printf("��%d�������Ϣ(char)��:", i);
		scanf_s("%c", &G.vertices[i].data);
		G.vertices[i].link = NULL;
	}

	for (i = 1; i <= G.arcmun; i++)
	{
		printf("��%d����----�����ţ��յ����:", i);
		scanf_s("%d %d", &s, &d);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = d;
		p->info = G.vertices[d].data;
		p->nextarc = G.vertices[s].link;
		G.vertices[s].link = p;
	}
}

void OutputAdjList(ALGraph &G)
{
	int i;
	ArcNode *p;
	printf("ͼ���ڽӱ����£�\n");
	for (i = 1; i <= G.vexnum; i++)
	{
		printf("[%c]", G.vertices[i].data);
		p = G.vertices[i].link;
		while (p != NULL)
		{
			printf("--->(%d %c)", p->adjvex, p->info);
			p = p->nextarc;
		}
		printf("\n");
	}
}


void OutputAdjMatrix(AdjMatrix gm, int n)
{
	printf("ͼ���ڽӾ�������:\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d", gm.arcs[i][j]);
		printf("\n");
	}
}

void main()
{
	ALGraph G;
	AdjMatrix gm;
	printf("���������ͱ���");
	scanf_s("%d %d", &G.vexnum,&G.arcmun);
	CreateGraph(G);
	AdjListToAdjMatrix(G.vertices, gm, G.vexnum);

	OutputAdjList(G);
	OutputAdjMatrix(gm, G.vexnum);
}