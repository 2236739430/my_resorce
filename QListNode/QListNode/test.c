#include "qlistnode.h"

void test()
{
	Queue q;//������Queue* q��ָ��δ��ʼ���ᱨ�����ʾδ��ʼ�������Ǽ���malloc
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