#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int  size;
	int  capacity;

}SL,SeqList;


void SeqListinit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps,SLDataType x);
void SeqListPushFront(SL* ps,SLDataType x);
void SeqListPopback(SL* ps);
void SeqListPopfront(SL* ps);