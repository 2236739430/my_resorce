#include "stack.h"

void test()
{
	struct Stack a;
	StackInit(&a);
	StackPush(&a, 0);
	StackPush(&a, 1);
	StackPush(&a, 2);
	StackPush(&a, 3);
	StackPush(&a, 4);
	StackPop(&a);
	StackPop(&a);
	StackPop(&a);
	StackPop(&a);
	StackPop(&a);
	StackPop(&a);
	while (StackEmpty(&a) == 0)
	{
		StackTop(&a);
	}
}


int main()
{
	test();


	return 0;
}