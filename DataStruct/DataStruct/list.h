#ifndef _LIST_H_
#define _LIST_H_

#include "common.h"

////////////////////////////////////////////////////////
//带头结点的双循环链表
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;

typedef struct DCList
{
	DCListNode *head;
}DCList;

////////////////////////////////////////////////////////
//接口声明
static DCListNode *_Buydnode(ElemType x);
void DCListInit(DCList *plist);
void DCListPusnBack(DCList *plist,ElemType x);
void DCListPusnFrount(DCList *plist,ElemType x);
void DCListPopBack(DCList *plist);
void DCListPopFront(DCList *plist);
DCListNode* DCListFind(DCList* pHead, ElemType x);


void DCListRevsrse(DCList *plist);
void DCListShow(DCList *plist);
size_t DCListLength(DCList *plist);
//双向链表清除 
void DCListClear(DCList *plist);
//链表排序
void DCListSort(DCList *plist);

// 双向链表销毁
void DCListDestory(DCList *plist);

// 双向链表按值进行插入
void DCListInsertByVal(DCList* plist, ElemType x);
// 双向链表按值进行删除
void DCListDeleteByVal(DCList* plist, ElemType x);
// 双向链表在pos的前面进行插入
void DCListInsert(DCList* plist,ElemType pos, ElemType x);
// 双向链表删除pos位置的节点
void DCListErase(DCList* plist, ElemType pos);

////////////////////////////////////////////////////////
//函数实现
static DCListNode *_Buydnode(ElemType x)
{
	DCListNode *s = (DCListNode *)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}
void DCListInit(DCList *plist)
{
	plist->head = _Buydnode(0);
}
void DCListPusnBack(DCList *plist,ElemType x)
{
	DCListNode *s = _Buydnode(x);
		s->prev = plist->head->prev;
		s->prev->next = s;
		s->next = plist->head;
		plist->head->prev = s;
}

void DCListPusnFrount(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *s = _Buydnode(x);
	s->next = plist->head->next;
	s->next->prev = s;
	s->prev = plist->head;
	plist->head->next = s;
}
void DCListPopBack(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->prev;
	if (p == plist->head)
		printf("链表为空.\n");
		return;
	plist->head->prev = p->prev;
	p->prev->next = plist->head;
	free(p);
}
void DCListPopFront(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	if (p == plist->head)
		printf("链表为空.\n");
		return;
	plist->head->next = p->next;
	p->next->prev = plist->head;
	free(p);
}
void DCListShow(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over. \n");
}
//双向链表查找
DCListNode* DCListFind(DCList *plist, ElemType key)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head  && key != p->data)
	{
		p = p->next;
	}
	return p;
}
void DCListClear(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		DCListNode *t = p->next;
		plist->head->next = p->next;
		p->next->prev = plist->head;

		free(p);
		p = t;
	}
}
// 双向链表销毁
void DCListDestory(DCList *plist)
{
	DCListClear(plist);
	free(plist->head);
	plist->head = NULL;
}
// 双向链表在pos的前面进行插入
void DCListInsert(DCList* plist,ElemType pos, ElemType x)
{
	assert(plist != NULL);
	DCListNode *s = _Buydnode(x);
	DCListNode *p = plist->head->next; int n = 1;
		while (p != plist->head )
		{
			if (n == pos)
			{
				s->next = p;
				s->prev = p->prev;
				p->prev->next = s;
				p->prev = s;
				free(p);
				return;
			}
			p = p->next;
			n++;
		}
}
// 双向链表删除pos位置的节点
void DCListErase(DCList* plist,ElemType pos)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next; int n = 1;
	while (p != plist->head)
	{
		if (n == pos)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			return;
		}
		p = p->next;
		n++;
	}
}
size_t DCListLength(DCList *plist)
{
	assert(plist != NULL);
	size_t len = 0;
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}
//按值插入
void DCListInsertByVal(DCList* plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head && p->data < x)
		p = p->next;
	DCListNode *s = _Buydnode(x);
	s->prev = p->prev;
	s->next = p;
	p->prev->next = s;
	p->prev = s;
}
//按值删除 
void DCListDeleteByVal(DCList* plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *p = DCListFind(plist, x);
	if (p == NULL)
		return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}
void DCListSort(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	DCListNode *q = p->next;
	p->next = plist->head;
	plist->head->prev = p;

	while (q != plist->head)
	{
		p = q;
		q = q->next;

		DCListNode *t = plist->head->next;
		while (t != plist->head && t->data < p->data)
			t = t->next;

		p->next = t;
		p->prev = t->prev;
		p->next->prev = p;
		p->prev->next = p;
		
		p = q;
	}

}
//转置链表
void DCListRevsrse(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	DCListNode *q = p->next;
	
	p->next = plist->head;
	plist->head->prev = p;
	while (q != plist->head)
	{
		p = q;
		q = q->next;

		p->next = plist->head->next;
		p->prev = plist->head;
		p->next->prev= p;
		p->prev->next = p;
	}
}
///////////////////////////////////////////////////////
//单链表
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;
/////////////////////////////////////////////////////
//单链表接口函数声明
static SListNode *_Buynode(ElemType x);
void SListInit(SList *plist);
void SListPushBack(SList *plist, ElemType x);
void SListPushFrount(SList *plist, ElemType x);
void SListPopBack(SList *plist);
void SListPopFront(SList *plist);
SListNode* SListFind(SList *plist, ElemType x);
void SListInsertByVal(SList *plist, ElemType x);

