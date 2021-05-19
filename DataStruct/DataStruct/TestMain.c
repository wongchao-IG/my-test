#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
#include"list.h"
#include"stack.h"
//#include"queue.h"
#include"tree.h"

//ABC##DE##F##G#H##
int main()
{
	//ABC##D##E#F#H##G##
	const char *str = "ABC##DE##F##G#H#";
	BinTree bt;
	BinTreeInit(&bt);
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str);

	printf("VLR:>");
	PreOrder(&bt);
	printf("\n");

	printf("LVR:>");
	InOrder(&bt);
	printf("\n");

	printf("LRV:>");
	PostOrder(&bt);
	printf("\n");

	printf("LEV;>");
	LevelOrder(&bt);
	printf("\n");

	printf("�������ڵ����:>");
	BinTreeSize(&bt);
	printf("\n");

	printf("�������߶�:>");
	BinTreeHeight(&bt);

}

//int main()
//{
//	////˳��ջ
//	SeqStack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	StackPush(&st, 5);
//	StackPush(&st, 6);
//	StackPush(&st, 7);
//	StackPush(&st, 8);
//	StackPush(&st, 9);
//	StackPush(&st, 10);
//	StackPrint(&st);
//	StackPop(&st);
//	StackPrint(&st);
//	////��ջ
//	ListStack pst;
//	ListStackInit(&pst);
//	ListStackPush(&pst, 1);
//	ListStackPush(&pst, 2);
//	ListStackPush(&pst, 3);
//	ListStackPush(&pst, 4);
//	ListStackPush(&pst, 5);
//	ListStackPrint(&pst);
//	//////////////////////////
//	//����
//	SeqQueue Q;
//	SeqQueueInit(&Q);
//	SeqQueueEnque(&Q, 1);
//	SeqQueueEnque(&Q, 2);
//	SeqQueueEnque(&Q, 3);
//	SeqQueueEnque(&Q, 4);
//	SeqQueueEnque(&Q, 5);
//	SeqQueuPrint(&Q);
//	//ѭ������
//	CircleQueue Q;
//	CircleQueueInit(&Q);
//	CircleQueuePush(&Q, 1);
//	CircleQueuePush(&Q, 2);
//	CircleQueuePush(&Q, 3);
//	CircleQueuePush(&Q, 4);
//	CircleQueuePush(&Q, 5);
//	CircleQueuePush(&Q, 6);
//	CircleQueuePush(&Q, 7);
//	CircleQueuePop(&Q);
//	CircleQueuePush(&Q, 8);
//	CircleQueuePrint(&Q);
//	//��ʽ����
//	ListQueue QL;
//	ListQueueInit(&QL);
//	ListQueuePush(&QL, 1);
//	ListQueuePush(&QL, 2);
//	ListQueuePush(&QL, 3);
//	ListQueuePush(&QL, 4);
//	ListQueuePush(&QL, 5);
//	ListQueuePush(&QL, 6);
//	ListQueuePrint(&QL);
//
//}



//void Test_List()
//{
//	//List mylist; 
//	//SListInit(&mylist);
//	
//	/*ListCreateTail(&mylist);*/
//	//ListCreateHead(&mylist);
//	
//	/*ListInit(&mylist);
//	ListCreateHead(&mylist);
//	ListShow(mylist);*/
//}
/*
int main()
{
	DCList mylist;
	DCListInit(&mylist);
	ElemType item;
	DCListNode * pos;
	ElemType key;
	int select = 1;
	while (select)
	{
		printf("**************************************************\n");
		printf("* [1]push_back                    [2]push_front  *\n");
		printf("* [3]show_list                    [0]quit_system *\n");
		printf("* [4]pop_back                     [5]pop_front   *\n");
		printf("* [6]insert_pos                   [7]insert_val  *\n");
		printf("* [8]delete_pos                   [9]delete val  *\n");
		printf("* [10]find_val                    [11]length_val *\n");
		printf("* [12]capacity                    [13]sort       *\n");
		printf("* [14]reverse                     [15]clear      *\n");
		printf("* [16]removeall                                  *\n");
		printf("**************************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPusnBack(&mylist, item);
			}

			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPusnFrount(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ�����λ��:>\n");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			DCListInsert(&mylist, pos, item);
			break;
		case 7:
			DCListSort(&mylist);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			DCListErase(&mylist, pos);
			printf("ɾ���ɹ�\n");
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			printf("ɾ�� %d �ɹ���\n", item);
			break;
		case 10:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			DCListNode *pos = DCListFind(&mylist, key);
			if (pos == NULL)
			{
				printf("Ҫ���ҵ�ֵ������.\n");
			}
			else
			{
				printf("Ҫ���ҵ�ֵΪ:> %d\n", pos->data);
			}
			break;
		case 11:
			printf("seqlist len = %d\n", DCListLength(&mylist));
			break;
		case 12:
			printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			DCListSort(&mylist);
			printf("˳�������ɹ�.\n");
			break;
		case 14:
			DCListRevsrse(&mylist);
			printf("reverse����ɹ�\n");
			break;
		case 15:
			DCListClear(&mylist);
			printf("�������ɹ�.\n");
			break;
		case 16:
			printf("����Ҫɾ�����ظ�����:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			printf("ɾ���ظ����� %d �ɹ�\n", key);
			break;
		default:
			break;
		}

	}
	DCListDestory(&mylist);
	printf("GoodBye!");
	return 0;
}
//
//int main()
//{
//	Test_List();
//	return 0;
//}

/*
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	ElemType item;
	ElemType pos;
	ElemType key;
	int select = 1;
	while (select)
	{
		printf("**************************************************\n");
		printf("* [1]push_back                    [2]push_front  *\n");
		printf("* [3]show_list                    [0]quit_system *\n");
		printf("* [4]pop_back                     [5]pop_front   *\n");
		printf("* [6]insert_pos                   [7]insert_val  *\n");
		printf("* [8]delete_pos                   [9]delete val  *\n");
		printf("* [10]find_val                    [11]length_val *\n");
		printf("* [12]capacity                    [13]sort       *\n");
		printf("* [14]reverse                     [15]clear      *\n");
		printf("* [16]removeall                                  *\n");
		printf("**************************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d",&item),item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ�����λ��:>\n");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			SeqListInsert(&mylist, pos, item);
			break;
		case 7:
			SeqListSort(&mylist);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			printf("ɾ���ɹ�\n");
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &item);
			SeqListDeleteVal(&mylist, item);
			printf("ɾ�� %d �ɹ���\n", item);
			break;
		case 10:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
			{
				printf("Ҫ���ҵ�ֵ������.\n");
			}
			else
			{
				printf("Ҫ���ҵ�ֵ��λ��Ϊ:> %d\n", pos);
			}
			break;
		case 11:
			printf("seqlist len = %d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("˳�������ɹ�.\n");
			break; 
		case 14:
			SeqListReverse(&mylist);
			printf("reverse˳���ɹ�\n");
			break;
		case 15:
			SeqListClear(&mylist);
			printf("������ݱ�ɹ�.\n");
			break;
		case 16:
			printf("����Ҫɾ�����ظ�����:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			printf("ɾ���ظ����� %d �ɹ�\n", key);
			break;
		default:
			break;
		}

	}
	SeqListDestroy(&mylist);
	printf("GoodBye!");
	return 0;
}*/