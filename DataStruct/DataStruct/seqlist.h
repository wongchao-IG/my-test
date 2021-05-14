#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"
#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8


typedef struct SeqList
{
	ElemType *base;//int 
	size_t capacity;
	size_t size;
}SeqList;

/////////////////////////////////////////////////
//���������ӿ�
static bool _Inc(SeqList *pst);

void SeqListInit(SeqList *pst);
bool IsFull(SeqList *pst);
bool IsEmpty(SeqList *pst);
void SeqListPushBack(SeqList *pst,ElemType x);
void SeqListPushFront(SeqList *pst, ElemType x);
void SeqListPopBack(SeqList *spt);
void SeqListPopFront(SeqList *pst);
void SeqListShow(SeqList *pst);
size_t SeqListLength(SeqList *pst);
size_t SeqListCapacity(SeqList *pst);
void SeqListClear(SeqList *pst);
void SeqListInsert(SeqList *pst, size_t pos, ElemType x);
void SeqListInsertByVal(SeqList *pst,ElemType x);
void SeqListSort(SeqList *pst);
void SeqListDeleteByPos(SeqList *pst,int pos);
int SeqListFind(SeqList *pst, ElemType key);
void SeqListDeleteVal(SeqList *pst, ElemType x);
void SeqListReverse(SeqList *pst);
void SeqListRemoveAll(SeqList *pst, ElemType key);

/////////////////////////////////////////////////////
//�����ӿ�ʵ��

static bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType *)realloc(pst->base, sizeof(ElemType)*pst->capacity * 2);
	if (new_base == NULL)
		return false;
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}

bool IsFull(SeqList *pst)
{
	return pst->size >= pst->capacity;
}

bool IsEmpty(SeqList *pst)
{
	return pst->size == 0;
}

void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}


void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{//�ռ����������ݲ��ɹ�
		printf("˳���ռ����������ܲ�������%d", x);
		return;
	}
	pst->base[pst->size++] = x;
}

void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���ռ����������ܲ�������%d", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

void SeqListPopBack(SeqList *pst)
{
	assert(pst != NULL);
	if(IsEmpty(pst))
	{
		printf("˳����,����β��ɾ��Ԫ��.\n");
		return;
	}
	pst->size--;
}
void SeqListPopFront(SeqList *pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳����,����ͷ��ɾ��Ԫ��.\n");
		return;
	}
	for (int i = 0; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListDestroy(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->base)
	{
		free(pst->base);
	}
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

size_t SeqListLength(SeqList *pst)
{
	assert(pst != NULL);
	return pst->size;
}

size_t SeqListCapacity(SeqList *pst)
{
	assert(pst != NULL);
	return pst->capacity;
}

void SeqListInsert(SeqList *pst, size_t pos, ElemType x)
{
	assert(pst != NULL);
	if (pos<0 || pos>pst->size)
	{
		printf("Ҫ���������λ�÷Ƿ��� %d ���ܲ���", x);
		return;
	}
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���ռ�����,���ܰ�λ�ò������� %d\n", x);
		return;
	}
	for (int i = pst->size; i > pos; --i)
		pst->base[i] = pst->base[i - 1];
	pst->base[pos] = x;
	pst->size++;
}

void SeqListInsertByVal(SeqList *pst, ElemType x)
{
	//�Ӻ���ǰ�Ƚ�
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���ռ�����,���ܰ�ֵ���� %d.\n", x);
		return;
	}
	int end = pst->size;
	while (end > 0 && x < pst->base[end - 1])
	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = x;
	pst->size++;
}


int SeqListFind(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	for (int i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}
	return -1;
}

void SeqListDeleteVal(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����ɾ��\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("Ҫɾ�������ݲ����ڣ�����ɾ��.\n");
		return;
	}
	SeqListDeleteByPos(pst, pos);
}

void SeqListDeleteByPos(SeqList *pst, int pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ����ܰ�λ��ɾ��Ԫ��.\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("Ҫɾ�����ݵ�λ�÷Ƿ�,���ܰ�λ��ɾ������.\n");
		return;
	}
	for (int i = pos; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListReverse(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->size < 2)
		return;
	ElemType left = 0;
	ElemType right = pst->size - 1;
	while (left < right)
	{
		Swap(&pst->base[left], &pst->base[right]);
		left++;
		right--;
	}
 }

void SeqListRemoveAll(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����ɾ��\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
		return;
	while (pos < pst->size)
	{
		SeqListDeleteByPos(pst, pos);
		if (key == pst->base[pos])
			continue;
		else
			pos++;
	}
}

void SeqListSort(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->size <= 1)
		return;
	for (int i = 0; i < pst->size-1; ++i)
	{
		for (int j = 0; j < pst->size - 1 - i; ++j)
		{
			if (pst->base[j] > pst->base[j + 1]) 
			{
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

void SeqListClear(SeqList *pst)
{
	assert(pst != NULL);
	pst->size = 0;
}

//��ǰ����Ƚ�
//assert(pst != NULL);
//if (IsFull(pst))
//{
//	printf("˳���ռ�����,���ܰ�ֵ���� %d.\n", x);
//}
//int pos = 0;
//int i;
//for (i = 0; i < pst->size; ++i)
//{
//	if (x < pst->base[i])
//	{
//		pos = i;
//		break;
//	}
//}
//if (i >= pst->size)
//{
//	pos = i;
//}
//SeqListInsert(pst, pos, x);
#endif // !_SEQLIST_H_
