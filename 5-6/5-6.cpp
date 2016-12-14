// 5-6.cpp : �������̨Ӧ�ó������ڵ㡣
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

//���������ṹ
typedef struct
{
	int data;//���ֵ
	int Weight;//Ȩ��
	int Flag;//��ʶ�Ƿ������㣬�ǵĻ���0��ʾ������1��ʾ
	int Parent;//�����
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
	//�����ɵĽ���ʼ����������ָ���ÿ�
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
		printf("�����%d��Ҷ�ӽ�㣺", i + 1);
		scanf_s("%c", &HuffNode[i].data);
		printf("�����Ӧ���Ȩֵ");
		scanf_s("%d", &HuffNode[i].Weight);
	}
}


void OutputHuffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i, j;
	printf("%d��Ҷ����Ӧ����Ϊ��\n", n);
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

	for (i = 0; i < n - 1; i++)//�����������
	{
		//���ݹ����������ɹ��̣�ʼ��ѡ����СȨֵ��������㹹��һ�Ŷ�����
		m1 = m2 = MAXVALUE;
		x1 = x2 = 0;
		for (j = 0; j < n + 1; j++)
		{
			if (HuffNode[j].Weight < m1&&HuffNode[j].Flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].Weight;
				x1 = j;//����x1�ĵ�ַ
			}
			else if (HuffNode[j].Weight < m2&&HuffNode[j].Flag == 0)
			{
				m2 = HuffNode[j].Weight;
				x2 = j;
			}
		}

		//���ҵ��������ڵ㰴�չ��������Ĺ��򹹽�һ��������
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
			//�����ǰ�����������Ϊ0
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
	printf("����Ҷ�ӽ�����n:\n");
	scanf_s("%d", &n);

	InitHaffman(HuffNode, HuffCode, n);
	Haffman(HuffNode, HuffCode, n);
	OutputHuffman(HuffNode, HuffCode, n);
}