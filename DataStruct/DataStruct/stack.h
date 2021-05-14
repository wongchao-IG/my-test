#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"
////////////////////////////////////////////////////
//Ë³ÐòÕ»
#define _STACK_DEFAULT_SIZE_ 8
#define _STACK_INC_SIZE 3

typedef struct SeqStack
{
	ElemType *base;
	size_t capacity;
	int top;
}SeqStack;

void StackInit(SeqStack *pst);
void StackPush(SeqStack *pst, ElemType x);
void StackPop(SeqStack *pst);
bool StackIsFull(SeqStack *pst);
bool StackIsEmpty(SeqStack *pst);
void StackPrint(SeqStack *pst);
void StackSeek(SeqStack *pst);
void CheckCapacity(SeqStack *pst);



void CheckCapacity(SeqStack *pst)
{
	assert(pst != NULL);
	if (pst->top >= pst->capacity)
	{
		pst->base = (SeqStack *)realloc(pst->base, sizeof(ElemType)*pst->capacity*2);
		pst->capacity *= 2;
	}
	printf("À©ÈÝ³É¹¦\n");
}
void StackInit(SeqStack *pst)
{
	pst->base = (ElemType *)malloc(sizeof(ElemType)*_STACK_DEFAULT_SIZE_);
	assert(pst->base != NULL);
	pst->capacity = _STACK_DEFAULT_SIZE_;
	pst->top = 0;

}
void StackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (StackIsFull(pst))
		CheckCapacity(pst);
	pst->base[pst->top++] = x;
}
void StackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (StackIsEmpty(pst))
	{
		printf("Õ»¿Õ\n");
		return;
	}
	pst->top--;
}
bool StackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool StackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}
void StackPrint(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top-1; i >= 0; --i)
	{
		printf("%d\n", pst->base[i]);
	}
	printf("\n");
}
void StackSeek(SeqStack *pst)
{
	assert(pst != NULL);
	if (StackIsEmpty(pst))
	{
		return;
	}
	printf("%d", pst->top - 1);
}


///////////////////////////////////////////////////
//Á´Õ»
typedef struct ListStackNode
{
	ElemType data;
	struct ListStackNode *link;
}ListStackNode;
typedef struct ListStack
{
	ListStackNode *top;
}ListStack;

void ListStackInit(ListStack *pst);
void ListStackPush(ListStack *pst, ElemType x);
void ListStackPop(ListStack *pst);
void ListStackPrint(ListStack *pst);
void ListStackTop(ListStack *pst);

void ListStackInit(ListStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}
void ListStackPush(ListStack *pst, ElemType x)
{
	assert(pst != NULL);
	ListStackNode *p = (ListStackNode *)malloc(sizeof(ListStackNode));
	p->data = x;
	p->link = pst->top;
	pst->top = p;
}
void ListStackPop(ListStack *pst)
{
	assert(pst != NULL);
	ListStackNode *p = pst->top;
	pst->top = p->link;
	free(p);
	/*pst->top = pst->top->link;*/
}
void ListStackPrint(ListStack *pst)
{
	assert(pst != NULL);
	ListStackNode *p = pst->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");

}
#endif // !_STACK_H_

