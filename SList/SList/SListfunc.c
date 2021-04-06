#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;
}

void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		printf("空\n");
		return 0;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* cur = *pplist;
		SListNode* pre = *pplist;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		pre->next = NULL;
	}

}

void SListPopFront(SListNode** pplist)
{
	SListNode* pre = *pplist;
	*pplist = (*pplist)->next;
	free(pre);
	pre = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
	{
		printf("空\n");
		return plist;
	}
	else
	{
		SListNode* move = plist;
		while (move->data != x)
		{
			move = move->next;
			if (move == NULL)
			{
				return NULL;
			}
		}
		return move;
	}

}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* pro = pos->next;
	SListNode* add = BuySListNode(x);
	pos->next = add;//pos->next 取到struct SListNode* next 地址传地址???
	add->next = pro;
}
