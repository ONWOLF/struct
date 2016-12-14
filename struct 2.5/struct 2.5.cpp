// struct 2.5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int main()
//{
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data;
	struct stack*link;
}sStack,*sNode;

sStack *createStack()
{
	sStack*p;
	p = (sStack*)malloc(sizeof(sStack));
	p->link = NULL;
	return p;
}

void push(sNode &head, int e)
{
	sStack *p;
	p = (sStack*)malloc(sizeof(sStack));
	p->data = e;
	p->link = head;
	head = p;
}

void pop(sNode &head)
{
	sStack *p;
	int e;
	if (head == NULL)
		exit(0);
	e = head->data;
	p = head;
	head = head->link;
	free(p);
}

int getStackTop(sNode &head)
{
	return head->data;
}

int isEmpty(sNode &head)
{
	if (head == NULL)
		return 0;
	else
		return 1;
}

void compare(sNode &head, int a, int b)
{
	int t;
	if (a > b)
	{
		pop(head);
		if (isEmpty(head))
		{
			t = getStackTop(head);
			compare(head, a, t);

		}
		else
			push(head, a);
		push(head, b);
	}
	else
		push(head, a);
}



void main()
{
	int temp;
	int a[100];
	int num;

	sNode pStack;
	sNode head;

	printf("input the number of array:\n");
	scanf_s("%d", &num);
	printf("input the vale of %d number of array:\n", num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", &a[i]);

	pStack = createStack();
	head = pStack->link;

	for (int j = 0; j < num; j++)
	{
		if (isEmpty(head))
		{
			temp = getStackTop(head);
			compare(head, a[j], temp);

		}
		else
			push(head, a[j]);
	}

	printf("sort by asc:\n");
	for (int k = 0; head != NULL; k++, head = head -> link)
		printf("%d", head->data);
	printf("\n");

}