#include "dlist.h"

ListNode* ListCreate()
{
	ListNode* New = (ListNode*)malloc(sizeof(ListNode));
	New->next = New;
	New->prev = New;
	return New;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	if (pos->next == pos)
	{
		printf("没的删\n");
		return;
	}
	ListNode* pro = pos->next;
	ListNode* pre = pos->prev;
	free(pos);
	pre->next = pro;
	pro->prev = pre;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* New = (ListNode*)malloc(sizeof(ListNode));
	New->data = x;
	New->next = pos->next;
	pos->next->prev = New;
	pos->next = New;
	New->prev = pos;
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	/*ListNode* New = (ListNode*)malloc(sizeof(ListNode));
	New->data = x;
	pHead->prev->next = New;
	New->prev = pHead->prev;
	pHead->prev = New;
	New->next = pHead;*/
	ListInsert(pHead->prev,x);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	//ListNode* New = (ListNode*)malloc(sizeof(ListNode));
	//New->data = x;
	//ListNode* next = pHead->next;
	//pHead->next = New;
	//New->prev = pHead;
	//New->next = next;
	//next->prev = New;
	ListInsert(pHead, x);
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	/*if (pHead->next == pHead)
	{
		printf("没得删\n");
		return;
	}
	ListNode* pro = pHead->next->next;
	free(pHead->next);
	pHead->next = pro;
	pro->prev = pHead;*/
	ListErase(pHead->next);
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	/*if (pHead->next == pHead)
	{
		printf("没得删\n");
		return;
	}
	ListNode* pre = pHead->prev->prev;
	free(pHead->prev);
	pre->next = pHead;
	pHead->prev = pre;*/
	ListErase(pHead->prev);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}




