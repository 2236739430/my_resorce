#include "stack.h"

void StackInit(struct Stack* a)
{
	assert(a);
	a->data = (STData*)malloc(sizeof(STData)*4);
	a->top = 0;
	a->capacity = 4;
}

void StackPush(struct Stack* a,STData data)
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
		printf("Îª¿Õ\n");
	}
	printf("%d\n",a->data[a->top - 1]);
	a->top--;
}

void StackPop(struct Stack* a)
{
	assert(a);
	if (a->top == 0)
	{
		printf("Îª¿ÕPopÊ§°Ü\n");
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
	free(a);
	a = NULL;
}
