// 4-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}


#include <stdio.h>
#define M 4

void BubblesSort(int list[], int n)
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (list[j] < list[j - 1])
			{
				k = list[j];
				list[j] = list[j - 1];
				list[j - 1] = k;
			}
		}
	}
}


void Display(int result[M][M])
{
	int i, j;
	printf("The operating result of Matrix:\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
}

void main()
{
	int A[M][M];
	int i, j;
	printf("input the data of matrix:\n");
	for (i = 0; i < M; i++)
	   for (j = 0; j < M; j++)
		 scanf_s("%d", &A[i][j]);
	for (i = 0; i < M; i++)
		BubblesSort(A[i], M);
	Display(A);
}
