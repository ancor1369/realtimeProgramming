/*
 * main.c
 *
 *  Created on: Jun. 3, 2020
 *      Author: andres
 */

#include <stdio.h>
#include "queue.h"

Node *root = NULL;

void treeCreate()
{
	Node *p, *t;
	int x;
	struct Queue q;
	create(&q,100);

	printf("Enter root value ");
	scanf("%d",&x);
	root=(Node *)malloc(sizeof(Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);

	while(!isEmpty(q))
	{
		p=dequeue(&q);
		printf("Enter left child %d ",p->data);
		scanf("%d", &x);
		if(x!=-1)
		{
			t = (Node *)malloc(sizeof(Node));
			t->data = x;
			t->lchild=t->rchild=NULL;
			p->lchild = t;
			enqueue(&q,t);
		}
		printf("Enter right child %d ", p->data);
		scanf("%d", &x);
		if(x!=-1)
		{
			t = (Node *)malloc(sizeof(Node));
			t->data = x;
			t->lchild=t->rchild=NULL;
			p->rchild = t;
			enqueue(&q,t);
		}

	}
}

void Inorder(Node *p)
{
	if(p)
	{
		Inorder(p->lchild);
		printf("%d \n", p->data);
		Inorder(p->rchild);
	}
}

void postorder(Node *p)
{
	if(p)
	{

		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d \n", p->data);
	}
}


int main()
{

	treeCreate();
	Inorder(root);
	printf("\n");
	postorder(root);
	return 0;
}