void SListDeleteByVal(SList *plist, ElemType x);
size_t SListLength(SList *plist);
void SListRevevse(SList *plist);

void SListSort(SList *plist);
void SListShow(SList *plist);
void SListDestroy(SList *plist);
void SListClear(SList *plist);

/////////////////////////////////////////////////////
//单链表接口函数声实现
size_t SListLength(SList *plist)//链表长度
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	size_t n = 0;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
static SListNode *_Buynode(ElemType x)//购买节点
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
void SListInit(SList *plist)//初始化链表
{
	plist->head = NULL;
}

void SListPushBack(SList *plist, ElemType x)//有头节点的链表尾插
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);

	if (plist->head == NULL)//空链表
	{
		plist->head = s;
		return;
	}
	SListNode *p = plist->head;//非空链表
	while (p->next != NULL)
		p = p->next;
	p->next = s;

}

void SListPushFrount(SList *plist, ElemType x)//有头节点头插
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);

	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList *plist)//尾部删除
{
	assert(plist != NULL);
	SListNode *p,*prev;
	if (plist->head == NULL)//空链表
		return;
	p = plist->head;
	if (p->next == NULL)//非空链表
		plist->head = NULL;
	else
	{
		while (p->next != NULL)//获取最后一个链表
		{
			prev = p;
			p = p->next;	
		}
		prev->next = NULL;
	}
	free(p);
}

void SListPopFront(SList *plist)//头删
{
	assert(plist != NULL); 
	SListNode *p = plist->head;
	if (plist->head == NULL)
		return;
	plist->head = p->next;
	free(p); 
}

void SListDeleteByVal(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode* pos = SListFind(plist, x);
	if (NULL == pos)
	{
		printf("要删除的节点不存在.\n");
		return;
	}
	if (pos == plist->head)
		plist->head = pos->next;
	else
	{
		prev = plist->head;
		while (prev->next != pos)
			prev = prev->next;
		prev->next = pos->next;
	}
	free(pos);
}

void SListInsertByVal(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	SListNode *prev = NULL;
	SListNode *s = _Buynode(x);
	
	while(p != NULL && x > p->data)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
	{
		s->next = p;
		plist->head = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

void SListShow(SList * plist)
{
	SListNode *p = plist->head;
	while (p !=NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void SListSort(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q, *t, *prev = NULL;
	
	plist->head->next = NULL;
	t = plist->head;
	while (p != NULL)
	{
		q = p->next;

		while (t != NULL && p->data > t->data)
		{
			prev = t;
			t = t->next;
		}
		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		p = q;
		t = plist->head;
	}
}

SListNode* SListFind(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
	plist->head = NULL;
}

void SListClear(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}
void SListRevevse(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q;
	if (p == NULL)
		return;
	plist->head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

//定义链表节点
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;




void ListInit(List *plist)
{
	*plist = (ListNode *)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}

void ListCreateTail(List *plist)//尾插单链表
{
	assert(plist != NULL);
	ListNode *p = *plist;
	for (int i = 1; i <= 10; ++i)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}

void ListCreateHead(List *plist)//头插单链表
{
	assert(*plist != NULL);
	for (int i = 1; i <= 10; ++i) 
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL); 
		s->data = i;
		s->next = (*plist)->next;
		(*plist)->next = s;
	}
	

}

void ListShow(List plist)//显示链表
{
	ListNode *p = plist->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
//void ListInit(List *plist)
//{
//	*plist = NULL;
//}

//void ListCreateTail(List *plist)//尾插单链表
//{
//	(*plist) = (ListNode*)malloc(sizeof(ListNode));
//	assert(*plist != NULL);
//	(*plist)->data = 1;
//	(*plist)->next = NULL;
//
//	ListNode *p = *plist;
//	for (int i = 2; i <= 10; ++i)
//	{
//		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
//		assert(s != NULL);
//		s->data = i;
//		s->next = NULL;
//
//		p->next = s;
//		p = s;
//	}
//}
//
//void ListCreateHead(List *plist)//头插单链表
//{
//	(*plist) = (ListNode *)malloc(sizeof(ListNode));
//	(*plist != NULL);
//	(*plist)->data = 1;
//	(*plist)->next = NULL;
//
//	for (int i = 2; i < 10; ++i)
//	{
//		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
//		assert(s != NULL);
//		s->data = i;
//		s->next = *plist;
//
//		(*plist) = s;
//	}
//}
//void ListShow(List plist)
//{
//	ListNode *p = plist;
//	while (p != NULL)
//	{
//		printf("%d->", p->data);
//		p = p->next;
//	}
//	printf("Over!\n");
//}*/
#endif // !_LIST_H_

