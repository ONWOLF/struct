// 5-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//
//    return 0;
//}

#include <stdio.h>
#define MAX 30

void CreateTree(int *bt, int list[], int n)
{
	int i;
	int level;

	for (i = 0; i < MAX; i++)
		bt[i] = 0;

	bt[0] = list[0];
	for (i = 1; i < n; i++)
	{
		level = 1;
		while (bt[level]!=0)
		{
			if (list[i]<bt[level])
			{
				level = level * 2;
			}
			else
			{
				level = level * 2 + 1;
			}
			bt[level] = list[i];
		}
	}
}



void main()
{
	int count, i;
	int btree[MAX];
	int nodelist[MAX];

	printf("input the number ofelements(n<50):\n");
	scanf_s("%d", &count);
	printf("input elements:\n");
	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &nodelist[i]);
	}
	CreateTree(btree, nodelist, count);
	printf("the binary tree is:\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%d", btree[i]);
	}
	printf("\n");
}