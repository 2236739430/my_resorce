#include "SList.h"

void test()
{
	SListNode* a = NULL;
	SListPushBack(&a,1);
	SListPushBack(&a, 2);
	SListPushBack(&a, 3);
	SListPushBack(&a, 4);
	SListPushBack(&a, 5);
	SListPrint(a);
	SListPushFront(&a,0);
	SListPrint(a);
	SListPopBack(&a);
	SListPrint(a);
	SListPopFront(&a);
	SListPrint(a);
	SListPrint(SListFind(a,2));
	SListInsertAfter(SListFind(a, 2),2);
	SListPrint(a);
}

int main()
{
	test();

	return 0;
}