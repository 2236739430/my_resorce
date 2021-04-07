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
	if (plist == NULL)
	{
		printf("空的\n");
		return 0;
	}
	else
	{
		SListNode* cur = plist;
		while (cur != NULL)
		{
			printf("%d\n", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
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
		printf("空了\n");
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
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* pre = *pplist;
		*pplist = (*pplist)->next;
		free(pre);
		pre = NULL;
	}
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
		while (move != NULL)
		{	
			if (move->data == x)
			{
				return move;
			}
			move = move->next;
		}
		return NULL;
	}

}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* pro = pos->next;
	SListNode* add = BuySListNode(x);
	pos->next = add;//pos->next 取到struct SListNode* next = SListNode* *a(next);故可以直接传
	add->next = pro;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
	    SListNode* pro = pos->next;
	    SListNode* pronext = pos->next->next;
	    pos->next = pronext;
	    free(pro);
	pro = NULL;
	}

}

void SListDestory(SListNode* plist)
{
	if (plist == NULL)
	{
		return 0;
	}
	else
	{
		SListNode* ps = plist;
		while (ps != NULL)
		{
			SListPopBack(&ps);
		}
	}
}