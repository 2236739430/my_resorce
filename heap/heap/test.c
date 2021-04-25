#include "heap.h"

void test()
{
	Heap hp;
	int a[] = {1,22,3,4,48,8,6,44,55};
	int size = sizeof(a) / sizeof(a[0]);
	PrintTopK(a,size,3);
	HeapCreate(&hp,a,size);
	HeapPrint(&hp,size);
	HeapPush(&hp,66);
	HeapPush(&hp,0);
	HeapPrint(&hp, (&hp)->size);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp, (&hp)->size);
}

int main()
{
	test();

	return 0;
}