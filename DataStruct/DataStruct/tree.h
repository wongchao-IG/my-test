#ifndef _TREE_H_
#define _TREE_H_

#include"common.h"

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *LeftChild;
	struct BinTreeNode *RightChild;

}BinTreeNode;// 定义树结点结构体包括节点值，左子树和右子树的指针

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;//定义二叉树

#define LEVEL_ORDER

#ifdef LEVEL_ORDER

typedef struct QueueNode
{
	BinTreeNode* data;
	struct ListQueueNode *next;
}QueueNode;

typedef struct ListQueue
{
	QueueNode *front;
	QueueNode *rear;
}ListQueue;

QueueNode * _BuyQueueNode(x);
void ListQueueInit(ListQueue *Lq);
void ListQueuePush(ListQueue *Lq, BinTreeNode* x);
void ListQueuePop(ListQueue *Lq);
void ListQueuePrint(ListQueue *Lq);
bool ListQueueEmpty(ListQueue *pq);
BinTreeNode* ListQueueFront(ListQueue *pq);

QueueNode * _BuyQueueNode(x)
{
	QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
	p->data = x;
	p->next = NULL;
	return p;
}
void ListQueueInit(ListQueue *Lq)
{
	Lq->front = Lq->rear = NULL;
}
void ListQueuePush(ListQueue *Lq, BinTreeNode* x)
{
	assert(Lq != NULL);
	QueueNode *q = _BuyQueueNode(x);
	if (Lq->front == NULL)
	{
		Lq->rear = Lq->front = q;
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

BinTreeNode* ListQueueFront(ListQueue *pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}
#endif // LEVEL_ORDER

//创建
void BinTreeInit(BinTree *pbt);
void BinTreeCreate(BinTree *bt);
void BinTreeCreate_1(BinTreeNode **t);
BinTreeNode *BinTreeCreate_2();
void BinTreeCreateByStr(BinTree *bt, const char *str);
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex);

//遍历
void PreOrder(BinTree *t);
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *t);
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *t);
void PostOrder_1(BinTreeNode *t);
void LevelOrder(BinTree *t);
void LevelOrder_1(BinTreeNode *bt);


//求二叉树
int BinTreeSize(BinTree *bt);//求二叉树节点个数
int BinTreeSize_1(BinTreeNode *t);
int BinTreeHeight(BinTree *bt);//求二叉树高度
int BinTreeHeight_1(BinTreeNode *t);


//查找二叉树节点
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key);
BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType key);
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key);
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key);

//拷贝二叉树
BinTreeNode *BinTreeCopy(BinTree *bt);

//判断二叉树
bool BinTreeEqual(BinTree *bt1, BinTree bt2);



void BinTreeCreateByStr(BinTree *bt,const char *str)
{
	int index = 0;
	BinTreeCreateByStr_1(str, &index);
}
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == NULL)
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}




void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}

void BinTreeCreate(BinTree *bt)
{
	BinTreeCreate_1(&bt->root);
	//BinTreeCreate_2();
}

void BinTreeCreate_1(BinTreeNode **t)
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->LeftChild);
		BinTreeCreate_1(&((*t)->RightChild));
	}

}

BinTreeNode* BinTreeCreate_2()
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->LeftChild = BinTreeCreate_2();
		t->RightChild = BinTreeCreate_2();
		return t;
	}
}
//遍历
void PreOrder(BinTree *t)
{
	PreOrder_1(t->root);
}
void PreOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder_1(t->LeftChild);
		PreOrder_1(t->RightChild);
	}
}
void InOrder(BinTree *t)
{
	InOrder_1(t->root);
}
void InOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		InOrder_1(t->LeftChild);
		printf("%c ", t->data);
		InOrder_1(t->RightChild);
	}
}
void PostOrder(BinTree *t)
{
	PostOrder_1(t->root);
}
void PostOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		PostOrder_1(t->LeftChild);
		PostOrder_1(t->RightChild);
		printf("%c ", t->data);
	}
}
void LevelOrder(BinTree *t)//层次遍历
{
	LevelOrder_1(t->root);
}
void LevelOrder_1(BinTreeNode *bt)
{
	if (bt != NULL)
	{
		ListQueue Q;
		ListQueueInit(&Q);
		ListQueuePush(&Q, bt);
		while (!ListQueueEmpty(&Q))//队列为空，则结束遍历
		{
			BinTreeNode* p = ListQueueFront(&Q);
			ListQueuePop(&Q);
			printf("%c", p->data);
			if (p->LeftChild != NULL)
				ListQueuePush(&Q,p->LeftChild);
			if (p->RightChild != NULL)
				ListQueuePush(&Q, p->RightChild);
		}
	}
}

int BinTreeSize(BinTree *bt)//节点个数
{
	return BinTreeSize_1(bt->root);
}
int BinTreeSize_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
	{
		return BinTreeSize_1(t->LeftChild) + BinTreeSize_1(t->RightChild) + 1;
	}
}
int BinTreeHeight(BinTree *bt)
{
	return BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = BinTreeHeight_1(t->LeftChild);
		int right_h = BinTreeHeight_1(t->RightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}

BinTreeNode* BinTreeFind(BinTree *bt, ElemType key)
{
	return BinTreeFind_1(bt->root, key);
}

BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if (t == NULL || t->data == key)
		return t;
	p = BinTreeFind_1(t->LeftChild, key);
	if (p != NULL)
		return p;
	return BinTreeFind_1(t->RightChild, key);
}
//查找节点的父节点
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key)
{
	return BinTreeParent_1(bt->root, key);
}

BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if (t == NULL || t->data == key)
		return t;
	if ((t->LeftChild != NULL && t->LeftChild->data == key) ||
		(t->RightChild != NULL && t->RightChild->data == key))
		return t;
	p = BinTreeParent_1(t->LeftChild, key);
	if (p != NULL)
		return p;
	return BinTreeParent_1(t->RightChild, key);
}
#endif // !_TREE_H_
