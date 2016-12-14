// 5-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}


#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE 59
#define MAXBIT 10
#include<stdio.h>

//哈弗曼树结构
typedef struct
{
	int data;//结点值
	int Weight;//权重
	int Flag;//标识是否待构结点，是的话用0表示，否则1表示
	int Parent;//父结点
	int LChild;
	int RChild;
}hnodetype;

typedef struct
{
	int Bit[MAXBIT];
	int Start;
}hcodetype;


void InitHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i;
	//把生成的结点初始化，把所有指针置空
	for (i = 0; i < 2 * n - 1; i++)
	{
		HuffNode[i].Weight = 0;
		HuffNode[i].Parent = 0;
		HuffNode[i].Flag = 0;
		HuffNode[i].LChild = 0;
		HuffNode[i].RChild = 0;
	}
	for (i = 0; i < n; i++)
	{
		getchar();
		printf("输入第%d个叶子结点：", i + 1);
		scanf_s("%c", &HuffNode[i].data);
		printf("输入对应结点权值");
		scanf_s("%d", &HuffNode[i].Weight);
	}
}


void OutputHuffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i, j;
	printf("%d个叶结点对应编码为：\n", n);
	for (i = 0; i < n; i++)
	{
		printf("%c----", HuffNode[i].data);
		for (j = HuffCode[i].Start + 1; j < n; j++)
			printf("%d", HuffCode[i].Bit[j]);
		printf("\n");
	}
}


void Haffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i, j, m1, m2, x1, x2, c, p;
	hcodetype cd;

	for (i = 0; i < n - 1; i++)//构造哈弗曼树
	{
		//根据哈弗曼树构成过程，始终选择最小权值的两个结点构成一颗二叉树
		m1 = m2 = MAXVALUE;
		x1 = x2 = 0;
		for (j = 0; j < n + 1; j++)
		{
			if (HuffNode[j].Weight < m1&&HuffNode[j].Flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].Weight;
				x1 = j;//记下x1的地址
			}
			else if (HuffNode[j].Weight < m2&&HuffNode[j].Flag == 0)
			{
				m2 = HuffNode[j].Weight;
				x2 = j;
			}
		}

		//把找到的两个节点按照哈夫曼树的规则构建一个二叉树
		HuffNode[x1].Parent = n + i;
		HuffNode[x2].Parent = n + i;
		HuffNode[x1].Flag = 1;
		HuffNode[x2].Flag = 1;
		HuffNode[n + i].Weight = HuffNode[x1].Weight + HuffNode[x2].Weight;
		HuffNode[n + i].LChild = x1;
		HuffNode[n + i].RChild = x2;

	}

	for (i = 0; i < n; i++)
	{
		cd.Start = n - 1;
		c = i;
		p = HuffNode[c].Parent;

		while (p != 0)
		{
			//如果当前是左孩子则编码为0
			if (HuffNode[p].LChild == c)
				cd.Bit[cd.Start] =0;
			else
				cd.Bit[cd.Start] = 1;
			cd.Start--;
			c = p;
			p = HuffNode[c].Parent;
		}

		for (j = cd.Start + 1; j < n; j++)
		{
			HuffCode[i].Bit[j] = cd.Bit[j];
			HuffCode[i].Start = cd.Start;
		}
	}

}


void main()
{
	hnodetype HuffNode[MAXNODE];
	hcodetype HuffCode[MAXLEAF];
	int n;
	printf("输入叶子结点个数n:\n");
	scanf_s("%d", &n);

	InitHaffman(HuffNode, HuffCode, n);
	Haffman(HuffNode, HuffCode, n);
	OutputHuffman(HuffNode, HuffCode, n);
}