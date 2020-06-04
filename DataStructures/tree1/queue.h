/*
 * queue.h
 *
 *  Created on: Jun. 3, 2020
 *      Author: andres
 */

#ifndef QUEUE_H_
#define QUEUE_H_

struct _Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}typedef Node;


//The following part defines a circular Queue that will help in the
//creation of the tree
struct Queue
{
	int size;
	int front;
	int rear;
	//This used to be int *Q, it is double
	Node **Q;
};

void create(struct Queue *q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q=(Node **)malloc(q->size*sizeof(Node *));
}

void enqueue(struct Queue *q, Node *x)
{
	if((q->rear+1)%q->size==q->front)
	{
		printf("Queue is Full");
	}
	else
	{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}

Node * dequeue(struct Queue *q)
{
	Node * x = NULL;

	if(q->front == q->rear)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		q->front = (q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}
#endif /* QUEUE_H_ */
