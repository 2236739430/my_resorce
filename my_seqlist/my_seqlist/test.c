#include "sld.h"

void SldTest()
{
	SL s;
	SeqListinit(&s);
	SeqListPrint(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,3);
	SeqListPushBack(&s,4);
	SeqListPushBack(&s,5);
	SeqListPrint(&s);
	SeqListPushFront(&s,1);
	SeqListPushFront(&s,2);
	SeqListPushFront(&s,3);
	SeqListPushFront(&s,4);
	SeqListPushFront(&s,5);
	SeqListPopfront(&s);
	SeqListPrint(&s);
    SeqListPopback(&s);
	SeqListPrint(&s);
}

int main()
{
    SldTest();

	return 0;
}
