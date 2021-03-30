#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void Checkadd(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqList* newA = (SeqList*)realloc(ps->a,sizeof(ps->a)*newcapacity);
		if (newA == NULL)
		{
			printf("error:À©ÈÝÊ§°Ü\n");
		}
		else
		{
			ps->a = newA;
			ps->capacity = newcapacity;
		}
	}

}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);

	Checkadd(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d\n",ps->a[i]);
	}

}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);

	Checkadd(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);

	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);

	Checkadd(ps);
	for (int i = ps->size - 1; i >= pos + 1; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos + 1] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}