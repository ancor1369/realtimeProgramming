//============================================================================
// Name        : treecpp.cpp
// Author      : Andres Cordoba
// Version     :
// Copyright   : This is free software
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"
#include "stdio.h"

using namespace std;


class Tree
{
public:
	Node *root;
	Tree(){root = NULL;}
	void createTree();
	void Preorder(Node *p);
	void Postorder(Node *p);
	void Inorder(Node *p);
	void Levelorder(Node *p);
	int Height(Node *p);
	int Count(Node *root);
};

void Tree::createTree()
{
		Node *p, *t;
		int x;
		Queue q(100);


		printf("Enter root value ");
		scanf("%d",&x);
		root= new Node;
		root->data=x;
		root->lchild=root->rchild=NULL;
		q.enqueue(root);

		while(!q.isEmpty())
		{
			p=q.dequeue();
			printf("Enter left child %d ",p->data);
			scanf("%d", &x);
			if(x!=-1)
			{
				t = new Node;
				t->data = x;
				t->lchild=t->rchild=NULL;
				p->lchild = t;
				q.enqueue(t);
			}
			printf("Enter right child %d ", p->data);
			scanf("%d", &x);
			if(x!=-1)
			{
				t = new Node;
				t->data = x;
				t->lchild=t->rchild=NULL;
				p->rchild = t;
				q.enqueue(t);
			}

		}
}




void Tree::Preorder(Node *p)
{
	if(p)
	{
		printf("%d \n", p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Tree::Postorder(Node *p)
{
	if(p)
	{

		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d \n", p->data);
	}
}

void Tree::Inorder(Node *p)
{
	if(p)
	{
		Inorder(p->lchild);
		printf("%d \n", p->data);
		Inorder(p->rchild);
	}
}


void Tree::Levelorder(Node *p)
{
	Queue q(100);
	printf("%d ", root->data );
	q.enqueue(root);

	while(!q.isEmpty())
	{
		root = q.dequeue();
		if(root->lchild)
		{
			printf("%d ",root->lchild->data);
			q.enqueue(root->lchild);
		}
		if(root->rchild)
		{
			printf("%d ", root->rchild->data);
			q.enqueue(root->rchild);
		}
	}
}

int Tree::Count(Node *root)
{
	if(root)
		return Count(root->lchild)+Count(root->lchild)+1;
	return 0;
}

int Tree::Height(Node *p)
{
	int x=0, y=0;
	if(root==0)
	{
		return 0;
	}
	x=Height(root->lchild);
	y=Height(root->rchild);
	if(x>y)
		return x+1;
	else
		return y+1;
}



int main()
{
	Tree t;
	t.createTree();
	t.Preorder(t.root);
	t.Inorder(t.root);

	return 0;
}
