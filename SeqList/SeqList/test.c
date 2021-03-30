#include "SeqList.h"

void SeqListtest()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,3);
	SeqListPushBack(&s,4);
	SeqListPushBack(&s,5);
	SeqListPushFront(&s,0);
	SeqListPushFront(&s,0);
	SeqListPushFront(&s,0);
	SeqListPushFront(&s,0);
	SeqListPrint(&s);
	printf("\n");
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	printf("\n");
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	printf("\n");
	printf("searchpos: %d\n", SeqListFind(&s,2));
	SeqListInsert(&s, 1, 0);
	SeqListPrint(&s);
	printf("\n");
	SeqListErase(&s,2);
	SeqListPrint(&s);
	printf("\n");

	SeqListDestory(&s);
}

int main()
{
	SeqListtest();

	return 0;
}