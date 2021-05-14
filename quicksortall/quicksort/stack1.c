#include "stack1.h"

void StackInit(struct Stack* a)
{
	assert(a);
	a->data = (STData*)malloc(sizeof(STData)* 4);
	a->top = 0;
	a->capacity = 4;
}

void StackPush(struct Stack* a, STData data)
{
	assert(a);
	if (a->top == a->capacity)
	{
		STData* tem = (STData*)realloc(a->data, sizeof(STData)*(a->capacity * 2));
		if (tem == NULL)
		{
			printf("error\n");
			exit(-1);
		}
		a->data = tem;
		a->capacity = a->capacity * 2;
	}
	a->data[a->top] = data;
	a->top++;
}

STData StackTop(struct Stack* a)
{
	assert(a);
	if (a->top == 0)
	{
		printf("为空\n");
	}
	return a->data[a->top - 1];
}

void StackPop(struct Stack* a)
{
	assert(a);
	if (a->top == 0)
	{
		printf("为空Pop失败\n");
		return;
	}
	a->top--;
}

int StackSize(struct Stack* a)
{
	assert(a);
	return a->top;
}

int StackEmpty(struct Stack* a)
{
	assert(a);
	if (a->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void StackDestroy(struct Stack* a)
{
	assert(a);
	free(a->data);//data也需要free，free掉所以动态开辟的空间
}
