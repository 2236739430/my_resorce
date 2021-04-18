#include "qlistnode.h"

void test()
{
	Queue q;//不能用Queue* q，指针未初始化会报错会显示未初始化，除非假设malloc
	QueueInit(&q, 0);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d\n", QueueFront(&q));
		QueuePop(&q);
	}
}

int main()
{
	test();
	

	return 0;
}