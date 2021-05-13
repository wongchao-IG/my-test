#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"common.h"

#define _SEQQUEUE_DEFAULT_SIZE_ 8
/////////////////////////////////////////
//顺序队列
typedef struct SeqQueue
{
	ElemType *base;
	int capacity;
	int front;
	int rear;
}SeqQueue;
void SeqQueueInit(SeqQueue *psq);
void SeqQueueEnque(SeqQueue *psq,ElemType x);
bool SeqQueueIsFull(SeqQueue *psq);
bool SeqQueueISEmpty(SeqQueue *psq);
void SeqQueueDeque(SeqQueue *psq);
void QueueCheckCapcity(SeqQueue *psq);
void SeqQueuPrint(SeqQueue* psq);
bool SeqQueueIsFull(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}
bool SeqQueueISEmpty(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}
void SeqQueueInit(SeqQueue *psq)
{
	psq->base = (SeqQueue *)malloc(sizeof(ElemType)*_SEQQUEUE_DEFAULT_SIZE_);
	assert(psq->base != NULL);
	
	psq->front = psq->rear = 0;
	psq->capacity = _SEQQUEUE_DEFAULT_SIZE_;
}
void SeqQueueEnque(SeqQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		QueueCheckCapcity(psq);
			return;
	}
		
	psq->base[psq->rear++] = x;
}
void SeqQueueDeque(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueISEmpty(psq))
	{
		printf("队列已空，不能出队.\n");
		return;
	}
	psq->front++;

}
void SeqQueuPrint(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueISEmpty(psq))
		return;
	while (psq->front !=psq->rear)
	{
		printf("%d\n", psq->base[psq->front++]);
	}
}
void QueueCheckCapcity(SeqQueue *psq)
{
	assert(psq != NULL);
	if (psq->rear >= psq->capacity)
		psq->base = (SeqQueue *)realloc(psq->base, sizeof(ElemType)*psq->capacity * 2);
	psq->capacity *= 2;
}
///////////////////////////////////////////////////////////////////
//循环队列
#define _CIRCLEQUEUE_DEFAULT_SIZE_ 8
typedef struct CircleQueue
{
	ElemType *base;
	int capacity;
	int front;
	int rear;
}CircleQueue;

void CircleQueueInit(CircleQueue *cq);
bool CircleQueueIsEmpty(CircleQueue *cq);
bool CircleQueueIsFull(CircleQueue *cq);
void CircleQueuePush(CircleQueue *cq,ElemType x);
void CircleQueuePop(CircleQueue *cq);
ElemType CircleQueueTop(CircleQueue *cq);
ElemType CircleQueueRear(CircleQueue *cq);
ElemType CircleQueueLength(CircleQueue *cq);
void CircleQueueDestroy(CircleQueue *cq);
void CircleQueuePrint(CircleQueue *cq);


void CircleQueueInit(CircleQueue *cq)
{
	assert(cq != NULL);
	cq->capacity = _CIRCLEQUEUE_DEFAULT_SIZE_;
	cq->base = malloc(sizeof(ElemType)*_CIRCLEQUEUE_DEFAULT_SIZE_);
	cq->front = cq->rear = 0;
}
bool CircleQueueIsEmpty(CircleQueue *cq)
{
	assert(cq != NULL);
	return cq->front == cq->rear;
}
bool CircleQueueIsFull(CircleQueue *cq)
{
	assert(cq != NULL);
	return (cq->rear + 1) % cq->capacity == cq->front;
}
void CircleQueuePush(CircleQueue *cq, ElemType x)
{
	assert(cq != NULL);
	if (CircleQueueIsFull(cq))
		return;
	cq->base[cq->rear] = x;
	cq->rear = (cq->rear + 1) % cq->capacity;
}
void CircleQueuePop(CircleQueue *cq)
{
	assert(cq != NULL);
	if (CircleQueueIsEmpty(cq))
		return;
	cq->front = (cq->front + 1) % cq->capacity;
}
ElemType CircleQueueTop(CircleQueue *cq)
{
	assert(cq != NULL);
	if (CircleQueueIsEmpty(cq))
		return;
	return cq->base[cq->front];
}
ElemType CircleQueueRear(CircleQueue *cq)
{
	assert(cq != NULL);
	if (CircleQueueIsEmpty(cq))
		return;
	return cq->base[(cq->rear + cq->capacity-1)% cq->capacity];
}
ElemType CircleQueueLength(CircleQueue *cq)
{
	assert(cq != NULL);
	int n = 0;
	while (n != cq->rear)
		n++;
	return n;
}
void CircleQueueDestroy(CircleQueue *cq)
{
	assert(cq != NULL);
	int p;
	if (CircleQueueIsEmpty(cq))
		return;
	p = cq->front;
	while (cq->rear != cq->front)
	{
		cq->front = (cq->front + 1) % cq->capacity;
	}
	printf("Destroy\n");
}
void CircleQueuePrint(CircleQueue *cq)
{
	assert(cq != NULL);
	while(cq->front != cq->rear)
	{
		printf("%d\n", cq->base[cq->front]);
		cq->front = (cq->front + 1) % cq->capacity;
	}
	
}
/////////////////////////////////////////////////////////////////
//链式队列
typedef struct QueueNode
{
	ElemType data;
	struct ListQueueNode *next;
}QueueNode;
typedef struct ListQueue
{
	QueueNode *front;
	QueueNode *rear;

}ListQueue;

QueueNode * _BuyQueueNode(x);
void ListQueueInit(ListQueue *Lq);
void ListQueuePush(ListQueue *Lq,ElemType x);
void ListQueuePop(ListQueue *Lq);
void ListQueuePrint(ListQueue *Lq);
bool ListQueueEmpty(ListQueue *pq);
ElemType ListQueueFront(ListQueue *pq);

QueueNode * _BuyQueueNode(x)
{
	QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
	p->data = x;
	p->next = NULL;
	return p;
}
void ListQueueInit(ListQueue *Lq)
{
	Lq->front = Lq->rear= NULL;
}
void ListQueuePush(ListQueue *Lq, ElemType x)
{
	assert(Lq != NULL);
	QueueNode *q = _BuyQueueNode(x);
	if (Lq->front == NULL)
	{
		Lq->rear=Lq->front = q;
	}
	else
	{
		Lq->rear->next = q;
		Lq->rear = q;
	}
}
void ListQueuePop(ListQueue *Lq)
{
	assert(Lq != NULL);
	if (Lq->front == NULL)
		return;
	Lq->front = Lq->front->next;
}
void ListQueuePrint(ListQueue *Lq)
{
	assert(Lq != NULL);
	if (Lq->front == NULL)
	{
		printf("链表为空.\n");
		return;
	}
	while (Lq->front != NULL)
	{
		printf("%d\n", Lq->front->data);
		Lq->front = Lq->front->next;
	}
}

bool ListQueueEmpty(ListQueue *pq)
{
	return pq->front == NULL;
}

ElemType ListQueueFront(ListQueue *pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}
#endif // !_QUEUE_H_

