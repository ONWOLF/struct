// struct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define M 4

void MatrixAdd(int m1[M][M], int m2[M][M], int result[M][M])
{
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			result[i][j]= (m1[i][j] + m2[i][j]);
	}
}

void MatrixTrams(int m1[M][M], int result[M][M])
{
	//将矩阵转置
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			result[i][j] = m1[j][i];
	}
}

void MatrixPlus(int m1[M][M], int m2[M][M], int result[M][M])
{
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k<4; k++)
				result[i][j] += m1[i][k] * m2[k][j];
		}
	}
}



void Display(int result[M][M])
{
	int i, j;
	printf("The operating result of Matrix:\n");
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<M; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
}

void main()
{
	int A[M][M];
	int B[M][M];
	int i, j;
	printf("input  the matrix:\n");
	for (i = 0; i<M; i++)
		for (j = 0; j<M; j++)
			scanf_s("%d", &A[i][j]);

	printf("input the other matrix;\n");
	for (i = 0; i<M; i++)
		for (j = 0; j<M; j++)
			scanf_s("%d", &B[i][j]);
	int result[M][M];
	printf("The operating result of Matrix:\n");
	MatrixAdd(A, B, result);
	Display(result);
	MatrixPlus(A, B, result);
	Display(result);
}