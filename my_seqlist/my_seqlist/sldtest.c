#include "sld.h"

void SeqListinit(SL* ps)
{
	ps -> a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	ps -> size = 0;
	ps -> capacity = 4;
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for(i=0; i < ps->size; i++)
	{
	    printf("%d ",ps->a[i]);
	}
	printf("\nsize=%d capacity=%d\n",ps->size,ps->capacity);
}

void SeqListExpend(SL* ps)
{
	if(ps->size >= ps->capacity)
	{
	    ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a,sizeof(SLDataType) * ps->capacity);
	}
}

void SeqListPushBack(SL* ps,SLDataType x)
{
	assert(ps);
	SeqListExpend(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SL* ps,SLDataType x)
{
	int i = 0;
	assert(ps);
	SeqListExpend(ps);
	for(i=ps->size-1; i>=0; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	  ps->a[0] = x;
	  ps->size++;
}

void SeqListPopback(SL* ps)
{
	assert(ps);
	ps->size--;
}

void SeqListPopfront(SL* ps)
{
	int i = 0;
	assert(ps);
	for(i=0; i<ps->size-1;i++)
	{
	     ps->a[i] = ps->a[i+1];
	}
	ps->size--;
}

