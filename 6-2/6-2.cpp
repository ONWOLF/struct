// 6-2.cpp : �������̨Ӧ�ó������ڵ㡣
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
}Vnode, AdjList[MAX + 1];

typedef struct
{
	AdjList vertices;
	int vexnum;
	int arcmun;

}ALGraph;

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

void DFS(AdjList g,int v, int visited[])
{
	ArcNode *w;
	int i;
	printf("%d ", v);
	visited[v] = 1;
	w = g[v].link;
	while (w != NULL)
	{
		i = w->adjvex;
		if (visited[i] == 0)
			DFS(g, i, visited);
		w = w->nextarc;
	}
}



void BFS(AdjList g, int v, int visited[])
{
	int qu[MAX], f = 0, r = 0;
	ArcNode *p;
	printf("%d ", v);
	visited[v] = 1;
	qu[0] = v;
	while (f <= r)
	{
		v = qu[f++];
		p = g[v].link;
		while (p != NULL)
		{
			v = p->adjvex;
			if (visited[v] == 0)
			{
				visited[v] = 1;
				printf("%d ", v);
				qu[++r] = v;
			}
			p = p->nextarc;
		}
	}
}

void Traver(AdjList g, int n, int id)
{
	int i;
	static int visited[MAX];
	for (i = 1; i <= n; i++)
		visited[i] = 0;
	for(i=1;i<=n;i++)
		if (visited[i] == 0)
		{
			if (id == 1)
				DFS(g, i, visited);
			if (id == 2)
				BFS(g, i, visited);
		}
}

void main()
{
	ALGraph G; 
	int id;
	printf("���������ͱ���:");
	scanf_s("%d %d", &G.vexnum, &G.arcmun);
	CreateGraph(G);

	printf("ѡ����ȱ�������ȱ���:(1 DFS,2 BFS)");
	scanf_s("%d", &id);
	Traver(G.vertices, G.vexnum, id);
}
