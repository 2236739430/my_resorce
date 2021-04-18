#include "qlistnode.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		printf("error\n");
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;
	if (q->rear == NULL)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = q->rear->next;
	}
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
	{
		return 1;
	}
	return 0;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}


QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	
	return q->front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QNode* move = q->front;
	while (move != q->rear)
	{
		move = move->next;
		size++;
	}
	return size;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
}