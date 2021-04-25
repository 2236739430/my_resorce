#include "heap.h"

void swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}

void AdjustDown(int* a, int parent, int sz)
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		int rightchild = child + 1;
		if (rightchild < sz && a[child] < a[rightchild])
		{
			child = rightchild;
		}
		if (a[child] > a[parent])
		{
			swap(a + child, a + parent);
		}
		else
		{
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

void AdjustUp(int* hp, int child)
{
	assert(hp);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp[child] > hp[parent])
		{
			swap(&hp[child], &hp[parent]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}

}

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->a,a,sizeof(HPDataType)*n);
	hp->size = hp->capacity = n;
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, i, hp->size);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
	free(hp);
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		HPDataType* tem = (HPDataType*)realloc(hp->a,sizeof(HPDataType)*(hp->capacity)*2);
		if (tem == NULL)
		{
			printf("push error\n");
			exit(-1);
		}
		hp->a = tem;
		hp->capacity *= 2;
	}
	hp->a[hp->size] = x;
	AdjustUp(hp->a,hp->size);
	++hp->size;
}

//删头，把头和尾的数交换向下排序堆结构不会乱
void HeapPop(Heap* hp)
{
	assert(hp);
	if (hp->size == 0)
	{
		printf("no value\n");
		return;
	}
	swap(&(hp->a[0]),&(hp->a[hp->size - 1]));
	AdjustDown(hp->a,0,hp->size);
	hp->size--;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	if (hp->size == 0)
	{
		printf("no value\n");
		return;
	}
	return hp->a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

void HeapPrint(Heap* hp, int sz)
{
	assert(hp);
	int layer = 1;
	for (int i = 0; i < sz; i++)
	{
		if (i == layer)
		{
			printf("\n");
			layer = layer * 2 + 1;
		}
		printf("%2d ",hp->a[i]);
	}
	printf("\n\n");
}

void PrintTopK(int* a, int n, int k)
{
	assert(a);
	//建大堆
	int* cmp = (int*)malloc(sizeof(int)*k);
	memcpy(cmp,a,sizeof(int)*k);
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(cmp,i,k);
	}
	//与堆顶比较
	for (int i = k; i < n; i++)
	{
		if (a[i] < cmp[0])
		{
			cmp[0] = a[i];
			AdjustDown(cmp,0,k);
		}
	}
    //打印
	for (int i = 0; i < k; i++)
	{
		printf("%d\t",cmp[i]);
	}
	printf("\n\n");
}