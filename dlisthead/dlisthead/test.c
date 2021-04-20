#include "dlist.h"

void test()
{
	ListNode* q = ListCreate();
	ListPushFront(q, 0);
	ListPushFront(q, 1);
	ListPushFront(q, 2);
	ListPushFront(q, 3);
	ListPrint(q);
	ListPushBack(q, 1);
	ListPushBack(q, 1);
	ListPrint(q);
	ListPopFront(q);
	ListPopFront(q);
	ListPopFront(q);
	ListPopFront(q);
	ListPopBack(q);
	ListPopBack(q);
	ListPopBack(q);
	ListPrint(q);
}

int main()
{
	test();

	return 0;
}